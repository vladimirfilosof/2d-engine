#include "SoundSystem.h"

SoundSystem::SoundSystem(int frequency, Uint16 format, int channels, int chunksize)
{
	if (Mix_OpenAudio(frequency, format, channels, chunksize < 0))
		throw std::runtime_error("[SoundSystem] <SoundSystem>: Open sound mixer error");

}

SoundSystem::~SoundSystem(){}
