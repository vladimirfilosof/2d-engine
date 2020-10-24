#include "SoundSystem.h"

#ifdef DEBUG
	#include <iostream>
	#include <chrono>
#endif

SoundSystem::SoundSystem(int frequency, Uint16 format, int channels, int chunksize)
{
	if (Mix_OpenAudio(frequency, format, channels, chunksize) < 0)
		throw std::runtime_error("[SoundSystem] <SoundSystem>: Open sound mixer error");
}

SoundSystem::~SoundSystem()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: SoundSystem destructor calling" << std::endl;
#endif
}

void SoundSystem::update()
{
#ifdef DEBUG
	std::cout << "\t[DEBUG]: SoundSystem begins" << std::endl;
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
#endif

#ifdef DEBUG
	std::chrono::system_clock::time_point e = std::chrono::system_clock::now();
	std::chrono::duration<double> d = e - b;
	std::cout << "\t[DEBUG]: SoundSystem ends with duration: " << std::to_string(d.count()) << std::endl;
#endif
}
