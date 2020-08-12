#include "Engine.h"
#include <chrono>

int main()
{
// Initialize SDL, creating window and renderer
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 300, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

// This variable responsible for exiting the program
	bool isWork = true;

	SDL_Event event;

// Some variables for delta_time calculating
	std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff;
	double delta;

	EntityManager manager;
	Entity& object = manager.add_entity();
	object.add_component<TransformComponent>(100, 100, 100, 100);
	object.add_component<BoxComponent>(renderer);
	object.add_component<PhysicComponent>(&delta, 500, 500);

	while (isWork)
	{
// Calculate delta time
		diff = end - begin;
		delta = diff.count();
		begin = std::chrono::system_clock::now();

// Clear renderer
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

// Check events
		manager.update();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						isWork = false;
						break;
					case SDLK_UP:
						object.get_component<PhysicComponent>().direction().y() = -1;
						break;
					case SDLK_LEFT:
						object.get_component<PhysicComponent>().direction().x() = -1;
						break;
					case SDLK_DOWN:
						object.get_component<PhysicComponent>().direction().y() = 1;
						break;
					case SDLK_RIGHT:
						object.get_component<PhysicComponent>().direction().x() = 1;
						break;
				}
			}
			if (event.type == SDL_KEYUP)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						isWork = false;
						break;
					case SDLK_UP:
						object.get_component<PhysicComponent>().direction().y() = 0;
						break;
					case SDLK_LEFT:
						object.get_component<PhysicComponent>().direction().x() = 0;
						break;
					case SDLK_DOWN:
						object.get_component<PhysicComponent>().direction().y() = 0;
						break;
					case SDLK_RIGHT:
						object.get_component<PhysicComponent>().direction().x() = 0;
						break;
				}
			}

		}

		manager.draw();
// Update renderer
		SDL_RenderPresent(renderer);
		end = std::chrono::system_clock::now();
	}

// Free memory
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
