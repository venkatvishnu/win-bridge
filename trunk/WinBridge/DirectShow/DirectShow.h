// DirectShow.h

#pragma once

#include <Dmo.h>
#include <Dmoreg.h>

using namespace System;

namespace WinBridge { namespace DirectShow { 

	// Public Enumrations
	public enum class DmoEnumFlags{
		None = 0x00000000,
		DmoEnumfIncludeKeyed = 0x00000001
	};

	// Public Structs
	public value class DmoPartialMediaType
	{
	private:
		System::Guid type;
		System::Guid subtype;
	internal:
		DmoPartialMediaType(DMO_PARTIAL_MEDIATYPE& mediaType);

	public:
		DmoPartialMediaType(Guid^ type, Guid^ subtype){
			this->type = *type;
			this->subtype = *subtype;
		}
		property System::Guid Type
		{
			System::Guid get(void) 
			{ 
				return type; 
			}
			void set(System::Guid value) 
			{ 
				type = value; 
			}
		}
		property System::Guid SubType
		{
			System::Guid get(void) 
			{ 
				return subtype; 
			}
			void set(System::Guid value) 
			{ 
				subtype = value;
			}
		}

	};

	// Public Interfaces
	public interface class IEnumDmo
	{
	public:
		DWORD Next(DWORD cItemsToFetch, array<Guid^>^ guids, array<String^>^ names);
	};

	// Public Classes
	public ref class Dmo
	{
		internal:
			static Guid^ GUID2Guid(const GUID* pGuid){
				return gcnew Guid(
					pGuid->Data1, pGuid->Data2, pGuid->Data3, 
					pGuid->Data4[0], pGuid->Data4[1], pGuid->Data4[2], pGuid->Data4[3], 
					pGuid->Data4[4], pGuid->Data4[5], pGuid->Data4[6], pGuid->Data4[7]);
			}
			static Guid^ GUID2Guid(GUID guid){
				return gcnew Guid(
					guid.Data1, guid.Data2, guid.Data3, 
					guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], 
					guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
			}
			static GUID Guid2GUID(Guid^ guid){
				GUID result;
				array<Byte> ^bytes = guid->ToByteArray();
				pin_ptr<Byte> pBytes = &bytes[0];
				memcpy(&result, pBytes, bytes->Length);
				return result;
			}

		public:
			static initonly Guid DmocategoryAll = *GUID2Guid(&GUID_NULL);
			static initonly Guid DmocategoryAudioDecoder = *GUID2Guid(&DMOCATEGORY_AUDIO_DECODER);
			static initonly Guid DmocategoryAudioEffect = *GUID2Guid(&DMOCATEGORY_AUDIO_EFFECT);
			static initonly Guid DmocategoryAudioEncoder = *GUID2Guid(&DMOCATEGORY_AUDIO_ENCODER);
			static initonly Guid DmocategoryVideoDecoder = *GUID2Guid(&DMOCATEGORY_VIDEO_DECODER);
			static initonly Guid DmocategoryVideoEffect = *GUID2Guid(&DMOCATEGORY_VIDEO_EFFECT);
			static initonly Guid DmocategoryVideoEncoder = *GUID2Guid(&DMOCATEGORY_VIDEO_ENCODER);
			static initonly Guid DmocategoryAudioCaptureEffect = *GUID2Guid(&DMOCATEGORY_AUDIO_CAPTURE_EFFECT);

			Dmo(void);
			~Dmo(void);
		
			IEnumDmo^ DmoEnum(
				System::Guid^ guidCategory, 
				DmoEnumFlags dwFlags, 
				array<DmoPartialMediaType^> ^pInTypes,
				array<DmoPartialMediaType^> ^pOutTypes);

			void DmoGetTypes(
				System::Guid^ clsidDmo,
				array<DmoPartialMediaType^> ^%inputTypes,
				array<DmoPartialMediaType^> ^%outputTypes);

	};

	public ref class DmoException : Exception{
		public:
			DmoException(HRESULT hr);
			property String^ Message{
				virtual String^  get() override;
			}
	};

	// Private Classes
	ref class EnumDmoClass : IEnumDmo{
		private:
			IEnumDMO* pEnumDMO;
		public:
			EnumDmoClass(IEnumDMO* pEnumDMO);
			~EnumDmoClass();
			!EnumDmoClass();
			virtual DWORD Next(DWORD cItemsToFetch, array<Guid^>^ pCLSID, array<String^>^ Names);
	};
	
}}
