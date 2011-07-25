// これは メイン DLL ファイルです。

#include "stdafx.h"

#include "DirectShow.h"
#include <msclr\marshal.h>
#include <msclr\marshal_windows.h>
#include <msclr\marshal_cppstd.h>


using namespace WinBridge::DirectShow;
using namespace msclr::interop;

// public structs
DmoPartialMediaType::DmoPartialMediaType(DMO_PARTIAL_MEDIATYPE& mediaType){
	this->type = *Dmo::GUID2Guid(mediaType.type);
	this->subtype = *Dmo::GUID2Guid(mediaType.subtype);
}

// public classes
Dmo::Dmo(void)
{
}
Dmo::~Dmo(void)
{
}
IEnumDmo^ Dmo::DmoEnum(Guid^ guidCategory, DmoEnumFlags dwFlags, array<DmoPartialMediaType^> ^pInTypes, array<DmoPartialMediaType^> ^pOutTypes){
	
	GUID guid;
	DWORD nIn = 0, nOut = 0;
	DMO_PARTIAL_MEDIATYPE *pIn = NULL, *pOut = NULL;
	IEnumDMO* pEnumDmo;

	try{
		array<Byte> ^bytes = guidCategory->ToByteArray();
		pin_ptr<Byte> pBytes = &bytes[0];
		memcpy(&guid, pBytes, bytes->Length);
	
		if(pInTypes != nullptr){
			nIn = pInTypes->Length;
			pIn = new DMO_PARTIAL_MEDIATYPE[pInTypes->Length];
		}
		if(pOutTypes != nullptr){
			nOut = pOutTypes->Length;
			pOut = new DMO_PARTIAL_MEDIATYPE[pOutTypes->Length];
		}

		HRESULT hr = DMOEnum(guid, static_cast<DWORD>(dwFlags), nIn, pIn, nOut, pOut, &pEnumDmo);
		if(FAILED(hr)){
			throw gcnew DmoException(hr);
		}
		return gcnew EnumDmoClass(pEnumDmo);

	}finally{
		delete[]pIn;
		delete[]pOut;
	}
	
}
void Dmo::DmoGetTypes(Guid^ clsidDmo, array<DmoPartialMediaType^> ^%inputTypes, array<DmoPartialMediaType^> ^%outputTypes){
	const int nDef = 16;
	DMO_PARTIAL_MEDIATYPE inDef[nDef];
	DMO_PARTIAL_MEDIATYPE outDef[nDef];

	unsigned long ulInputTypesRequested = nDef;
	unsigned long pulInputTypesSupplied;
	DMO_PARTIAL_MEDIATYPE *pInputTypes = inDef;
	unsigned long ulOutputTypesRequested = nDef;
    unsigned long pulOutputTypesSupplied;
    DMO_PARTIAL_MEDIATYPE *pOutputTypes = outDef;

	REFCLSID refClsid = Guid2GUID(clsidDmo);

	try{
		do{
			HRESULT hr = DMOGetTypes(
				refClsid,
				ulInputTypesRequested,
				&pulInputTypesSupplied,
				pInputTypes,
				ulOutputTypesRequested,
				&pulOutputTypesSupplied,
				pOutputTypes);

			if(FAILED(hr)){
				throw gcnew DmoException(hr);
			}
			if(ulInputTypesRequested > pulInputTypesSupplied && ulOutputTypesRequested > pulOutputTypesSupplied){
				break;
			}
			if(ulInputTypesRequested > pulInputTypesSupplied){
				ulInputTypesRequested *= 2;
				if(inDef != pInputTypes){
					delete[] pInputTypes;
					pInputTypes = NULL;
				}
				pInputTypes = new DMO_PARTIAL_MEDIATYPE[ulInputTypesRequested];
			}
			if(ulOutputTypesRequested > pulOutputTypesSupplied){
				ulOutputTypesRequested *= 2;
				if(outDef != pOutputTypes){
					delete[] pOutputTypes;
					pOutputTypes = NULL;
				}
				pOutputTypes = new DMO_PARTIAL_MEDIATYPE[ulOutputTypesRequested];
			}

		}while(true);

		inputTypes = gcnew array<DmoPartialMediaType^>(pulInputTypesSupplied);
		for(unsigned int i = 0; i < pulInputTypesSupplied; i++){
			inputTypes[i] = gcnew DmoPartialMediaType(pInputTypes[i]);
		}

		outputTypes = gcnew array<DmoPartialMediaType^>(pulOutputTypesSupplied);
		for(unsigned int i = 0; i < pulOutputTypesSupplied; i++){
			outputTypes[i] = gcnew DmoPartialMediaType(pOutputTypes[i]);
		}
		
	}finally{
		if(inDef != pInputTypes){
			delete[] pInputTypes;
		}
		if(outDef != pOutputTypes){
			delete[] pOutputTypes;
		}
	}
}

DmoException::DmoException(HRESULT hr){
	this->HResult = hr;
}
String^ DmoException::Message::get(){
	LPVOID lpMsgBuf;
	if(0==FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		this->HResult, 
		0, // TODO: MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
		(LPTSTR)&lpMsgBuf, 
		0, 
		NULL)) {
		try{		
			return marshal_as<String^>((LPTSTR)lpMsgBuf);
		}finally{
			LocalFree(lpMsgBuf);
		}
	}
	return "";
}

// Private Classes
EnumDmoClass::EnumDmoClass(IEnumDMO* pEnumDMO){
	this->pEnumDMO = pEnumDMO;
}
EnumDmoClass::~EnumDmoClass(){
	if(this->pEnumDMO != NULL){
		pEnumDMO->Release();
		this->pEnumDMO = NULL;
	}
}
EnumDmoClass::!EnumDmoClass(){
	if(this->pEnumDMO != NULL){
		pEnumDMO->Release();
		this->pEnumDMO = NULL;
	}
}
DWORD EnumDmoClass::Next(DWORD itemsToFetch, array<Guid^>^ clsids, array<String^>^ names){
	CLSID* pCLSID = NULL;
	WCHAR **Names = NULL;
    DWORD pcItemsFetched = 0;

	try{
		pCLSID = new CLSID[clsids->Length];
		Names = new WCHAR*[names->Length];
		HRESULT hr = this->pEnumDMO->Next(itemsToFetch, pCLSID, Names, &pcItemsFetched);
		if(FAILED(hr)){
			throw gcnew DmoException(hr);
		}
		if(itemsToFetch==1 && hr == S_OK){
			pcItemsFetched = 1;
		}
		for(unsigned int i = 0; i < pcItemsFetched; i++){
			clsids[i] = Dmo::GUID2Guid(&pCLSID[i]);
			names[i] = marshal_as<String^>(Names[i]);
		}
		return pcItemsFetched;
	}finally{
		delete[]pCLSID;
		delete[]Names;
	}
}
