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
#include <cmath>

class RenderSystem : public System
{
private:
	SDL_Window* window;
public:
	static SDL_Renderer* renderer;
	RenderSystem(const char* window_title, const int& position_x, const int& position_y, const int& width, const int& height, const Uint32& window_flags, const Uint32& renderer_flags);
	~RenderSystem();

	void update();
};

#endif 
