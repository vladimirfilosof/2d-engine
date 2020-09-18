#include "Engine.h"
#include <SDL2/SDL.h>

int main()
{
// Initialize SDL, creating window and renderer
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		exit (1);
	}

// This variable responsible for exiting the program
	bool isWork = true;

	SDL_Event event;

	srand(time(NULL));

// Class for calculating delta time 
	DeltaTime dt;

	EntityManager manager;

	Entity& object = manager.add_entity();

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

	Entity& damage_area = manager.add_entity();
	damage_area.add_component<TransformComponent>(-100, 0, 100, 100);
	damage_area.add_component<ColorComponent>(255, 0, 255, 0);
	damage_area.add_component<BoxComponent>();
	damage_area.add_component<ColliderComponent>("damage_area");

	manager.add_system<CollisionSystem>();
	manager.add_system<PhysicSystem>();
	manager.add_system<CameraSystem>(&object, 800, 800);
	manager.add_system<LifeSystem>([](Entity* entity)
			{
				if (entity->has_component<HealthComponent>())
				{
					if (entity->get_component<HealthComponent>().health() <= 0)
					{
						if (entity->has_component<SpriteComponent>())
						{
							entity->isActive = false;
						}
					}
				}
			});
	manager.add_system<RenderSystem>();
	manager.add_system<SoundSystem>(44100, MIX_DEFAULT_FORMAT, 2, 4096);

	object.add_component<SoundComponent>();
	object.add_component<TransformComponent>(600, 600, 100, 100);
	object.add_component<ColliderComponent>("Player");
	object.add_component<ColorComponent>(0, 0, 255, 0);
	object.add_component<PhysicComponent>(500, 500);
	object.add_component<SpriteComponent>();
	object.add_component<HealthComponent>(10);
	object.get_component<SpriteComponent>().add_animation("../texture/dino_peace.png", 0, 1);
	object.get_component<SpriteComponent>().add_animation("../texture/dino_run.png", 0.2, 2);

	object.get_component<SoundComponent>().add_sample("wall_hit", "../sound/kick.wav", 128);

	object.get_component<ColliderComponent>().add_collisionEvent("inc_area",[](Entity* e1, Entity* e2)
			{
				if (e1->has_component<TransformComponent>())
				{
					if (e1->get_component<TransformComponent>().size().w() < 300)
					{
						e1->get_component<TransformComponent>().size().w() += 200 * DeltaTime::delta;
						e1->get_component<TransformComponent>().size().h() += 200 * DeltaTime::delta;
						e1->get_component<TransformComponent>().coords().x() -= 50 * DeltaTime::delta;
						e1->get_component<TransformComponent>().coords().y() -= 50 * DeltaTime::delta;
					}
				}
			});
	object.get_component<ColliderComponent>().add_collisionEvent("dec_area",[](Entity* e1, Entity* e2)
			{
				if (e1->has_component<TransformComponent>())
				{
					if (e1->get_component<TransformComponent>().size().w() > 100)
					{
						e1->get_component<TransformComponent>().size().w() -= 200 * DeltaTime::delta;
						e1->get_component<TransformComponent>().size().h() -= 200 * DeltaTime::delta;
						e1->get_component<TransformComponent>().coords().x() += 50 * DeltaTime::delta;
						e1->get_component<TransformComponent>().coords().y() += 50 * DeltaTime::delta;
					}
				}
			});
	object.get_component<ColliderComponent>().add_collisionEvent("Wall",[](Entity* e1, Entity* e2)
			{
				if (e1->has_component<ColliderComponent>() && e1->has_component<PhysicComponent>())
				{
					if (e1->get_component<ColliderComponent>().x_axis) e1->get_component<PhysicComponent>().direction().x() = 0;
					if (e1->get_component<ColliderComponent>().y_axis) e1->get_component<PhysicComponent>().direction().y() = 0;
					
					if (e1->has_component<SoundComponent>())
					{
						e1->get_component<SoundComponent>().play_sample("wall_hit");
					}
				}

			
			});
	object.get_component<ColliderComponent>().add_collisionEvent("rotate_area",[](Entity* e1, Entity* e2)
			{
				if (e1->has_component<SpriteComponent>())
				{
					e1->get_component<SpriteComponent>().angle() += 360;
				}
			});
	object.get_component<ColliderComponent>().add_collisionEvent("run_area", [](Entity* e1, Entity* e2)
			{
				if (e2->has_component<TransformComponent>())
				{
					e2->get_component<TransformComponent>().coords().x() = rand()%800;
					e2->get_component<TransformComponent>().coords().y() = rand()%800;
				}
			});
	object.get_component<ColliderComponent>().add_collisionEvent("damage_area", [](Entity* e1, Entity* e2)
			{
				if (e1->has_component<HealthComponent>())
				{
					e1->get_component<HealthComponent>().add_damage(10);
					std::cout << e1->get_component<HealthComponent>().health() << std::endl;
				}
			});


	while (isWork)
	{
// Calculate delta time
		dt.begin();

// Check events
		manager.update();

		if (object.has_component<SpriteComponent>())	
		{
			if (object.get_component<PhysicComponent>().direction().x() != 0 || object.get_component<PhysicComponent>().direction().y() != 0)
			{
				object.get_component<SpriteComponent>().set_animation(1, false);
			}
			else
			{
				object.get_component<SpriteComponent>().set_animation(0, false);
			}
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
			if (object.has_component<SpriteComponent>()) object.get_component<SpriteComponent>().flip() = SDL_FLIP_NONE;
		}
		else if (state[SDL_SCANCODE_LEFT])
		{
			object.get_component<PhysicComponent>().direction().x() = -1;
			if (object.has_component<SpriteComponent>()) object.get_component<SpriteComponent>().flip() = SDL_FLIP_HORIZONTAL;
		}
		else
		{
			object.get_component<PhysicComponent>().direction().x() = 0;
		}

		if (state[SDL_SCANCODE_ESCAPE]) isWork = false;

		dt.end();
	}

// Free memory
	SDL_Quit();
	return 0;
}
