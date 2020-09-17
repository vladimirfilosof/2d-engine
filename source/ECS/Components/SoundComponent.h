#ifndef SOUND_H
#define SOUND_H

#include "../ECS.h"
#include <SDL2/SDL_mixer.h>
#include <map>
#include <string>

//value of volume must be ranged from 0 to 128

class SoundComponent : public Component
{
public:
	SoundComponent();
	~SoundComponent();

	void add_sample(const std::string key, const std::string file_path, int volume);
	void add_music(const std::string key, const std::string file_path, int volume);

	void change_sample_vol(const std::string key, int volume);
	void change_music_vol(const std::string key, int volume);

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

	std::map<std::string, sample> Sample;
	std::map<std::string, music> Music;
};

#endif
