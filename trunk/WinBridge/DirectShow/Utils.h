#pragma once

#include "WTypes.h"

namespace WinBridge { namespace DirectShow { 
	ref class Utils
	{
	internal:
		Utils();
		static System::Guid^ GUID2Guid(const GUID* pGuid);
		static System::Guid^ GUID2Guid(GUID& guid);
		static GUID Guid2GUID(System::Guid^ guid);
	};
}}

