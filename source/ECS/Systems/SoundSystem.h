#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include "../ECS.h"
#include "../Components/SoundComponent.h"

class SoundSystem
{
public:
	SoundSystem(int frequency, Uint16 format, int channels, int chunksize);
	~SoundSystem();

private:
};

#endif
