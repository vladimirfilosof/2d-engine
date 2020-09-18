#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include "../ECS.h"
#include "../Components/SoundComponent.h"
#include <iostream>

class SoundSystem : public System
{
public:
	SoundSystem(int frequency, Uint16 format, int channels, int chunksize);
	~SoundSystem();

	void update();

private:
};

#endif
