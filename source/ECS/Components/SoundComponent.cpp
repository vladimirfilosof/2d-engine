#include "SoundComponent.h"

SoundComponent::SoundComponent(){}

SoundComponent::~SoundComponent(){}

void SoundComponent::add_sample(const std::string key, const std::string file_path, int volume)
{
	sample s;
	s.Chunk() = Mix_LoadWAV(file_path.c_str());
	s.Volume() = volume;
	Sample[key] = s;
}

void SoundComponent::add_music(const std::string key, const std::string file_path, int volume)
{
	music m;
	m.Music() = Mix_LoadMUS(file_path.c_str());
	m.Volume() = volume;
	Music[key] = m;
}

void SoundComponent::change_sample_vol(const std::string key, int volume)
{
	std::map<std::string, sample> :: iterator it;
	it = Sample.find(key);
	if (it == Sample.end())
		return;

	it->second.Volume() = volume;
}

void SoundComponent::change_music_vol(const std::string key, int volume)
{
	std::map<std::string, music> :: iterator it;
	it = Music.find(key);
	if (it == Music.end())
		return;

	it->second.Volume() = volume;
}
