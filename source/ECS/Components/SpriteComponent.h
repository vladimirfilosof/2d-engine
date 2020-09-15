#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "../ECS.h"
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <chrono>

struct Animation
{
	SDL_Texture* texture;
	double SPF;
	int frame_w;
	int frame_h;
	int width;
	int height;
};

class SpriteComponent : public Component
{
private:
	int size;
	SDL_Rect rect;
	bool isLocked;
	SDL_RendererFlip fp;
	double ang;

	std::chrono::system_clock::time_point begin;
	std::chrono::system_clock::time_point end;
public:
	Animation* animation;
	int current_animation;
	
	SpriteComponent();
	~SpriteComponent();

	void init();

	void update();

	void add_animation(const char* texture_path, const double& SPF, const int& frame_count);

	bool isAnimation(){return size == 0 ? false : true;}

	SDL_Rect& get_rect(){return rect;}

	SDL_RendererFlip& flip(){return fp;}

	double& angle(){return ang;}

	SDL_Texture* get_texture(){return isAnimation() ? animation[current_animation].texture : nullptr;}

	void set_animation(const int& animation_number, const bool& isLocked);

};

#endif
