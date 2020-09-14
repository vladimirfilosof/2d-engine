#include "LifeSystem.h"

LifeSystem::LifeSystem()
{
}

LifeSystem::~LifeSystem()
{
}

void LifeSystem::update()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: LifeSystem begin" << std::endl;
#endif


	for (auto& entity : entities)
	{
		if (entity->has_component<HealthComponent>())
		{
			if (entity->get_component<HealthComponent>().health() <= 0)
			{
				if (entity->has_component<SpriteComponent>())entity->remove_component<SpriteComponent>();
			}
		}
	}
#ifdef DEBUG
	std::cout << "[DEBUG]: LifeSystem end" << std::endl;
#endif

}
