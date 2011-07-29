#include "StdAfx.h"
#include "Utils.h"

using namespace WinBridge::DirectShow;
using namespace System;

Utils::Utils(void)
{
}

Guid^ WinBridge::DirectShow::Utils::GUID2Guid(const GUID* pGuid){
	return gcnew Guid(
		pGuid->Data1, pGuid->Data2, pGuid->Data3, 
		pGuid->Data4[0], pGuid->Data4[1], pGuid->Data4[2], pGuid->Data4[3], 
		pGuid->Data4[4], pGuid->Data4[5], pGuid->Data4[6], pGuid->Data4[7]);
}
Guid^ Utils::GUID2Guid(GUID& guid){
	return gcnew Guid(
		guid.Data1, guid.Data2, guid.Data3, 
		guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], 
		guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
}
GUID Utils::Guid2GUID(Guid^ guid){
	GUID result;
	array<Byte> ^bytes = guid->ToByteArray();
	pin_ptr<Byte> pBytes = &bytes[0];
	memcpy(&result, pBytes, bytes->Length);
	return result;
}
