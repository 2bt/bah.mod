/*
 Copyright (c) 2011-2016 Bruce A Henderson
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of Bruce A Henderson nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY Bruce A Henderson ``AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL Bruce A Henderson BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "TheoraPlayer.h"
#include "TheoraException.h"
#include "TheoraDataSource.h"

class MaxTheoraDataSource;

extern "C" {

#include "blitz.h"

#ifdef BMX_NG
#define CB_PREF(func) func
#else
#define CB_PREF(func) _##func
#endif

#ifdef BMX_NG
	BBObject * CB_PREF(bah_theoraplayer_common_TTheoraGenericException__create)(BBString * mErrText, BBString * mFile, BBString * mType);
#else
	BBObject * CB_PREF(bah_theoraplayer_TTheoraGenericException__create)(BBString * mErrText, BBString * mFile, BBString * mType);
#endif
	
	int CB_PREF(bah_theoraplayer_TTheoraDataSource__read)(BBObject * handle, void * output, int nBytes);
	BBString * CB_PREF(bah_theoraplayer_TTheoraDataSource__repr)(BBObject * handle);
	void CB_PREF(bah_theoraplayer_TTheoraDataSource__seek)(BBObject * handle, unsigned long byte_index);
	int CB_PREF(bah_theoraplayer_TTheoraDataSource__size)(BBObject * handle);
	int CB_PREF(bah_theoraplayer_TTheoraDataSource__tell)(BBObject * handle);

	TheoraVideoManager * bmx_TheoraVideoManager_new(int numWorkerThreads);
	void bmx_TheoraVideoManager_free(TheoraVideoManager * manager);
	TheoraVideoClip * bmx_TheoraVideoManager_createVideoClip(TheoraVideoManager * manager, BBString * filename, int outputMode, int numPrecachedOverride, int usePower2Stride);
	TheoraVideoClip * bmx_TheoraVideoManager_createVideoClipDataSource(TheoraVideoManager * manager, MaxTheoraDataSource * source, int outputMode, int numPrecachedOverride, int usePower2Stride);
	void bmx_TheoraVideoManager_update(TheoraVideoManager * manager, float timeIncrease);
	void bmx_TheoraVideoManager_setAudioInterfaceFactory(TheoraVideoManager * manager, TheoraAudioInterfaceFactory * factory);
	void bmx_TheoraVideoManager_getVersion(TheoraVideoManager * manager, int * a, int * b, int * c);
	BBString * bmx_TheoraVideoManager_getVersionString(TheoraVideoManager * manager);
	void bmx_TheoraVideoManager_destroyVideoClip(TheoraVideoManager * manager, TheoraVideoClip * clip);
	int bmx_TheoraVideoManager_getNumWorkerThreads(TheoraVideoManager * manager);
	void bmx_TheoraVideoManager_setNumWorkerThreads(TheoraVideoManager * manager, int numWorkerThreads);
	TheoraVideoClip * bmx_TheoraVideoManager_getVideoClipByName(TheoraVideoManager * manager, BBString * name);

	BBString * bmx_TheoraVideoClip_getName(TheoraVideoClip * clip);
	int bmx_TheoraVideoClip_getWidth(TheoraVideoClip * clip);
	int bmx_TheoraVideoClip_getHeight(TheoraVideoClip * clip);
	int bmx_TheoraVideoClip_getStride(TheoraVideoClip * clip);
	TheoraVideoFrame * bmx_TTheoraVideoClip_getNextFrame(TheoraVideoClip * clip);
	void bmx_TheoraVideoClip_popFrame(TheoraVideoClip * clip);
	float bmx_TheoraVideoClip_getTimePosition(TheoraVideoClip * clip);
	float bmx_TheoraVideoClip_getDuration(TheoraVideoClip * clip);
	int bmx_TheoraVideoClip_getFPS(TheoraVideoClip * clip);
	int bmx_TheoraVideoClip_getNumFrames(TheoraVideoClip * clip);
	int bmx_TheoraVideoClip_isDone(TheoraVideoClip * clip);
	void bmx_TheoraVideoClip_play(TheoraVideoClip * clip);
	void bmx_TheoraVideoClip_pause(TheoraVideoClip * clip);
	void bmx_TheoraVideoClip_restart(TheoraVideoClip * clip);
	int bmx_TheoraVideoClip_isPaused(TheoraVideoClip * clip);
	void bmx_TheoraVideoClip_stop(TheoraVideoClip * clip);
	void bmx_TheoraVideoClip_setPlaybackSpeed(TheoraVideoClip * clip, float speed);
	float bmx_TheoraVideoClip_getPlaybackSpeed(TheoraVideoClip * clip);
	void bmx_TheoraVideoClip_seek(TheoraVideoClip * clip, float time);
	float bmx_TheoraVideoClip_updateToNextFrame(TheoraVideoClip * clip);
	void bmx_TheoraVideoClip_setAutoRestart(TheoraVideoClip * clip, int restart);
	int bmx_TheoraVideoClip_getAutoRestart(TheoraVideoClip * clip);

	void * bmx_TheoraVideoFrame_getBuffer(TheoraVideoFrame * frame);

	void (*bmx_LogFunction)(BBString *)=0;	
	void bmx_TheoraVideoManager_setLogFunction(void (*fn)(BBString * s));
	
	MaxTheoraDataSource * bmx_TheoraDataSource_create(BBObject * handle);
	void bmx_TheoraDataSource_free(MaxTheoraDataSource * source);

}


class MaxTheoraDataSource : public TheoraDataSource
{
public:

	MaxTheoraDataSource(BBObject * handle)
		: maxHandle(handle)
	{
	}
	
	~MaxTheoraDataSource()
	{
	}

	int read(void * output, int nBytes) {
		return CB_PREF(bah_theoraplayer_TTheoraDataSource__read)(maxHandle, output, nBytes);
	}
	
	std::string repr() {
		BBString * text = CB_PREF(bah_theoraplayer_TTheoraDataSource__repr)(maxHandle);
		char * r = bbStringToUTF8String(text);
		std::string s( r );
		bbMemFree( r );
		return s;
	}
	
	void seek(unsigned long byte_index) {
		CB_PREF(bah_theoraplayer_TTheoraDataSource__seek)(maxHandle, byte_index);
	}
	
	unsigned long size() {
		return CB_PREF(bah_theoraplayer_TTheoraDataSource__size)(maxHandle);
	}
	
	unsigned long tell() {
		return CB_PREF(bah_theoraplayer_TTheoraDataSource__tell)(maxHandle);
	}

private:
	BBObject * maxHandle;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void bmx_theoraplayer_throw_exception(_TheoraGenericException & e) {
#ifdef BMX_NG
	bbExThrow(CB_PREF(bah_theoraplayer_common_TTheoraGenericException__create)(bbStringFromUTF8String(e.mErrText.data()),
#else
	bbExThrow(CB_PREF(bah_theoraplayer_TTheoraGenericException__create)(bbStringFromUTF8String(e.mErrText.data()),
#endif
		bbStringFromUTF8String(e.mFile.data()),
		bbStringFromUTF8String(e.mType.data())));
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TheoraVideoManager * bmx_TheoraVideoManager_new(int numWorkerThreads) {
	return new TheoraVideoManager(numWorkerThreads);
}

void bmx_TheoraVideoManager_free(TheoraVideoManager * manager) {
	delete manager;
}

TheoraVideoClip * bmx_TheoraVideoManager_createVideoClip(TheoraVideoManager * manager, BBString * filename, int outputMode, int numPrecachedOverride, int usePower2Stride) {
	TheoraVideoClip * clip = 0;
	char * f = bbStringToUTF8String(filename);
	
	try {
		clip = manager->createVideoClip(f, (TheoraOutputMode)outputMode, numPrecachedOverride, usePower2Stride);
	} catch (_TheoraGenericException & e) {
		bbMemFree(f);
		bmx_theoraplayer_throw_exception(e);
	}
	
	bbMemFree(f);
	return clip;
}

TheoraVideoClip * bmx_TheoraVideoManager_createVideoClipDataSource(TheoraVideoManager * manager, MaxTheoraDataSource * source, int outputMode, int numPrecachedOverride, int usePower2Stride) {
	TheoraVideoClip * clip = 0;

	try {
		clip = manager->createVideoClip(source, (TheoraOutputMode)outputMode, numPrecachedOverride, usePower2Stride);
	} catch (_TheoraGenericException & e) {
		bmx_theoraplayer_throw_exception(e);
	}
	
	return clip;
}

void bmx_TheoraVideoManager_update(TheoraVideoManager * manager, float timeIncrease) {
	manager->update(timeIncrease);
}

TheoraVideoFrame * bmx_TTheoraVideoClip_getNextFrame(TheoraVideoClip * clip) {
	return clip->getNextFrame();
}

void bmx_TheoraVideoManager_setAudioInterfaceFactory(TheoraVideoManager * manager, TheoraAudioInterfaceFactory * factory) {
	manager->setAudioInterfaceFactory(factory);
}

void bmx_TheoraVideoManager_getVersion(TheoraVideoManager * manager, int * a, int * b, int * c) {
	manager->getVersion(a, b, c);
}

BBString * bmx_TheoraVideoManager_getVersionString(TheoraVideoManager * manager) {
	return bbStringFromUTF8String(manager->getVersionString().data());
}

void bmx_TheoraVideoManager_destroyVideoClip(TheoraVideoManager * manager, TheoraVideoClip * clip) {
	manager->destroyVideoClip(clip);
}

int bmx_TheoraVideoManager_getNumWorkerThreads(TheoraVideoManager * manager) {
	return manager->getNumWorkerThreads();
}

void bmx_TheoraVideoManager_setNumWorkerThreads(TheoraVideoManager * manager, int numWorkerThreads) {
	manager->setNumWorkerThreads(numWorkerThreads);
}

void bmx_TheoraVideoManager_logFunction(std::string s) {
	if (bmx_LogFunction) {
		bmx_LogFunction(bbStringFromUTF8String(s.c_str()));
	}
}

void bmx_TheoraVideoManager_setLogFunction(void (*fn)(BBString * s)) {
	bmx_LogFunction = fn;
	TheoraVideoManager::getSingleton().setLogFunction(bmx_TheoraVideoManager_logFunction);
}

TheoraVideoClip * bmx_TheoraVideoManager_getVideoClipByName(TheoraVideoManager * manager, BBString * name) {
	TheoraVideoClip * clip = 0;
	char * n = bbStringToUTF8String(name);
	clip = manager->getVideoClipByName(n);
	bbMemFree(n);
	return clip;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

BBString * bmx_TheoraVideoClip_getName(TheoraVideoClip * clip) {
	return bbStringFromUTF8String(clip->getName().data());
}

int bmx_TheoraVideoClip_getWidth(TheoraVideoClip * clip) {
	return clip->getWidth();
}

int bmx_TheoraVideoClip_getHeight(TheoraVideoClip * clip) {
	return clip->getHeight();
}

int bmx_TheoraVideoClip_getStride(TheoraVideoClip * clip) {
	return clip->getStride();
}

void bmx_TheoraVideoClip_popFrame(TheoraVideoClip * clip) {
	clip->popFrame();
}

float bmx_TheoraVideoClip_getTimePosition(TheoraVideoClip * clip) {
	return clip->getTimePosition();
}

float bmx_TheoraVideoClip_getDuration(TheoraVideoClip * clip) {
	return clip->getDuration();
}

int bmx_TheoraVideoClip_getFPS(TheoraVideoClip * clip) {
	return clip->getFPS();
}

int bmx_TheoraVideoClip_getNumFrames(TheoraVideoClip * clip) {
	return clip->getNumFrames();
}

int bmx_TheoraVideoClip_isDone(TheoraVideoClip * clip) {
	return clip->isDone();
}

void bmx_TheoraVideoClip_play(TheoraVideoClip * clip) {
	clip->play();
}

void bmx_TheoraVideoClip_pause(TheoraVideoClip * clip) {
	clip->pause();
}

void bmx_TheoraVideoClip_restart(TheoraVideoClip * clip) {
	clip->restart();
}

int bmx_TheoraVideoClip_isPaused(TheoraVideoClip * clip) {
	return clip->isPaused();
}

void bmx_TheoraVideoClip_stop(TheoraVideoClip * clip) {
	clip->stop();
}

void bmx_TheoraVideoClip_setPlaybackSpeed(TheoraVideoClip * clip, float speed) {
	clip->setPlaybackSpeed(speed);
}

float bmx_TheoraVideoClip_getPlaybackSpeed(TheoraVideoClip * clip) {
	return clip->getPlaybackSpeed();
}

void bmx_TheoraVideoClip_seek(TheoraVideoClip * clip, float time) {
	clip->seek(time);
}

float bmx_TheoraVideoClip_updateToNextFrame(TheoraVideoClip * clip) {
	return clip->updateToNextFrame();
}

void bmx_TheoraVideoClip_setAutoRestart(TheoraVideoClip * clip, int restart) {
	clip->setAutoRestart(restart);
}

int bmx_TheoraVideoClip_getAutoRestart(TheoraVideoClip * clip) {
	return clip->getAutoRestart();
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void * bmx_TheoraVideoFrame_getBuffer(TheoraVideoFrame * frame) {
	return frame->getBuffer();
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MaxTheoraDataSource * bmx_TheoraDataSource_create(BBObject * handle) {
	return new MaxTheoraDataSource(handle);
}

void bmx_TheoraDataSource_free(MaxTheoraDataSource * source) {
	delete source;
}

