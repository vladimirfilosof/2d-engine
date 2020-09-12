#include "LifeSystem.h"

LifeSystem::LifeSystem()
{
}

LifeSystem::~LifeSystem()
{
}

void LifeSystem::update()
{
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
}
