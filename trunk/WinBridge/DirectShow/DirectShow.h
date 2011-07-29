// DirectShow.h

#pragma once

#include <Dmo.h>
#include <Dmoreg.h>
#include "Utils.h"

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
		Guid type;
		Guid subtype;
	internal:
		void init(DMO_PARTIAL_MEDIATYPE& mediaType);

	public:
		DmoPartialMediaType(Guid^ type, Guid^ subtype){
			this->type = *type;
			this->subtype = *subtype;
		}
		property Guid Type
		{
			Guid get(void) 
			{ 
				return type; 
			}
			void set(Guid value) 
			{ 
				type = value; 
			}
		}
		property Guid SubType
		{
			Guid get(void) 
			{ 
				return subtype; 
			}
			void set(Guid value) 
			{ 
				subtype = value;
			}
		}

	};

	// Public Interfaces
	public interface class IEnumDmo
	{
	public:
		int Next(int cItemsToFetch, [System::Runtime::InteropServices::Out] array<Guid>^ %pCLSID, [System::Runtime::InteropServices::Out] array<String^>^ %Names);
	};

	// Public Classes
	public ref class Dmo
	{
		public:
			static initonly Guid DmocategoryAll = *Utils::GUID2Guid(&GUID_NULL);
			static initonly Guid DmocategoryAudioDecoder = *Utils::GUID2Guid(&DMOCATEGORY_AUDIO_DECODER);
			static initonly Guid DmocategoryAudioEffect = *Utils::GUID2Guid(&DMOCATEGORY_AUDIO_EFFECT);
			static initonly Guid DmocategoryAudioEncoder = *Utils::GUID2Guid(&DMOCATEGORY_AUDIO_ENCODER);
			static initonly Guid DmocategoryVideoDecoder = *Utils::GUID2Guid(&DMOCATEGORY_VIDEO_DECODER);
			static initonly Guid DmocategoryVideoEffect = *Utils::GUID2Guid(&DMOCATEGORY_VIDEO_EFFECT);
			static initonly Guid DmocategoryVideoEncoder = *Utils::GUID2Guid(&DMOCATEGORY_VIDEO_ENCODER);
			static initonly Guid DmocategoryAudioCaptureEffect = *Utils::GUID2Guid(&DMOCATEGORY_AUDIO_CAPTURE_EFFECT);

			Dmo(void);
			~Dmo(void);
		
			IEnumDmo^ DmoEnum(
				Guid^ guidCategory, 
				DmoEnumFlags dwFlags, 
				array<DmoPartialMediaType^> ^pInTypes,
				array<DmoPartialMediaType^> ^pOutTypes);

			void DmoGetTypes(
				Guid clsidDmo,
				[Runtime::InteropServices::Out] array<DmoPartialMediaType>^ %inputTypes,
				[Runtime::InteropServices::Out] array<DmoPartialMediaType>^ %outputTypes);

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
			virtual int Next(int cItemsToFetch, [Runtime::InteropServices::Out] array<Guid>^ %pCLSID, [Runtime::InteropServices::Out] array<String^>^ %Names);
	};
}}
