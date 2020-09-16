#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "../ECS.h"
#include "../Components/ColorComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/BoxComponent.h"
#include <SDL2/SDL.h>
#include <vector>
#include <chrono>

class RenderSystem : public System
{
private:
	SDL_Window* window;
public:
	static SDL_Renderer* renderer;
	RenderSystem();
	~RenderSystem();

	void update();
};

#endif 
