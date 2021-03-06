/*
  Copyright (c) 2008-2016 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#include "fmod_errors.h"
#include "blitz.h"

class MAX_FMOD_CHANNEL;

extern "C" {

	unsigned int bmx_fmod_getversion();
	const char * bmx_FMOD_ErrorString(FMOD_RESULT errcode);


	FMOD_SYSTEM  * bmx_FMOD_System_Create(FMOD_RESULT * result);
	FMOD_SOUND * bmx_FMOD_System_CreateSound(FMOD_SYSTEM *system, const char * filename, FMOD_MODE mode,
		FMOD_CREATESOUNDEXINFO * exInfo, FMOD_RESULT * ret);
	MAX_FMOD_CHANNEL * bmx_FMOD_System_PlaySound(FMOD_SYSTEM *system, FMOD_CHANNELINDEX channelId, FMOD_SOUND * sound,
		FMOD_BOOL paused, MAX_FMOD_CHANNEL * reuse);
	MAX_FMOD_CHANNEL * bmx_FMOD_System_GetChannel(FMOD_SYSTEM *system, int channelId);
	FMOD_DSP * bmx_FMOD_System_CreateDSPByType(FMOD_SYSTEM *system, FMOD_DSP_TYPE dspType, FMOD_RESULT * ret);
	MAX_FMOD_CHANNEL * bmx_FMOD_System_PlayDSP(FMOD_SYSTEM *system, FMOD_CHANNELINDEX channelId, FMOD_DSP * dsp,
		FMOD_BOOL paused, MAX_FMOD_CHANNEL * reuse);
	FMOD_SOUND * bmx_FMOD_System_CreateStream(FMOD_SYSTEM *system, const char * filename, FMOD_MODE mode,
		FMOD_CREATESOUNDEXINFO * exInfo, FMOD_RESULT * ret);
	FMOD_REVERB * bmx_FMOD_System_CreateReverb(FMOD_SYSTEM *system);
	FMOD_RESULT bmx_FMOD_System_GetSpectrum(FMOD_SYSTEM *system, BBArray * spectrumArray, int channelOffset, FMOD_DSP_FFT_WINDOW windowType);
	FMOD_CHANNELGROUP * bmx_FMOD_System_CreateChannelGroup(FMOD_SYSTEM *system, const char * name);
	FMOD_CHANNELGROUP * bmx_FMOD_System_GetMasterChannelGroup(FMOD_SYSTEM *system);


	void bmx_fmodchannel_delete(MAX_FMOD_CHANNEL * channel);
	FMOD_RESULT bmx_FMOD_Channel_GetSpectrum(MAX_FMOD_CHANNEL *channel, BBArray * spectrumArray, int channelOffset, FMOD_DSP_FFT_WINDOW windowType);
	FMOD_SOUND * bmx_FMOD_Channel_GetCurrentSound(MAX_FMOD_CHANNEL *channel);
	FMOD_RESULT bmx_FMOD_Channel_GetPaused(MAX_FMOD_CHANNEL *channel, FMOD_BOOL * paused);
	FMOD_RESULT bmx_FMOD_Channel_SetPaused(MAX_FMOD_CHANNEL *channel, FMOD_BOOL paused);
	FMOD_RESULT bmx_FMOD_Channel_Stop(MAX_FMOD_CHANNEL *channel);
	FMOD_RESULT bmx_FMOD_Channel_GetVolume(MAX_FMOD_CHANNEL *channel, float * volume);
	FMOD_RESULT bmx_FMOD_Channel_SetVolume(MAX_FMOD_CHANNEL *channel, float volume);
	FMOD_RESULT bmx_FMOD_Channel_GetPan(MAX_FMOD_CHANNEL *channel, float * pan);
	FMOD_RESULT bmx_FMOD_Channel_SetPan(MAX_FMOD_CHANNEL *channel, float pan);
	FMOD_RESULT bmx_FMOD_Channel_GetDelay(MAX_FMOD_CHANNEL *channel, FMOD_DELAYTYPE delaytype, unsigned int *delayhi, unsigned int *delaylo);

	FMOD_RESULT bmx_FMOD_Channel_IsPlaying(MAX_FMOD_CHANNEL *channel, FMOD_BOOL *isplaying);
	FMOD_RESULT bmx_FMOD_Channel_IsVirtual(MAX_FMOD_CHANNEL *channel, FMOD_BOOL *isvirtual);
	FMOD_RESULT bmx_FMOD_Channel_GetAudibility(MAX_FMOD_CHANNEL *channel, float *audibility);
	FMOD_RESULT bmx_FMOD_Channel_GetIndex(MAX_FMOD_CHANNEL *channel, int *index);
	FMOD_RESULT bmx_FMOD_Channel_SetFrequency(MAX_FMOD_CHANNEL *channel, float frequency);
	FMOD_RESULT bmx_FMOD_Channel_GetFrequency(MAX_FMOD_CHANNEL *channel, float *frequency);
	FMOD_RESULT bmx_FMOD_Channel_GetPosition(MAX_FMOD_CHANNEL *channel, unsigned int *position, FMOD_TIMEUNIT postype);
	FMOD_RESULT bmx_FMOD_Channel_SetLoopCount(MAX_FMOD_CHANNEL *channel, int loopcount);
	FMOD_RESULT bmx_FMOD_Channel_GetLoopCount(MAX_FMOD_CHANNEL *channel, int *loopcount);
	FMOD_RESULT bmx_FMOD_Channel_SetLoopPoints(MAX_FMOD_CHANNEL *channel, unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype);
	FMOD_RESULT bmx_FMOD_Channel_GetLoopPoints(MAX_FMOD_CHANNEL *channel, unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype);
	FMOD_RESULT bmx_FMOD_Channel_Get3DAttributes(MAX_FMOD_CHANNEL *channel, FMOD_VECTOR *pos, FMOD_VECTOR *vel);
	FMOD_RESULT bmx_FMOD_Channel_Get3DMinMaxDistance(MAX_FMOD_CHANNEL *channel, float *mindistance, float *maxdistance);
	FMOD_RESULT bmx_FMOD_Channel_Get3DConeOrientation(MAX_FMOD_CHANNEL *channel, FMOD_VECTOR *orientation);
	FMOD_RESULT bmx_FMOD_Channel_Get3DOcclusion(MAX_FMOD_CHANNEL *channel, float *directocclusion, float *reverbocclusion);
	FMOD_RESULT bmx_FMOD_Channel_Get3DDopplerLevel(MAX_FMOD_CHANNEL *channel, float *level);
	FMOD_RESULT bmx_FMOD_Channel_Get3DSpread(MAX_FMOD_CHANNEL *channel, float *angle);
	FMOD_RESULT bmx_FMOD_Channel_Get3DPanLevel(MAX_FMOD_CHANNEL *channel, float *level);
	FMOD_RESULT bmx_FMOD_Channel_SetChannelGroup(MAX_FMOD_CHANNEL *channel, FMOD_CHANNELGROUP * group);
	FMOD_RESULT bmx_FMOD_Channel_Get3DConeSettings(MAX_FMOD_CHANNEL *channel, float * insideConeAngle, float * outsideConeAngle, float * outsideVolume);
	FMOD_CHANNELGROUP * bmx_FMOD_Channel_GetChannelGroup(MAX_FMOD_CHANNEL *channel);
	FMOD_RESULT bmx_FMOD_Channel_GetMode(MAX_FMOD_CHANNEL *channel, FMOD_MODE * mode);
	FMOD_RESULT bmx_FMOD_Channel_GetMute(MAX_FMOD_CHANNEL *channel, FMOD_BOOL * mute);
	FMOD_RESULT bmx_FMOD_Channel_GetPriority(MAX_FMOD_CHANNEL *channel, int * priority);
	FMOD_RESULT bmx_FMOD_Channel_GetReverbProperties(MAX_FMOD_CHANNEL *channel, FMOD_REVERB_CHANNELPROPERTIES * properties);
	FMOD_RESULT bmx_FMOD_Channel_SetReverbProperties(MAX_FMOD_CHANNEL *channel, FMOD_REVERB_CHANNELPROPERTIES * properties);
	FMOD_RESULT bmx_FMOD_Channel_SetPriority(MAX_FMOD_CHANNEL *channel, int priority);
	FMOD_RESULT bmx_FMOD_Channel_GetLowPassGain(MAX_FMOD_CHANNEL *channel, float * gain);
	FMOD_RESULT bmx_FMOD_Channel_GetSpeakerLevels(MAX_FMOD_CHANNEL *channel, FMOD_SPEAKER speaker, BBArray * levels);
	FMOD_RESULT bmx_FMOD_Channel_GetSpeakerMix(MAX_FMOD_CHANNEL *channel, float * frontleft, float * frontright, float * center,
		float * lfe, float * backleft, float * backright, float * sideleft, float * sideright);
	FMOD_RESULT bmx_FMOD_Channel_GetWaveData(MAX_FMOD_CHANNEL *channel, BBArray * waveArray, int channelOffset);
	FMOD_RESULT bmx_FMOD_Channel_SetDelay(MAX_FMOD_CHANNEL *channel, FMOD_DELAYTYPE delayType, unsigned int delayHi, unsigned int delayLo);
	FMOD_RESULT bmx_FMOD_Channel_SetInputChannelMix(MAX_FMOD_CHANNEL *channel, BBArray * levels);
	FMOD_RESULT bmx_FMOD_Channel_SetLowPassGain(MAX_FMOD_CHANNEL *channel, float gain);
	FMOD_RESULT bmx_FMOD_Channel_SetMode(MAX_FMOD_CHANNEL *channel, FMOD_MODE mode);
	FMOD_RESULT bmx_FMOD_Channel_SetMute(MAX_FMOD_CHANNEL *channel, bool mute);
	FMOD_RESULT bmx_FMOD_Channel_SetPosition(MAX_FMOD_CHANNEL *channel, unsigned int position, FMOD_TIMEUNIT postype);

	FMOD_CREATESOUNDEXINFO * bmx_soundexinfo_create();
	void bmx_soundexinfo_setlength(FMOD_CREATESOUNDEXINFO * info, int length);	
	void bmx_soundexinfo_delete(FMOD_CREATESOUNDEXINFO * info);
	void bmx_soundexinfo_setnumchannels(FMOD_CREATESOUNDEXINFO * info, int numChannels);
	void bmx_soundexinfo_setdefaultfrequency(FMOD_CREATESOUNDEXINFO * info, int frequency);
	void bmx_soundexinfo_setformat(FMOD_CREATESOUNDEXINFO * info, FMOD_SOUND_FORMAT format);
	void bmx_soundexinfo_setdecodebuffersize(FMOD_CREATESOUNDEXINFO * info, unsigned int bufferSize);
	void bmx_soundexinfo_setinitialsubsound(FMOD_CREATESOUNDEXINFO * info, int initial);
	void bmx_soundexinfo_setnumsubsounds(FMOD_CREATESOUNDEXINFO * info, int num);
	void bmx_soundexinfo_setpcmreadcallback(FMOD_CREATESOUNDEXINFO * info, FMOD_SOUND_PCMREADCALLBACK cb);
	void bmx_soundexinfo_setpcmsetposcallback(FMOD_CREATESOUNDEXINFO * info, FMOD_SOUND_PCMSETPOSCALLBACK cb);
	BBObject * bmx_soundexinfo_getuserdata(FMOD_CREATESOUNDEXINFO * info);
	void bmx_soundexinfo_setuserdata(FMOD_CREATESOUNDEXINFO * info, BBObject * obj);


	FMOD_SOUND * bmx_FMOD_SoundGroup_GetSound(FMOD_SOUNDGROUP *soundgroup, int index);

	FMOD_TAG * bmx_FMOD_Sound_GetTag(FMOD_SOUND * sound, const char * name, int index);
	FMOD_RESULT bmx_FMOD_Sound_SetSubSoundSentence(FMOD_SOUND * sound, BBArray * soundList);
	FMOD_SOUND * bmx_FMOD_Sound_GetSubSound(FMOD_SOUND * sound, int index);
	BBObject * bmx_FMOD_Sound_GetUserData(FMOD_SOUND * sound);
	void bmx_FMOD_Sound_SetUserData(FMOD_SOUND * sound, BBObject * obj);


	void * bmx_fmodtag_getdata(FMOD_TAG * tag);
	void bmx_fmodtag_delete(FMOD_TAG * tag);
	FMOD_TAGTYPE bmx_fmodtag_gettagtype(FMOD_TAG * tag);
	FMOD_TAGDATATYPE bmx_fmodtag_getdatatype(FMOD_TAG * tag);
	char * bmx_fmodtag_getname(FMOD_TAG * tag);
	unsigned int bmx_fmodtag_getdatalength(FMOD_TAG * tag);
	FMOD_BOOL bmx_fmodtag_getupdated(FMOD_TAG * tag);
	
	MAX_FMOD_CHANNEL * bmx_FMOD_ChannelGroup_GetChannel(FMOD_CHANNELGROUP *channelgroup, int index);

	void bmx_fmodreverbchannelproperties_delete(FMOD_REVERB_CHANNELPROPERTIES * prop);

	FMOD_ADVANCEDSETTINGS * bmx_advancedsettings_create();
	void bmx_advancedsettings_delete(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmaxMPEGcodecs(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmaxMPEGcodecs(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmaxADPCMcodecs(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmaxADPCMcodecs(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmaxXMAcodecs(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmaxXMAcodecs(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmaxCELTcodecs(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmaxCELTcodecs(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmaxVORBIScodecs(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmaxVORBIScodecs(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmaxPCMcodecs(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmaxPCMcodecs(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setASIONumChannels(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getASIONumChannels(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmax3DReverbDSPs(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmax3DReverbDSPs(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setHRTFMinAngle(FMOD_ADVANCEDSETTINGS * settings, float value);
	float bmx_advancedsettings_getHRTFMinAngle(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setHRTFMaxAngle(FMOD_ADVANCEDSETTINGS * settings, float value);
	float bmx_advancedsettings_getHRTFMaxAngle(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setHRTFFreq(FMOD_ADVANCEDSETTINGS * settings, float value);
	float bmx_advancedsettings_getHRTFFreq(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setvol0virtualvol(FMOD_ADVANCEDSETTINGS * settings, float value);
	float bmx_advancedsettings_getvol0virtualvol(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_seteventqueuesize(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_geteventqueuesize(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setdefaultDecodeBufferSize(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getdefaultDecodeBufferSize(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setprofileport(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getprofileport(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setgeometryMaxFadeTime(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getgeometryMaxFadeTime(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmaxSpectrumWaveDataBuffers(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmaxSpectrumWaveDataBuffers(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setmusicSystemCacheDelay(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getmusicSystemCacheDelay(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setdistanceFilterCenterFreq(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getdistanceFilterCenterFreq(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setstackSizeStream(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getstackSizeStream(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setstackSizeNonBlocking(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getstackSizeNonBlocking(FMOD_ADVANCEDSETTINGS * settings);
	void bmx_advancedsettings_setstackSizeMixer(FMOD_ADVANCEDSETTINGS * settings, int value);
	int bmx_advancedsettings_getstackSizeMixer(FMOD_ADVANCEDSETTINGS * settings);

}

class MAX_FMOD_CHANNEL
{
public:
	MAX_FMOD_CHANNEL()
	{
		channel = 0;
	}
	
	FMOD_CHANNEL * channel;
};


unsigned int bmx_fmod_getversion() {
	return FMOD_VERSION;
}

const char * bmx_FMOD_ErrorString(FMOD_RESULT errcode) {
	return FMOD_ErrorString(errcode);
}


FMOD_SYSTEM  * bmx_FMOD_System_Create(FMOD_RESULT * result) {
	FMOD_SYSTEM * system;

	*result = FMOD_System_Create(&system);

	return system;
}

FMOD_SOUND * bmx_FMOD_System_CreateSound(FMOD_SYSTEM *system, const char * filename, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO * exInfo,
		FMOD_RESULT * result) {

	FMOD_SOUND * sound;
	
	*result = FMOD_System_CreateSound(system, filename, mode, exInfo, &sound);
	
	if (*result) {
		return 0;
	}
	
	return sound;

}

MAX_FMOD_CHANNEL * bmx_FMOD_System_PlaySound(FMOD_SYSTEM *system, FMOD_CHANNELINDEX channelId, FMOD_SOUND * sound,
		FMOD_BOOL paused, MAX_FMOD_CHANNEL * reuse) {
	
	if (reuse) {
		FMOD_RESULT result = FMOD_System_PlaySound(system, channelId, sound, paused, &reuse->channel);
		return reuse;
	} else {

		MAX_FMOD_CHANNEL * channel = new MAX_FMOD_CHANNEL();
		
		FMOD_RESULT result = FMOD_System_PlaySound(system, channelId, sound, paused, &channel->channel);
	
		if (result) {
			delete channel;
			return 0;
		}
		
		return channel;	
	}
}

MAX_FMOD_CHANNEL * bmx_FMOD_System_GetChannel(FMOD_SYSTEM *system, int channelId) {
	MAX_FMOD_CHANNEL * channel = new MAX_FMOD_CHANNEL();
	
	FMOD_RESULT result = FMOD_System_GetChannel(system, channelId, &channel->channel);
	
	if (result) {
		delete channel;
		return 0;
	}
	
	return channel;
}

FMOD_DSP * bmx_FMOD_System_CreateDSPByType(FMOD_SYSTEM *system, FMOD_DSP_TYPE dspType, FMOD_RESULT * ret) {

	FMOD_DSP * dsp;
	
	*ret = FMOD_System_CreateDSPByType(system, dspType, &dsp);
	
	if (*ret) {
		return 0;
	}
	
	return dsp;
}

MAX_FMOD_CHANNEL * bmx_FMOD_System_PlayDSP(FMOD_SYSTEM *system, FMOD_CHANNELINDEX channelId, FMOD_DSP * dsp,
		FMOD_BOOL paused, MAX_FMOD_CHANNEL * reuse) {

	if (reuse) {
		FMOD_RESULT result = FMOD_System_PlayDSP(system, channelId, dsp, paused, &reuse->channel);
		
		return reuse;
	} else {
	
		MAX_FMOD_CHANNEL * channel = new MAX_FMOD_CHANNEL();

		FMOD_RESULT result = FMOD_System_PlayDSP(system, channelId, dsp, paused, &channel->channel);
	
		if (result) {
			delete channel;
			return 0;
		}
		return channel;	
	}
}

FMOD_SOUND * bmx_FMOD_System_CreateStream(FMOD_SYSTEM *system, const char * filename, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO * exInfo,
		FMOD_RESULT * result) {

	FMOD_SOUND * sound;
	
	*result = FMOD_System_CreateStream(system, filename, mode, exInfo, &sound);
	
	if (*result) {
		return 0;
	}
	
	return sound;

}

FMOD_REVERB * bmx_FMOD_System_CreateReverb(FMOD_SYSTEM *system) {
	FMOD_REVERB * reverb;
	
	FMOD_RESULT result = FMOD_System_CreateReverb(system, &reverb);
	
	if (result) {
		return 0;
	}
	
	return reverb;
}

FMOD_RESULT bmx_FMOD_System_GetSpectrum(FMOD_SYSTEM *system, BBArray * spectrumArray, int channelOffset, FMOD_DSP_FFT_WINDOW windowType) {

	int size = spectrumArray->scales[0];
	float arr[size];
	
	FMOD_RESULT res = FMOD_System_GetSpectrum(system, &arr[0], size, channelOffset, windowType);

	float *s=(float*)BBARRAYDATA( spectrumArray, spectrumArray->dims );
	for (int i = 0; i < size; i ++) {
		s[i] = arr[i];
	}
	
	return res;
}

FMOD_CHANNELGROUP * bmx_FMOD_System_CreateChannelGroup(FMOD_SYSTEM *system, const char * name) {
	FMOD_CHANNELGROUP * group;
	
	FMOD_RESULT res = FMOD_System_CreateChannelGroup(system, name, &group);
	
	if (res) {
		return 0;
	}

	return group;
}

FMOD_CHANNELGROUP * bmx_FMOD_System_GetMasterChannelGroup(FMOD_SYSTEM *system) {
	FMOD_CHANNELGROUP * group;
	
	FMOD_RESULT res = FMOD_System_GetMasterChannelGroup(system, &group);
	
	if (res) {
		return 0;
	}
	
	return group;	
}

// ++++++++++++++++++++++++++++++++

void bmx_fmodchannel_delete(MAX_FMOD_CHANNEL * channel) {
	delete channel;
}


FMOD_RESULT bmx_FMOD_Channel_GetSpectrum(MAX_FMOD_CHANNEL *channel, BBArray * spectrumArray, int channelOffset, FMOD_DSP_FFT_WINDOW windowType) {

	int size = spectrumArray->scales[0];
	float arr[size];
	
	FMOD_RESULT res = FMOD_Channel_GetSpectrum(channel->channel, &arr[0], size, channelOffset, windowType);

	float *s=(float*)BBARRAYDATA( spectrumArray, spectrumArray->dims );
	for (int i = 0; i < size; i ++) {
		s[i] = arr[i];
	}
	
	return res;
}

FMOD_SOUND * bmx_FMOD_Channel_GetCurrentSound(MAX_FMOD_CHANNEL *channel) {

	FMOD_SOUND * sound;
	
	FMOD_RESULT result = FMOD_Channel_GetCurrentSound(channel->channel, &sound);

	if (result) {
		return 0;
	}
	
	return sound;
}

FMOD_RESULT bmx_FMOD_Channel_GetPaused(MAX_FMOD_CHANNEL *channel, FMOD_BOOL * paused) {
	return FMOD_Channel_GetPaused(channel->channel, paused);
}

FMOD_RESULT bmx_FMOD_Channel_SetPaused(MAX_FMOD_CHANNEL *channel, FMOD_BOOL paused) {
	return FMOD_Channel_SetPaused(channel->channel, paused);
}

FMOD_RESULT bmx_FMOD_Channel_Stop(MAX_FMOD_CHANNEL *channel) {
	return FMOD_Channel_Stop(channel->channel);
}

FMOD_RESULT bmx_FMOD_Channel_GetVolume(MAX_FMOD_CHANNEL *channel, float * volume) {
	return FMOD_Channel_GetVolume(channel->channel, volume);
}

FMOD_RESULT bmx_FMOD_Channel_SetVolume(MAX_FMOD_CHANNEL *channel, float volume) {
	return FMOD_Channel_SetVolume(channel->channel, volume);
}

FMOD_RESULT bmx_FMOD_Channel_GetPan(MAX_FMOD_CHANNEL *channel, float * pan) {
	return FMOD_Channel_GetPan(channel->channel, pan);
}

FMOD_RESULT bmx_FMOD_Channel_SetPan(MAX_FMOD_CHANNEL *channel, float pan) {
	return FMOD_Channel_SetPan(channel->channel, pan);
}

FMOD_RESULT bmx_FMOD_Channel_GetDelay(MAX_FMOD_CHANNEL *channel, FMOD_DELAYTYPE delaytype, unsigned int *delayhi, unsigned int *delaylo) {
	return FMOD_Channel_GetDelay(channel->channel, delaytype, delayhi, delaylo);
}

FMOD_RESULT bmx_FMOD_Channel_IsPlaying(MAX_FMOD_CHANNEL *channel, FMOD_BOOL *isplaying) {
    return FMOD_Channel_IsPlaying(channel->channel, isplaying);
}

FMOD_RESULT bmx_FMOD_Channel_IsVirtual(MAX_FMOD_CHANNEL *channel, FMOD_BOOL *isvirtual) {
    return FMOD_Channel_IsVirtual(channel->channel, isvirtual);
}

FMOD_RESULT bmx_FMOD_Channel_GetAudibility(MAX_FMOD_CHANNEL *channel, float *audibility) {
    return FMOD_Channel_GetAudibility(channel->channel, audibility);
}

FMOD_RESULT bmx_FMOD_Channel_GetIndex(MAX_FMOD_CHANNEL *channel, int *index) {
    return FMOD_Channel_GetIndex(channel->channel, index);
}

FMOD_RESULT bmx_FMOD_Channel_SetFrequency(MAX_FMOD_CHANNEL *channel, float frequency) {
    return FMOD_Channel_SetFrequency(channel->channel, frequency);
}

FMOD_RESULT bmx_FMOD_Channel_GetFrequency(MAX_FMOD_CHANNEL *channel, float *frequency) {
    return FMOD_Channel_GetFrequency(channel->channel, frequency);
}

FMOD_RESULT bmx_FMOD_Channel_GetPosition(MAX_FMOD_CHANNEL *channel, unsigned int *position, FMOD_TIMEUNIT postype) {
    return FMOD_Channel_GetPosition(channel->channel, position, postype);
}

FMOD_RESULT bmx_FMOD_Channel_SetLoopCount(MAX_FMOD_CHANNEL *channel, int loopcount) {
    return FMOD_Channel_SetLoopCount(channel->channel, loopcount);
}

FMOD_RESULT bmx_FMOD_Channel_GetLoopCount(MAX_FMOD_CHANNEL *channel, int *loopcount) {
    return FMOD_Channel_GetLoopCount(channel->channel, loopcount);
}

FMOD_RESULT bmx_FMOD_Channel_SetLoopPoints(MAX_FMOD_CHANNEL *channel, unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype) {
    return FMOD_Channel_SetLoopPoints(channel->channel, loopstart, loopstarttype, loopend, loopendtype);
}

FMOD_RESULT bmx_FMOD_Channel_GetLoopPoints(MAX_FMOD_CHANNEL *channel, unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype) {
    return FMOD_Channel_GetLoopPoints(channel->channel, loopstart, loopstarttype, loopend, loopendtype);
}

FMOD_RESULT bmx_FMOD_Channel_Get3DAttributes(MAX_FMOD_CHANNEL *channel, FMOD_VECTOR *pos, FMOD_VECTOR *vel) {
    return FMOD_Channel_Get3DAttributes(channel->channel, pos, vel);
}

FMOD_RESULT bmx_FMOD_Channel_Get3DMinMaxDistance(MAX_FMOD_CHANNEL *channel, float *mindistance, float *maxdistance) {
    return FMOD_Channel_Get3DMinMaxDistance(channel->channel, mindistance, maxdistance);
}

FMOD_RESULT bmx_FMOD_Channel_Get3DConeOrientation(MAX_FMOD_CHANNEL *channel, FMOD_VECTOR *orientation) {
    return FMOD_Channel_Get3DConeOrientation(channel->channel, orientation);
}

FMOD_RESULT bmx_FMOD_Channel_Get3DOcclusion(MAX_FMOD_CHANNEL *channel, float *directocclusion, float *reverbocclusion) {
    return FMOD_Channel_Get3DOcclusion(channel->channel, directocclusion, reverbocclusion);
}

FMOD_RESULT bmx_FMOD_Channel_Get3DDopplerLevel(MAX_FMOD_CHANNEL *channel, float *level) {
    return FMOD_Channel_Get3DDopplerLevel(channel->channel, level);
}

FMOD_RESULT bmx_FMOD_Channel_Get3DSpread(MAX_FMOD_CHANNEL *channel, float *angle) {
    return FMOD_Channel_Get3DSpread(channel->channel, angle);
}

FMOD_RESULT bmx_FMOD_Channel_Get3DPanLevel(MAX_FMOD_CHANNEL *channel, float *level) {
    return FMOD_Channel_Get3DPanLevel(channel->channel, level);
}

FMOD_RESULT bmx_FMOD_Channel_SetChannelGroup(MAX_FMOD_CHANNEL *channel, FMOD_CHANNELGROUP * group) {
	return FMOD_Channel_SetChannelGroup(channel->channel, group);
}

FMOD_RESULT bmx_FMOD_Channel_Get3DConeSettings(MAX_FMOD_CHANNEL *channel, float * insideConeAngle, float * outsideConeAngle, float * outsideVolume) {
	return FMOD_Channel_Get3DConeSettings(channel->channel, insideConeAngle, outsideConeAngle, outsideVolume);
}

FMOD_CHANNELGROUP * bmx_FMOD_Channel_GetChannelGroup(MAX_FMOD_CHANNEL *channel) {
	FMOD_CHANNELGROUP * group;

	FMOD_RESULT result = FMOD_Channel_GetChannelGroup(channel->channel, &group);

	if (result) {
		return 0;
	}
	
	return group;
}

FMOD_RESULT bmx_FMOD_Channel_GetMode(MAX_FMOD_CHANNEL *channel, FMOD_MODE * mode) {
	return FMOD_Channel_GetMode(channel->channel, mode);
}

FMOD_RESULT bmx_FMOD_Channel_GetMute(MAX_FMOD_CHANNEL *channel, FMOD_BOOL * mute) {
	return FMOD_Channel_GetMute(channel->channel, mute);
}

FMOD_RESULT bmx_FMOD_Channel_GetPriority(MAX_FMOD_CHANNEL *channel, int * priority) {
	return FMOD_Channel_GetPriority(channel->channel, priority);
}

FMOD_RESULT bmx_FMOD_Channel_GetReverbProperties(MAX_FMOD_CHANNEL *channel, FMOD_REVERB_CHANNELPROPERTIES * properties) {
	return FMOD_Channel_GetReverbProperties(channel->channel, properties);
}

FMOD_RESULT bmx_FMOD_Channel_SetReverbProperties(MAX_FMOD_CHANNEL *channel, FMOD_REVERB_CHANNELPROPERTIES * properties) {
	return FMOD_Channel_SetReverbProperties(channel->channel, properties);
}

FMOD_RESULT bmx_FMOD_Channel_SetPriority(MAX_FMOD_CHANNEL *channel, int priority) {
	return FMOD_Channel_SetPriority(channel->channel, priority);
}

FMOD_RESULT bmx_FMOD_Channel_GetLowPassGain(MAX_FMOD_CHANNEL *channel, float * gain) {
	return FMOD_Channel_GetLowPassGain(channel->channel, gain);
}

FMOD_RESULT bmx_FMOD_Channel_GetSpeakerLevels(MAX_FMOD_CHANNEL *channel, FMOD_SPEAKER speaker, BBArray * levels) {
	int n = levels->scales[0];
	float *f=(float*)BBARRAYDATA( levels,levels->dims );
	return FMOD_Channel_GetSpeakerLevels(channel->channel, speaker, f, n);
}

FMOD_RESULT bmx_FMOD_Channel_GetSpeakerMix(MAX_FMOD_CHANNEL *channel, float * frontleft, float * frontright, float * center,
		float * lfe, float * backleft, float * backright, float * sideleft, float * sideright) {
	return FMOD_Channel_GetSpeakerMix(channel->channel, frontleft, frontright, center, lfe, backleft, backright, sideleft, sideright);
}

FMOD_RESULT bmx_FMOD_Channel_GetWaveData(MAX_FMOD_CHANNEL *channel, BBArray * waveArray, int channelOffset) {
	int n = waveArray->scales[0];
	float *f=(float*)BBARRAYDATA( waveArray, waveArray->dims );
	return FMOD_Channel_GetWaveData(channel->channel, f, n, channelOffset);
}

FMOD_RESULT bmx_FMOD_Channel_SetDelay(MAX_FMOD_CHANNEL *channel, FMOD_DELAYTYPE delayType, unsigned int delayHi, unsigned int delayLo) {
	return FMOD_Channel_SetDelay(channel->channel, delayType, delayHi, delayLo);
}

FMOD_RESULT bmx_FMOD_Channel_SetInputChannelMix(MAX_FMOD_CHANNEL *channel, BBArray * levels) {
	int n = levels->scales[0];
	float *f=(float*)BBARRAYDATA( levels, levels->dims );
	return FMOD_Channel_SetInputChannelMix(channel->channel, f, n);
}

FMOD_RESULT bmx_FMOD_Channel_SetLowPassGain(MAX_FMOD_CHANNEL *channel, float gain) {
	return FMOD_Channel_SetLowPassGain(channel->channel, gain);
}

FMOD_RESULT bmx_FMOD_Channel_SetMode(MAX_FMOD_CHANNEL *channel, FMOD_MODE mode) {
	return FMOD_Channel_SetMode(channel->channel, mode);
}

FMOD_RESULT bmx_FMOD_Channel_SetMute(MAX_FMOD_CHANNEL *channel, bool mute) {
	return FMOD_Channel_SetMute(channel->channel, mute);
}

FMOD_RESULT bmx_FMOD_Channel_SetPosition(MAX_FMOD_CHANNEL *channel, unsigned int position, FMOD_TIMEUNIT postype) {
	return FMOD_Channel_SetPosition(channel->channel, position, postype);
}


// ++++++++++++++++++++++++++++++++

FMOD_CREATESOUNDEXINFO * bmx_soundexinfo_create() {
	FMOD_CREATESOUNDEXINFO * info = (FMOD_CREATESOUNDEXINFO *)malloc(sizeof(FMOD_CREATESOUNDEXINFO));
	
	memset(info, 0, sizeof(FMOD_CREATESOUNDEXINFO)); // need to zerofy the data
	
	info->cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
	return info;
}

void bmx_soundexinfo_setlength(FMOD_CREATESOUNDEXINFO * info, int length) {
	info->length = length;
}

void bmx_soundexinfo_delete(FMOD_CREATESOUNDEXINFO * info) {
	free(info);
}

void bmx_soundexinfo_setnumchannels(FMOD_CREATESOUNDEXINFO * info, int numChannels) {
	info->numchannels = numChannels;
}

void bmx_soundexinfo_setdefaultfrequency(FMOD_CREATESOUNDEXINFO * info, int frequency) {
	info->defaultfrequency = frequency;
}

void bmx_soundexinfo_setformat(FMOD_CREATESOUNDEXINFO * info, FMOD_SOUND_FORMAT format) {
	info->format = format;
}

void bmx_soundexinfo_setdecodebuffersize(FMOD_CREATESOUNDEXINFO * info, unsigned int bufferSize) {
	info->decodebuffersize = bufferSize;
}

void bmx_soundexinfo_setinitialsubsound(FMOD_CREATESOUNDEXINFO * info, int initial) {
	info->initialsubsound = initial;
}

void bmx_soundexinfo_setnumsubsounds(FMOD_CREATESOUNDEXINFO * info, int num) {
	info->numsubsounds = num;
}

void bmx_soundexinfo_setpcmreadcallback(FMOD_CREATESOUNDEXINFO * info, FMOD_SOUND_PCMREADCALLBACK cb) {
	info->pcmreadcallback = cb;
}

BBObject * bmx_soundexinfo_getuserdata(FMOD_CREATESOUNDEXINFO * info) {
	void * obj = info->userdata;
	if (obj) {
		return (BBObject*)obj;
	} else {
		return &bbNullObject;
	}
}

void bmx_soundexinfo_setuserdata(FMOD_CREATESOUNDEXINFO * info, BBObject * obj) {
	BBRETAIN(obj);
	info->userdata = obj;
}

void bmx_soundexinfo_setpcmsetposcallback(FMOD_CREATESOUNDEXINFO * info, FMOD_SOUND_PCMSETPOSCALLBACK cb) {
	info->pcmsetposcallback = cb;
}

// ++++++++++++++++++++++++++++++++

FMOD_SOUND * bmx_FMOD_SoundGroup_GetSound(FMOD_SOUNDGROUP *soundgroup, int index) {
	FMOD_SOUND * sound;
	FMOD_RESULT result = FMOD_SoundGroup_GetSound(soundgroup, index, &sound);
	
	if (result) {
		return 0;
	}
	
	return sound;
}


// ++++++++++++++++++++++++++++++++

FMOD_TAG * bmx_FMOD_Sound_GetTag(FMOD_SOUND * sound, const char * name, int index) {
	FMOD_TAG * tag = new FMOD_TAG;
	FMOD_RESULT result = FMOD_Sound_GetTag(sound, name, index, tag);
	if (result) {
		return 0;
	}
	
	return tag;
}

FMOD_RESULT bmx_FMOD_Sound_SetSubSoundSentence(FMOD_SOUND * sound, BBArray * soundList) {
	int length = soundList->scales[0];
	int *s=(int*)BBARRAYDATA( soundList, soundList->dims );

	return FMOD_Sound_SetSubSoundSentence(sound, s, length);
}

FMOD_SOUND * bmx_FMOD_Sound_GetSubSound(FMOD_SOUND * sound, int index) {
	FMOD_SOUND * subsound;
	FMOD_RESULT result = FMOD_Sound_GetSubSound(sound, index, &subsound);

	if (result) {
		return 0;
	}
	
	return subsound;
	
}

BBObject * bmx_FMOD_Sound_GetUserData(FMOD_SOUND * sound) {
	void * data;
	FMOD_RESULT ret = FMOD_Sound_GetUserData(sound, &data);
	if (data) {
		return (BBObject*)data;
	} else {
		return &bbNullObject;
	}
}

void bmx_FMOD_Sound_SetUserData(FMOD_SOUND * sound, BBObject * obj) {
	
}


// ++++++++++++++++++++++++++++++++

void * bmx_fmodtag_getdata(FMOD_TAG * tag) {
	return tag->data;
}

void bmx_fmodtag_delete(FMOD_TAG * tag) {
	delete tag;
}

FMOD_TAGTYPE bmx_fmodtag_gettagtype(FMOD_TAG * tag) {
	return tag->type;
}

FMOD_TAGDATATYPE bmx_fmodtag_getdatatype(FMOD_TAG * tag) {
	return tag->datatype;
}

char * bmx_fmodtag_getname(FMOD_TAG * tag) {
	return tag->name;
}

unsigned int bmx_fmodtag_getdatalength(FMOD_TAG * tag) {
	return tag->datalen;
}

FMOD_BOOL bmx_fmodtag_getupdated(FMOD_TAG * tag) {
	return tag->updated;
}


// ++++++++++++++++++++++++++++++++

MAX_FMOD_CHANNEL * bmx_FMOD_ChannelGroup_GetChannel(FMOD_CHANNELGROUP *channelgroup, int index) {
	MAX_FMOD_CHANNEL * channel = new MAX_FMOD_CHANNEL;
	FMOD_RESULT result = FMOD_ChannelGroup_GetChannel(channelgroup, index, &channel->channel);
	
	if (result) {
		delete channel;
		return 0;
	}
	
	return channel;
}

// ++++++++++++++++++++++++++++++++

void bmx_fmodreverbchannelproperties_delete(FMOD_REVERB_CHANNELPROPERTIES * prop) {
	delete prop;
}

// ++++++++++++++++++++++++++++++++

FMOD_ADVANCEDSETTINGS * bmx_advancedsettings_create() {
	FMOD_ADVANCEDSETTINGS * settings = (FMOD_ADVANCEDSETTINGS *)malloc(sizeof(FMOD_ADVANCEDSETTINGS));
	
	memset(settings, 0, sizeof(FMOD_ADVANCEDSETTINGS)); // need to zerofy the data
	
	settings->cbsize = sizeof(FMOD_ADVANCEDSETTINGS);
	return settings;
}

void bmx_advancedsettings_delete(FMOD_ADVANCEDSETTINGS * settings) {
	free(settings);
}

void bmx_advancedsettings_setmaxMPEGcodecs(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->maxMPEGcodecs = value;
}

int bmx_advancedsettings_getmaxMPEGcodecs(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->maxMPEGcodecs;
}

void bmx_advancedsettings_setmaxADPCMcodecs(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->maxADPCMcodecs = value;
}

int bmx_advancedsettings_getmaxADPCMcodecs(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->maxADPCMcodecs;
}

void bmx_advancedsettings_setmaxXMAcodecs(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->maxXMAcodecs = value;
}

int bmx_advancedsettings_getmaxXMAcodecs(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->maxXMAcodecs;
}

void bmx_advancedsettings_setmaxCELTcodecs(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->maxCELTcodecs = value;
}

int bmx_advancedsettings_getmaxCELTcodecs(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->maxCELTcodecs;
}

void bmx_advancedsettings_setmaxVORBIScodecs(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->maxVORBIScodecs = value;
}

int bmx_advancedsettings_getmaxVORBIScodecs(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->maxVORBIScodecs;
}

void bmx_advancedsettings_setmaxPCMcodecs(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->maxPCMcodecs = value;
}

int bmx_advancedsettings_getmaxPCMcodecs(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->maxPCMcodecs;
}

void bmx_advancedsettings_setASIONumChannels(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->ASIONumChannels = value;
}

int bmx_advancedsettings_getASIONumChannels(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->ASIONumChannels;
}

void bmx_advancedsettings_setmax3DReverbDSPs(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->max3DReverbDSPs = value;
}

int bmx_advancedsettings_getmax3DReverbDSPs(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->max3DReverbDSPs;
}

void bmx_advancedsettings_setHRTFMinAngle(FMOD_ADVANCEDSETTINGS * settings, float value) {
	settings->HRTFMinAngle = value;
}

float bmx_advancedsettings_getHRTFMinAngle(FMOD_ADVANCEDSETTINGS * settings) {
	return settings->HRTFMinAngle;
}

void bmx_advancedsettings_setHRTFMaxAngle(FMOD_ADVANCEDSETTINGS * settings, float value) {
	settings->HRTFMaxAngle = value;
}

float bmx_advancedsettings_getHRTFMaxAngle(FMOD_ADVANCEDSETTINGS * settings) {
	return settings->HRTFMaxAngle;
}

void bmx_advancedsettings_setHRTFFreq(FMOD_ADVANCEDSETTINGS * settings, float value) {
	settings->HRTFFreq = value;
}

float bmx_advancedsettings_getHRTFFreq(FMOD_ADVANCEDSETTINGS * settings) {
	return settings->HRTFFreq;
}

void bmx_advancedsettings_setvol0virtualvol(FMOD_ADVANCEDSETTINGS * settings, float value) {
	settings->vol0virtualvol = value;
}

float bmx_advancedsettings_getvol0virtualvol(FMOD_ADVANCEDSETTINGS * settings) {
	return settings->vol0virtualvol;
}

void bmx_advancedsettings_seteventqueuesize(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->eventqueuesize = value;
}

int bmx_advancedsettings_geteventqueuesize(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->eventqueuesize;
}

void bmx_advancedsettings_setdefaultDecodeBufferSize(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->defaultDecodeBufferSize = value;
}

int bmx_advancedsettings_getdefaultDecodeBufferSize(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->defaultDecodeBufferSize;
}

void bmx_advancedsettings_setprofileport(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->profileport = value;
}

int bmx_advancedsettings_getprofileport(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->profileport;
}

void bmx_advancedsettings_setgeometryMaxFadeTime(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->geometryMaxFadeTime = value;
}

int bmx_advancedsettings_getgeometryMaxFadeTime(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->geometryMaxFadeTime;
}

void bmx_advancedsettings_setmaxSpectrumWaveDataBuffers(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->maxSpectrumWaveDataBuffers = value;
}

int bmx_advancedsettings_getmaxSpectrumWaveDataBuffers(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->maxSpectrumWaveDataBuffers;
}

void bmx_advancedsettings_setmusicSystemCacheDelay(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->musicSystemCacheDelay = value;
}

int bmx_advancedsettings_getmusicSystemCacheDelay(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->musicSystemCacheDelay;
}

void bmx_advancedsettings_setdistanceFilterCenterFreq(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->distanceFilterCenterFreq = value;
}

int bmx_advancedsettings_getdistanceFilterCenterFreq(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->distanceFilterCenterFreq;
}

void bmx_advancedsettings_setstackSizeStream(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->stackSizeStream = value;
}

int bmx_advancedsettings_getstackSizeStream(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->stackSizeStream;
}

void bmx_advancedsettings_setstackSizeNonBlocking(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->stackSizeNonBlocking = value;
}

int bmx_advancedsettings_getstackSizeNonBlocking(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->stackSizeNonBlocking;
}

void bmx_advancedsettings_setstackSizeMixer(FMOD_ADVANCEDSETTINGS * settings, int value) {
	settings->stackSizeMixer = value;
}

int bmx_advancedsettings_getstackSizeMixer(FMOD_ADVANCEDSETTINGS * settings) {
	return (int)settings->stackSizeMixer;
}


