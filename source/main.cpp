#include "Engine.h"
#include "ECS/Components/Components.h"
#include "ECS/Systems/Systems.h"
#include <SDL2/SDL.h>
#include <chrono>

int main()
{
// Initialize SDL, creating window and renderer
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
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
	object.add_component<TransformComponent>(600, 600, 100, 100);
	object.add_component<ColliderComponent>("Just rect");
	object.add_component<ColorComponent>(255, 0, 0, 0);
	object.add_component<PhysicComponent>(500, 500);
	object.add_component<SpriteComponent>(renderer);
	object.get_component<SpriteComponent>().add_animation("../texture/dino_peace.png", 0, 1);
	object.get_component<SpriteComponent>().add_animation("../texture/dino_run.png", 0.2, 2);

	Entity& test = manager.add_entity();
	test.add_component<TransformComponent>(100, 100, 80, 80);
	test.add_component<ColliderComponent>("Test");

	manager.add_system<RenderSystem>(renderer);
	manager.add_system<CollisionSystem>(&delta);
	manager.add_system<PhysicSystem>(&delta);
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

		if (object.get_component<PhysicComponent>().direction().x() != 0 || object.get_component<PhysicComponent>().direction().y() != 0)
		{
			object.get_component<SpriteComponent>().set_animation(1, false);
		}
		else
		{
			object.get_component<SpriteComponent>().set_animation(0, false);
		}
		while (SDL_PollEvent(&event))
		{
		}
		const Uint8* state = SDL_GetKeyboardState(NULL);

		if (state[SDL_SCANCODE_UP])
		{
			object.get_component<PhysicComponent>().direction().y() = -1;
		}
		else if (state[SDL_SCANCODE_DOWN])
		{
			object.get_component<PhysicComponent>().direction().y() = 1;
		}
		else
		{
			object.get_component<PhysicComponent>().direction().y() = 0;
		}

		if (state[SDL_SCANCODE_RIGHT])
		{
			object.get_component<PhysicComponent>().direction().x() = 1;
			object.get_component<SpriteComponent>().flip() = SDL_FLIP_HORIZONTAL;
		}
		else if (state[SDL_SCANCODE_LEFT])
		{
			object.get_component<PhysicComponent>().direction().x() = -1;
			object.get_component<SpriteComponent>().flip() = SDL_FLIP_NONE;
		}
		else
		{
			object.get_component<PhysicComponent>().direction().x() = 0;
		}

		if (state[SDL_SCANCODE_ESCAPE]) isWork = false;

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
