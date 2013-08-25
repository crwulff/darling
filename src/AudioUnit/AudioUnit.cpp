#include "AudioUnit.h"
#include "AudioUnitALSA.h"
#include <log.h>
#include <trace.h>
#include <alsa/asoundlib.h>
#include <CoreServices/MacErrors.h>

OSStatus AudioUnitInitialize(AudioUnit inUnit)
{
	return inUnit->init();
}

OSStatus AudioUnitUninitialize(AudioUnit inUnit)
{
	return inUnit->deinit();
}

OSStatus AudioUnitAddRenderNotify(AudioUnit inUnit, AURenderCallback inProc, void* opaque)
{
	STUB();
	return unimpErr;
}

OSStatus AudioUnitRemoveRenderNotify(AudioUnit inUnit, AURenderCallback inProc, void* opaque)
{
	STUB();
	return unimpErr;
}

OSStatus AudioUnitRender(AudioUnit inUnit, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inOutputBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData)
{
	STUB();
	return unimpErr;
}

OSStatus AudioUnitReset(AudioUnit inUnit, AudioUnitScope inScope, AudioUnitElement inElement)
{
	STUB();
	return noErr;
}

OSStatus AudioUnitGetProperty(AudioUnit inUnit, AudioUnitPropertyID inID, AudioUnitScope inScope, AudioUnitElement inElement, void* outData, UInt32 *ioDataSize)
{
	return inUnit->getProperty(inID, inScope, inElement, outData, ioDataSize);
}

OSStatus AudioUnitGetPropertyInfo(AudioUnit inUnit, AudioUnitPropertyID inID, AudioUnitScope inScope, AudioUnitElement inElement, UInt32 *outDataSize, Boolean *outWritable)
{
	return inUnit->getPropertyInfo(inID, inScope, inElement, outDataSize, outWritable);
}

OSStatus AudioUnitSetProperty(AudioUnit inUnit, AudioUnitPropertyID inID, AudioUnitScope inScope, AudioUnitElement inElement, const void *inData, UInt32 inDataSize)
{
	return inUnit->setProperty(inID, inScope, inElement, inData, inDataSize);
}

OSStatus AudioOutputUnitStart(AudioUnit inUnit)
{
	return inUnit->start();
}

OSStatus AudioOutputUnitStop(AudioUnit inUnit)
{
	return inUnit->stop();
}


