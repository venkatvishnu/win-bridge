#pragma once

#include<Dshow.h>
#include<wmcodecdsp.h>
#include<BDATYPES.H>
#include<KS.H>
#include<KSMEDIA.H>
#include<bdamedia.h>
#include"Utils.h"


using namespace System;

namespace WinBridge { namespace DirectShow { 
	public ref class MediaTypes
	{
	public:
		MediaTypes();
		static initonly Guid MediatypeAnalogaudio = *Utils::GUID2Guid(&MEDIATYPE_AnalogAudio);
		static initonly Guid MediatypeAnalogvideo = *Utils::GUID2Guid(&MEDIATYPE_AnalogVideo);
		static initonly Guid MediatypeAudio = *Utils::GUID2Guid(&MEDIATYPE_Audio);
		static initonly Guid MediatypeAuxline21data = *Utils::GUID2Guid(&MEDIATYPE_AUXLine21Data);
		static initonly Guid MediatypeFile = *Utils::GUID2Guid(&MEDIATYPE_File);
		static initonly Guid MediatypeInterleaved = *Utils::GUID2Guid(&MEDIATYPE_Interleaved);
		static initonly Guid MediatypeLmrt = *Utils::GUID2Guid(&MEDIATYPE_LMRT);
		static initonly Guid MediatypeMidi = *Utils::GUID2Guid(&MEDIATYPE_Midi);
		static initonly Guid MediatypeMpeg2Pes = *Utils::GUID2Guid(&MEDIATYPE_MPEG2_PES);
		static initonly Guid MediatypeMpeg2Sections = *Utils::GUID2Guid(&MEDIATYPE_MPEG2_SECTIONS);
		static initonly Guid MediatypeScriptcommand = *Utils::GUID2Guid(&MEDIATYPE_ScriptCommand);
		static initonly Guid MediatypeStream = *Utils::GUID2Guid(&MEDIATYPE_Stream);
		static initonly Guid MediatypeText = *Utils::GUID2Guid(&MEDIATYPE_Text);
		static initonly Guid MediatypeTimecode = *Utils::GUID2Guid(&MEDIATYPE_Timecode);
		static initonly Guid MediatypeUrlStream = *Utils::GUID2Guid(&MEDIATYPE_URL_STREAM);
		static initonly Guid MediatypeVbi = *Utils::GUID2Guid(&MEDIATYPE_VBI);
		static initonly Guid MediatypeVideo = *Utils::GUID2Guid(&MEDIATYPE_Video);
		static initonly Guid MediasubtypeNone = *Utils::GUID2Guid(&MEDIASUBTYPE_None);
		static initonly Guid MediasubtypeIeeeFloat = *Utils::GUID2Guid(&MEDIASUBTYPE_IEEE_FLOAT);
		static initonly Guid MediasubtypePcm = *Utils::GUID2Guid(&MEDIASUBTYPE_PCM);
		//static initonly Guid MediasubtypeMpegAdtsAac = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG_ADTS_AAC);
		static initonly Guid MediasubtypeMpegAdtsAac = *gcnew Guid(0x00001600, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		//static initonly Guid MediasubtypeMpegHeaac = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG_HEAAC);
		static initonly Guid MediasubtypeMpegHeaac = *gcnew Guid(0x00001610, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		//static initonly Guid MediasubtypeMpegLoas = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG_LOAS);
		static initonly Guid MediasubtypeMpegLoas = *gcnew Guid(0x00001602, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		//static initonly Guid MediasubtypeRawAac1 = *Utils::GUID2Guid(&MEDIASUBTYPE_RAW_AAC1);
		static initonly Guid MediasubtypeRawAac1 = *gcnew Guid(0x000000FF, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		//static initonly Guid MediasubtypeDolbyDdplus = *Utils::GUID2Guid(&MEDIASUBTYPE_DOLBY_DDPLUS);
		static initonly Guid MediasubtypeDolbyDdplus = *gcnew Guid(0xa7fb87af, 0x2d02, 0x42fb, 0xa4, 0xd4, 0x5, 0xcd, 0x93, 0x84, 0x3b, 0xdd);
		static initonly Guid MediasubtypeDolbyAc3 = *Utils::GUID2Guid(&MEDIASUBTYPE_DOLBY_AC3);
		static initonly Guid MediasubtypeDolbyAc3Spdif = *Utils::GUID2Guid(&MEDIASUBTYPE_DOLBY_AC3_SPDIF);
		//static initonly Guid MediasubtypeDvm = *Utils::GUID2Guid(&MEDIASUBTYPE_DVM);
		static initonly Guid MediasubtypeDvm = *gcnew Guid(0x00002000, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		static initonly Guid MediasubtypeRawSport = *Utils::GUID2Guid(&MEDIASUBTYPE_RAW_SPORT);
		static initonly Guid MediasubtypeSpdifTag241h = *Utils::GUID2Guid(&MEDIASUBTYPE_SPDIF_TAG_241h);
		static initonly Guid MediasubtypeDrmAudio = *Utils::GUID2Guid(&MEDIASUBTYPE_DRM_Audio);
		static initonly Guid MediasubtypeDts = *Utils::GUID2Guid(&MEDIASUBTYPE_DTS);
		//static initonly Guid MediasubtypeDts2 = *Utils::GUID2Guid(&MEDIASUBTYPE_DTS2);
		static initonly Guid MediasubtypeDts2 = *gcnew Guid(0x00002001, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		static initonly Guid MediasubtypeDvdLpcmAudio = *Utils::GUID2Guid(&MEDIASUBTYPE_DVD_LPCM_AUDIO);
		static initonly Guid MediasubtypeMpeg1audiopayload = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG1AudioPayload);
		static initonly Guid MediasubtypeMpeg1packet = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG1Packet);
		static initonly Guid MediasubtypeMpeg1payload = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG1Payload);
		static initonly Guid MediasubtypeMpeg2Audio = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG2_AUDIO);
		static initonly Guid KsdataformatTypeBdaAntenna = *Utils::GUID2Guid(&KSDATAFORMAT_TYPE_BDA_ANTENNA);
		static initonly Guid KsdataformatTypeBdaIfSignal = *Utils::GUID2Guid(&KSDATAFORMAT_TYPE_BDA_IF_SIGNAL);
		static initonly Guid MediatypeDvdEncryptedPack = *Utils::GUID2Guid(&MEDIATYPE_DVD_ENCRYPTED_PACK);
		static initonly Guid MediasubtypeDvdSubpicture = *Utils::GUID2Guid(&MEDIASUBTYPE_DVD_SUBPICTURE);
		static initonly Guid MediasubtypeMpeg2Video = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG2_VIDEO);
		static initonly Guid MediasubtypeSdds = *Utils::GUID2Guid(&MEDIASUBTYPE_SDDS);
		static initonly Guid MediasubtypeLine21Bytepair = *Utils::GUID2Guid(&MEDIASUBTYPE_Line21_BytePair);
		static initonly Guid MediasubtypeLine21Goppacket = *Utils::GUID2Guid(&MEDIASUBTYPE_Line21_GOPPacket);
		static initonly Guid MediasubtypeLine21Vbirawdata = *Utils::GUID2Guid(&MEDIASUBTYPE_Line21_VBIRawData);
		static initonly Guid MediasubtypeMpeg1system = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG1System);
		static initonly Guid MediasubtypeMpeg1videocd = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG1VideoCD);
		static initonly Guid MediasubtypeMpeg1video = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG1Video);
		static initonly Guid MediasubtypeMpeg1audio = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG1Audio);
		static initonly Guid MediasubtypeAiff = *Utils::GUID2Guid(&MEDIASUBTYPE_AIFF);
		static initonly Guid MediasubtypeAsf = *Utils::GUID2Guid(&MEDIASUBTYPE_Asf);
		static initonly Guid MediasubtypeAvi = *Utils::GUID2Guid(&MEDIASUBTYPE_Avi);
		static initonly Guid MediasubtypeAu = *Utils::GUID2Guid(&MEDIASUBTYPE_AU);
		static initonly Guid MediasubtypeDssaudio = *Utils::GUID2Guid(&MEDIASUBTYPE_DssAudio);
		static initonly Guid MediasubtypeDssvideo = *Utils::GUID2Guid(&MEDIASUBTYPE_DssVideo);
		//static initonly Guid MediasubtypeMpeg1systemstream = *Utils::GUID2Guid(&MEDIASUBTYPE_MPEG1SystemStream);
		static initonly Guid MediasubtypeWave = *Utils::GUID2Guid(&MEDIASUBTYPE_WAVE);
		static initonly Guid KsdataformatSubtypeRaw8 = *Utils::GUID2Guid(&KSDATAFORMAT_SUBTYPE_RAW8);
		static initonly Guid MediasubtypeTeletext = *Utils::GUID2Guid(&MEDIASUBTYPE_TELETEXT);
		static initonly Guid MediasubtypeVps = *Utils::GUID2Guid(&MEDIASUBTYPE_VPS);
		static initonly Guid MediasubtypeWss = *Utils::GUID2Guid(&MEDIASUBTYPE_WSS);
		static initonly Guid MediasubtypeAnalogvideoNtscM = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_NTSC_M);
		static initonly Guid MediasubtypeAnalogvideoPalB = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_PAL_B);
		static initonly Guid MediasubtypeAnalogvideoPalD = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_PAL_D);
		static initonly Guid MediasubtypeAnalogvideoPalG = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_PAL_G);
		static initonly Guid MediasubtypeAnalogvideoPalH = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_PAL_H);
		static initonly Guid MediasubtypeAnalogvideoPalI = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_PAL_I);
		static initonly Guid MediasubtypeAnalogvideoPalM = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_PAL_M);
		static initonly Guid MediasubtypeAnalogvideoPalN = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_PAL_N);
		static initonly Guid MediasubtypeAnalogvideoSecamB = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_SECAM_B);
		static initonly Guid MediasubtypeAnalogvideoSecamD = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_SECAM_D);
		static initonly Guid MediasubtypeAnalogvideoSecamG = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_SECAM_G);
		static initonly Guid MediasubtypeAnalogvideoSecamH = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_SECAM_H);
		static initonly Guid MediasubtypeAnalogvideoSecamK = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_SECAM_K);
		static initonly Guid MediasubtypeAnalogvideoSecamK1 = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_SECAM_K1);
		static initonly Guid MediasubtypeAnalogvideoSecamL = *Utils::GUID2Guid(&MEDIASUBTYPE_AnalogVideo_SECAM_L);
		static initonly Guid MediasubtypeAi44 = *Utils::GUID2Guid(&MEDIASUBTYPE_AI44);
		static initonly Guid MediasubtypeIa44 = *Utils::GUID2Guid(&MEDIASUBTYPE_IA44);
		static initonly Guid MediasubtypeDvsl = *Utils::GUID2Guid(&MEDIASUBTYPE_dvsl);
		static initonly Guid MediasubtypeDvsd = *Utils::GUID2Guid(&MEDIASUBTYPE_dvsd);
		static initonly Guid MediasubtypeDvhd = *Utils::GUID2Guid(&MEDIASUBTYPE_dvhd);
		static initonly Guid MediasubtypeDv25 = *Utils::GUID2Guid(&MEDIASUBTYPE_dv25);
		static initonly Guid MediasubtypeDv50 = *Utils::GUID2Guid(&MEDIASUBTYPE_dv50);
		static initonly Guid MediasubtypeDvh1 = *Utils::GUID2Guid(&MEDIASUBTYPE_dvh1);
		static initonly Guid MediasubtypeDvcs = *Utils::GUID2Guid(&MEDIASUBTYPE_DVCS);
		//static initonly Guid MediasubtypeAvc1 = *Utils::GUID2Guid(&MEDIASUBTYPE_AVC1);
		static initonly Guid MediasubtypeAvc1 = *gcnew Guid(0x31435641, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		static initonly Guid MediasubtypeH264 = *Utils::GUID2Guid(&MEDIASUBTYPE_H264);
		//static initonly Guid MediasubtypeX264 = *Utils::GUID2Guid(&MEDIASUBTYPE_X264);
		static initonly Guid MediasubtypeX264 = *gcnew Guid(0x34363258, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		static initonly Guid MediasubtypeRgb1 = *Utils::GUID2Guid(&MEDIASUBTYPE_RGB1);
		static initonly Guid MediasubtypeRgb4 = *Utils::GUID2Guid(&MEDIASUBTYPE_RGB4);
		static initonly Guid MediasubtypeRgb8 = *Utils::GUID2Guid(&MEDIASUBTYPE_RGB8);
		static initonly Guid MediasubtypeRgb555 = *Utils::GUID2Guid(&MEDIASUBTYPE_RGB555);
		static initonly Guid MediasubtypeRgb565 = *Utils::GUID2Guid(&MEDIASUBTYPE_RGB565);
		static initonly Guid MediasubtypeRgb24 = *Utils::GUID2Guid(&MEDIASUBTYPE_RGB24);
		static initonly Guid MediasubtypeRgb32 = *Utils::GUID2Guid(&MEDIASUBTYPE_RGB32);
		static initonly Guid MediasubtypeArgb1555 = *Utils::GUID2Guid(&MEDIASUBTYPE_ARGB1555);
		static initonly Guid MediasubtypeArgb32 = *Utils::GUID2Guid(&MEDIASUBTYPE_ARGB32);
		static initonly Guid MediasubtypeArgb4444 = *Utils::GUID2Guid(&MEDIASUBTYPE_ARGB4444);
		static initonly Guid MediasubtypeA2r10g10b10 = *Utils::GUID2Guid(&MEDIASUBTYPE_A2R10G10B10);
		static initonly Guid MediasubtypeA2b10g10r10 = *Utils::GUID2Guid(&MEDIASUBTYPE_A2B10G10R10);
		static initonly Guid MediasubtypeAyuv = *Utils::GUID2Guid(&MEDIASUBTYPE_AYUV);
		static initonly Guid MediasubtypeYuy2 = *Utils::GUID2Guid(&MEDIASUBTYPE_YUY2);
		static initonly Guid MediasubtypeUyvy = *Utils::GUID2Guid(&MEDIASUBTYPE_UYVY);
		static initonly Guid MediasubtypeImc1 = *Utils::GUID2Guid(&MEDIASUBTYPE_IMC1);
		static initonly Guid MediasubtypeImc3 = *Utils::GUID2Guid(&MEDIASUBTYPE_IMC3);
		static initonly Guid MediasubtypeImc2 = *Utils::GUID2Guid(&MEDIASUBTYPE_IMC2);
		static initonly Guid MediasubtypeImc4 = *Utils::GUID2Guid(&MEDIASUBTYPE_IMC4);
		static initonly Guid MediasubtypeYv12 = *Utils::GUID2Guid(&MEDIASUBTYPE_YV12);
		static initonly Guid MediasubtypeNv12 = *Utils::GUID2Guid(&MEDIASUBTYPE_NV12);
		//static initonly Guid MediasubtypeI420 = *Utils::GUID2Guid(&MEDIASUBTYPE_I420);
		static initonly Guid MediasubtypeI420 = *gcnew Guid(0x30323449, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		static initonly Guid MediasubtypeIf09 = *Utils::GUID2Guid(&MEDIASUBTYPE_IF09);
		static initonly Guid MediasubtypeIyuv = *Utils::GUID2Guid(&MEDIASUBTYPE_IYUV);
		static initonly Guid MediasubtypeY211 = *Utils::GUID2Guid(&MEDIASUBTYPE_Y211);
		static initonly Guid MediasubtypeY411 = *Utils::GUID2Guid(&MEDIASUBTYPE_Y411);
		static initonly Guid MediasubtypeY41p = *Utils::GUID2Guid(&MEDIASUBTYPE_Y41P);
		static initonly Guid MediasubtypeYvu9 = *Utils::GUID2Guid(&MEDIASUBTYPE_YVU9);
		static initonly Guid MediasubtypeYvyu = *Utils::GUID2Guid(&MEDIASUBTYPE_YVYU);
		static initonly Guid MediasubtypeMss1 = *gcnew Guid(0x3153534D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		static initonly Guid MediasubtypeMss2 = *gcnew Guid(0x3253534D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		//DEFINE_GUID(MEDIASUBTYPE_MSS1, 0x3153534D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
		//DEFINE_GUID(MEDIASUBTYPE_MSS2, 0x3253534D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
 	};
}}
