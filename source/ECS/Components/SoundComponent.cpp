#include "SoundComponent.h"

SoundComponent::SoundComponent(){}

SoundComponent::~SoundComponent(){}

void SoundComponent::add_sample(const char* key, const char* file_path, int volume)
{
	sample s;
	s.Chunk() = Mix_LoadWAV(file_path);
	s.Volume() = volume;
	Sample[key] = s;
}

void SoundComponent::add_music(const char* key, const char* file_path, int volume)
{
	music m;
	m.Music() = Mix_LoadMUS(file_path);
	m.Volume() = volume;
	Music[key] = m;
}

void SoundComponent::change_sample_vol(const char* key, int volume)
{
	std::map<const char*, sample> :: iterator it;
	it = Sample.find(key);
	if (it == Sample.end()) return;

	it->second.Volume() = volume;
	Mix_VolumeChunk(it->second.Chunk(), volume);
}

void SoundComponent::change_music_vol(const char* key, int volume)
{
	std::map<const char*, music> :: iterator it;
	it = Music.find(key);
	if (it == Music.end()) return;

	it->second.Volume() = volume;
}

void SoundComponent::play_sample(const char* key)
{
	std::map<const char*, sample> :: iterator it;
	it = Sample.find(key);
	if (it == Sample.end()) return;

	Mix_PlayChannel(-1, it->second.Chunk(), 0);
}

