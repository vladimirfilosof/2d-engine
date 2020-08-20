#include "CollisionSystem.h"

CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::init()
{
	entities = manager->get_entities();
}

void CollisionSystem::update()
{
	for (unsigned register int i = 0 ; i < entities.size() - 1 ; i++)
	{
		if (entities[i]->has_component<ColliderComponent>())
		{
			TransformComponent& tc = entities[i]->get_component<TransformComponent>();
			for (unsigned register int j = i + 1 ; j < entities.size() ; j++)
			{
				if (entities[j]->has_component<ColliderComponent>())
				{
					if (Collision::AABB(tc, entities[j]->get_component<TransformComponent>()))
					{
						if (entities[i]->has_component<PhysicComponent>()) entities[i]->get_component<PhysicComponent>().direction().zeroize();
						if (entities[j]->has_component<PhysicComponent>()) entities[j]->get_component<PhysicComponent>().direction().zeroize();
					}
				}
			}
		}
	}
}
