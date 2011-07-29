// TestDirectShow.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"

using namespace System;
using namespace WinBridge::DirectShow;

void testEnumDom();

int main(array<System::String ^> ^args)
{
	testEnumDom();

    return 0;
}

// Testing DmoEnum and DmoGetTypes
void testEnumDom(){
	Dmo dmo;
	IEnumDmo^ iEnumDmo = dmo.DmoEnum( Dmo::DmocategoryAll, DmoEnumFlags::None, nullptr, nullptr);
	try{
		unsigned int n = 1;
		array<Guid>^ guids;
		array<String^>^ names;

		while(0 < iEnumDmo->Next(n, guids, names)){
			Console::WriteLine ("{" + guids[0].ToString() + "}:" + names[0]);

			array<DmoPartialMediaType> ^inputTypes;
			array<DmoPartialMediaType> ^outputTypes;
			dmo.DmoGetTypes(guids[0], inputTypes, outputTypes);

			Console::WriteLine ("\tInputType");
			for(int i = 0; i < inputTypes->Length; i++ ){
				Console::WriteLine (
					"\t{" + inputTypes[i].Type.ToString() + 
					"}-{" + inputTypes[i].SubType.ToString() + "}" );
				
			}
			Console::WriteLine ("\tOutputType");
			for(int i = 0; i < outputTypes->Length; i++ ){
				Console::WriteLine (
					"\t{" + outputTypes[i].Type.ToString() + 
					"}-{" + outputTypes[i].SubType.ToString() + "}" );
				
			}
		}

	}finally{
		delete[]iEnumDmo;
	}
}
