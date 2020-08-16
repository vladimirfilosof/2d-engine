#ifndef BOXCOMPONENT_H
#define BOXCOMPONENT_H

#include "../ECS.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class BoxComponent : public Component
{
private:
	SDL_Rect rect;
public:
	BoxComponent();
	~BoxComponent();

	void init();
};

#endif
