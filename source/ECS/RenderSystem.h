#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "ECS.h"
#include "TransformComponent.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>
#include <vector>

class RenderSystem : public System
{
private:
	SDL_Renderer* renderer;
	std::vector<Entity*> entities;
public:
	RenderSystem(SDL_Renderer* renderer);
	~RenderSystem();
	void init();
	void update();
};

#endif 
