#include "CollisionSystem.h"

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::update()
{
	for (unsigned register int i = 0 ; i < entities.size() - 1 ; i++)
	{
		if (entities[i]->has_component<ColliderComponent>())
		{
			TransformComponent& tc1 = entities[i]->get_component<TransformComponent>();
			for (unsigned register int j = i + 1 ; j < entities.size() ; j++)
			{
				if (entities[j]->has_component<ColliderComponent>())
				{
					TransformComponent& tc2 = entities[j]->get_component<TransformComponent>();
					
					// Collisions checking on next step of moving
					TransformComponent Dtc_x1 = tc1;
					TransformComponent Dtc_x2 = tc2;
					TransformComponent Dtc_y1 = tc1;
					TransformComponent Dtc_y2 = tc2;


					if (entities[i]->has_component<PhysicComponent>())
					{
						PhysicComponent pc1 = entities[i]->get_component<PhysicComponent>();
						Dtc_x1.coords().x() += pc1.direction().x() * pc1.speed().x() * (*delta);
						Dtc_y1.coords().y() += pc1.direction().y() * pc1.speed().y() * (*delta);
					}

					if (entities[j]->has_component<PhysicComponent>())
					{
						PhysicComponent pc2 = entities[j]->get_component<PhysicComponent>();
						Dtc_x2.coords().x() += pc2.direction().x() * pc2.speed().x() * (*delta);
						Dtc_y2.coords().y() += pc2.direction().y() * pc2.speed().y() * (*delta);
					}
					
					// Check x-asix collision	
					if (Collision::AABB(Dtc_x1, Dtc_x2))
					{
						entities[i]->get_component<ColliderComponent>().x_axis = true;
						entities[j]->get_component<ColliderComponent>().x_axis = true;
						std::cout << "x" << std::endl;
					}

					// Check y-asix collision
					if (Collision::AABB(Dtc_y1, Dtc_y2))
					{
						entities[i]->get_component<ColliderComponent>().y_axis = true;
						entities[j]->get_component<ColliderComponent>().y_axis = true;
						std::cout << "y" << std::endl;
					}

					
					handling_collision(entities[i], entities[j]);

					// zeroize collision result for next step
					entities[i]->get_component<ColliderComponent>().zeroize();
					entities[j]->get_component<ColliderComponent>().zeroize();

				}
			}
		}
	}
}

void CollisionSystem::handling_collision(Entity* e1, Entity* e2)
{
	
	if (e1->has_component<PhysicComponent>())
	{
		if (e1->get_component<ColliderComponent>().x_axis)
		{
			e1->get_component<PhysicComponent>().direction().x() = 0;
		}
	
		if (e1->get_component<ColliderComponent>().y_axis)
		{
			e1->get_component<PhysicComponent>().direction().y() = 0;
		}
	}

	if (e2->has_component<PhysicComponent>())
	{
		if (e2->get_component<ColliderComponent>().x_axis)
		{
			e2->get_component<PhysicComponent>().direction().x() = 0;
		}
	
		if (e2->get_component<ColliderComponent>().y_axis)
		{
			e2->get_component<PhysicComponent>().direction().y() = 0;
		}
	}
}

