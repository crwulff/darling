#ifndef AUCOMPONENTINTERNAL_H
#define AUCOMPONENTINTERNAL_H
#include "AudioUnit.h"
#include <CoreServices/ComponentsInternal.h>
#include <alsa/asoundlib.h>
#include "AudioUnitBase.h"

class AudioUnitALSA : public AudioUnitComponent
{
private:
	AudioUnitALSA(int cardIndex, char* cardName);
public:
	static AudioUnitComponent* create(int cardIndex);
	virtual ~AudioUnitALSA();
	
	int cardIndex() const override { return m_cardIndex; }

	OSStatus init() override;
	OSStatus deinit() override;

	OSStatus start() override;
	OSStatus stop() override;
private:
	int m_cardIndex;
	char* m_cardName;
	snd_pcm_t *m_pcmOutput, *m_pcmInput;
};

#endif

