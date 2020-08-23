#include "CollisionSystem.h"

CollisionSystem::CollisionSystem()
{
}

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
					TransformComponent Dtc1 = tc1;
					TransformComponent Dtc2 = tc2;

					// check collision on x-asix
					if (entities[i]->has_component<PhysicComponent>())
					{
						Dtc1.coords().x() += 
							entities[i]->get_component<PhysicComponent>().direction().x();
					}

					if (entities[j]->has_component<PhysicComponent>())
					{
						Dtc2.coords().x() += 
							entities[j]->get_component<PhysicComponent>().direction().x();
					}

					if (Collision::AABB(Dtc1, Dtc2))
					{
						entities[i]->get_component<ColliderComponent>().x_axis = true;
						std::cout << "x" << std::endl;
					}
					
					if (entities[i]->has_component<PhysicComponent>())
					{
						Dtc1.coords().x() -= 
							entities[i]->get_component<PhysicComponent>().direction().x();
					}

					if (entities[j]->has_component<PhysicComponent>())
					{
						Dtc2.coords().x() -= 
							entities[j]->get_component<PhysicComponent>().direction().x();
					}

					// check collision on y-asix
					if (entities[i]->has_component<PhysicComponent>())
					{
						Dtc1.coords().y() += 
							entities[i]->get_component<PhysicComponent>().direction().y();
					}

					if (entities[j]->has_component<PhysicComponent>())
					{
						Dtc2.coords().y() += 
							entities[j]->get_component<PhysicComponent>().direction().y();
					}

					if (Collision::AABB(Dtc1, Dtc2))
					{
						entities[i]->get_component<ColliderComponent>().y_axis = true;
						std::cout << "y" << std::endl;
					}

					if (entities[i]->has_component<PhysicComponent>())
					{
						Dtc1.coords().y() -= 
							entities[i]->get_component<PhysicComponent>().direction().y();
					}

					if (entities[j]->has_component<PhysicComponent>())
					{
						Dtc2.coords().y() -= 
							entities[j]->get_component<PhysicComponent>().direction().y();
					}

					handling_collision(entities[i], entities[j]);

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

