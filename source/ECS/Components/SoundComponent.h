#ifndef SOUND_H
#define SOUND_H

#include "../ECS.h"
#include <SDL2/SDL_mixer.h>
#include <map>

//value of volume must be ranged from 0 to 128

class SoundComponent : public Component
{
public:
	SoundComponent();
	~SoundComponent();

	void add_sample(const char* key, const char* file_path, int volume);
	void add_music(const char* key, const char* file_path, int volume);

	void change_sample_vol(const char* key, int volume);
	void change_music_vol(const char* key, int volume);

	void play_sample(const char* key);
	void play_music(const char* key);

private:
	class sample
	{
	public:
		sample(){}
		~sample(){}
	
		Mix_Chunk*& Chunk(){ return chunk; }
		int& Volume(){ return volume; }
	private:
		Mix_Chunk* chunk;
		int volume; 
	};

	class music
	{
	public:
		music(){}
		~music(){}

		Mix_Music*& Music(){ return mus; }
		int& Volume(){ return volume; }
	private:
		Mix_Music* mus;
		int volume;
	};

	std::map<const char*, sample> Sample;
	std::map<const char*, music> Music;
};

#endif
