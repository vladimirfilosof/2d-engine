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

#include "../../fps.h"

class RenderSystem : public System
{
private:
	SDL_Window* window;
	fps* f;
	bool FPS_Status;
public:
	static SDL_Renderer* renderer;
	RenderSystem(const char* window_title, const int& position_x, const int& position_y, const int& width, const int& height, const Uint32& window_flags, const Uint32& renderer_flags);
	~RenderSystem();

	void update();

	void set_FPSStatus(bool status)
	{
		FPS_Status = status; 
		if (f == nullptr) 
		{
			f = new fps("../font/roboto.ttf", 24);
		}
	}
	bool get_FPSStatus(){return FPS_Status;}
};

#endif 
