#ifndef FPS_H
#define FPS_H

#include "DeltaTime.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class fps
{
public:
	fps(const char* font_path, int font_size);
	~fps();
	void print_fps();

private:
	TTF_Font* font;
	SDL_Color color;
	int font_size;
};

#endif
