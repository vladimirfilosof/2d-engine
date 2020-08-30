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

	srand(time(NULL));

// Some variables for delta_time calculating
	std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff;
	double delta;

	EntityManager manager;
	Entity& object = manager.add_entity();
	object.add_component<TransformComponent>(600, 600, 100, 100);
	object.add_component<ColliderComponent>("Player");
	object.add_component<ColorComponent>(0, 0, 255, 0);
	object.add_component<PhysicComponent>(500, 500);
	object.add_component<SpriteComponent>(renderer);
	object.get_component<SpriteComponent>().add_animation("../texture/dino_peace.png", 0, 1);
	object.get_component<SpriteComponent>().add_animation("../texture/dino_run.png", 0.2, 2);
	object.get_component<ColliderComponent>().add_collisionEvent("inc_area",[](Entity* e1, Entity* e2)
			{
				if (e1->get_component<TransformComponent>().size().w() < 300)
				{
					e1->get_component<TransformComponent>().size().w()++;
					e1->get_component<TransformComponent>().size().h()++;
					e1->get_component<TransformComponent>().coords().x()--;
					e1->get_component<TransformComponent>().coords().y()--;
				}
			});
	object.get_component<ColliderComponent>().add_collisionEvent("dec_area",[](Entity* e1, Entity* e2)
			{
				if (e1->get_component<TransformComponent>().size().w() > 100)
				{
					e1->get_component<TransformComponent>().size().w()--;
					e1->get_component<TransformComponent>().size().h()--;
					e1->get_component<TransformComponent>().coords().x()++;
					e1->get_component<TransformComponent>().coords().y()++;
				}
			});
	object.get_component<ColliderComponent>().add_collisionEvent("Wall",[](Entity* e1, Entity* e2)
			{
				if (e1->get_component<ColliderComponent>().x_axis) e1->get_component<PhysicComponent>().direction().x() = 0;
				if (e1->get_component<ColliderComponent>().y_axis) e1->get_component<PhysicComponent>().direction().y() = 0;
			});
	object.get_component<ColliderComponent>().add_collisionEvent("rotate_area",[](Entity* e1, Entity* e2)
			{
				e1->get_component<SpriteComponent>().angle() += 20;
			});
	object.get_component<ColliderComponent>().add_collisionEvent("run_area", [](Entity* e1, Entity* e2)
			{
				e2->get_component<TransformComponent>().coords().x() = rand()%800;
				e2->get_component<TransformComponent>().coords().y() = rand()%800;
			});



	Entity& wall = manager.add_entity();
	wall.add_component<TransformComponent>(100, 100, 80, 80);
	wall.add_component<BoxComponent>();
	wall.add_component<ColliderComponent>("Wall");

	Entity& inc_area = manager.add_entity();
	inc_area.add_component<TransformComponent>(0, 700, 100, 100);
	inc_area.add_component<ColorComponent>(0, 255, 0, 0);
	inc_area.add_component<BoxComponent>();
	inc_area.add_component<ColliderComponent>("inc_area");

	Entity& dec_area = manager.add_entity();
	dec_area.add_component<TransformComponent>(700, 700, 100, 100);
	dec_area.add_component<ColorComponent>(255, 0, 0, 0);
	dec_area.add_component<BoxComponent>();
	dec_area.add_component<ColliderComponent>("dec_area");

	Entity& rotate_area = manager.add_entity();
	rotate_area.add_component<TransformComponent>(350,350,100,100);
	rotate_area.add_component<ColorComponent>(255, 255, 0, 0);
	rotate_area.add_component<BoxComponent>();
	rotate_area.add_component<ColliderComponent>("rotate_area");

	Entity& run_area = manager.add_entity();
	run_area.add_component<TransformComponent>(-100, -100, 50, 50);
	run_area.add_component<ColorComponent>(0, 255, 255, 0);
	run_area.add_component<BoxComponent>();
	run_area.add_component<ColliderComponent>("run_area");

	manager.add_system<RenderSystem>(renderer);
	manager.add_system<CollisionSystem>(&delta);
	manager.add_system<PhysicSystem>(&delta);
	manager.add_system<CameraSystem>(&object, 800, 800);

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
			object.get_component<SpriteComponent>().flip() = SDL_FLIP_NONE;
		}
		else if (state[SDL_SCANCODE_LEFT])
		{
			object.get_component<PhysicComponent>().direction().x() = -1;
			object.get_component<SpriteComponent>().flip() = SDL_FLIP_HORIZONTAL;
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
