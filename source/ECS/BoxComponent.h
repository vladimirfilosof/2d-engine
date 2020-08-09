#ifndef BOXCOMPONENT_H
#define BOXCOMPONENT_H

#include "ECS.h"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include <iostream>

class BoxComponent : public Component
{
private:
	SDL_Renderer* renderer;
	SDL_Rect rect;
public:
	BoxComponent(SDL_Renderer* renderer);
	BoxComponent(SDL_Renderer* renderer, int w, int h, int x, int y);
	~BoxComponent();

	void init();
	void draw();
	void update();
};

#endif
