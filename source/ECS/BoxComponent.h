#ifndef BOXCOMPONENT_H
#define BOXCOMPONENT_H

#include "ECS.h"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include "TransformComponent.h"

class BoxComponent : public Component
{
private:
	SDL_Renderer* renderer;
	SDL_Rect rect;
	TransformComponent* transform;
public:
	BoxComponent(SDL_Renderer* renderer);
	~BoxComponent();

	void init();
	void draw();
	void update();
};

#endif
