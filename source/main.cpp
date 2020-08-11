#include "Engine.h"
#include <chrono>
#include "ECS/Vector2D.h"

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
	object.add_component<BoxComponent>(renderer, 100, 100, 0, 0);

	while (isWork)
	{
// Calculate delta time
		diff = end - begin;
		delta = diff.count();

// Clear renderer
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

// Check events
		manager.update();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isWork = false;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				isWork = false;
			}
		}

		manager.draw();
// Update renderer
		SDL_RenderPresent(renderer);
	}

// Free memory
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
