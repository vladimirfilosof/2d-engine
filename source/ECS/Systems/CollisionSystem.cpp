#include "CollisionSystem.h"

#ifdef DEBUG
	#include <iostream>
	#include <chrono>
#endif

CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: CollisionSystem destuctor calling" << std::endl;
#endif
}

void CollisionSystem::update()
{
	std::vector<Entity*>& entities = manager->get_entities();
	for (register int i = 0 ; i < static_cast<int>(entities.size()) - 1 ; i++)
	{
		if (entities[i]->isActive && entities[i]->has_component<ColliderComponent>())
		{
			TransformComponent& tc1 = entities[i]->get_component<TransformComponent>();
			ColliderComponent& cc1 = entities[i]->get_component<ColliderComponent>();
			for (unsigned register int j = i + 1 ; j < entities.size() ; j++)
			{
				if (entities[j]->isActive && entities[j]->has_component<ColliderComponent>())
				{
					ColliderComponent& cc2 = entities[j]->get_component<ColliderComponent>();
					TransformComponent& tc2 = entities[j]->get_component<TransformComponent>();
					
					// Collisions checking on next step of moving
					SDL_Rect Dtc_x1 = tc1.get_rect();
					SDL_Rect Dtc_x2 = tc2.get_rect();
					SDL_Rect Dtc_y1 = tc1.get_rect();
					SDL_Rect Dtc_y2 = tc2.get_rect();

					PhysicComponent* pc1 = nullptr;
					PhysicComponent* pc2 = nullptr;

					if (entities[i]->has_component<PhysicComponent>())
					{
						next_step(entities[i], Dtc_x1, Dtc_y1);
						pc1 = &entities[i]->get_component<PhysicComponent>();
					}
					if (entities[j]->has_component<PhysicComponent>())
					{
						next_step(entities[j], Dtc_x2, Dtc_y2);
						pc2 = &entities[j]->get_component<PhysicComponent>();
					}
					
					// Check x-asix collision	
					if (Collision::AABB(Dtc_x1, Dtc_x2))
					{
						cc1.x_axis = true;
						cc2.x_axis = true;
						if (pc1 != nullptr)
						{
							if (pc1->direction().x() > 0)
							{
								cc1.right = true;
								cc2.left = true;
							}
							if (pc1->direction().x() < 0)
							{
								cc1.left = true;
								cc2.right = true;
							}
						}
						else if (pc2 != nullptr)
						{
							if (pc2->direction().x() > 0)
							{
								cc2.right = true;
								cc1.left = true;
							}
							if (pc2->direction().x() < 0)
							{
								cc2.left = true;
								cc1.right = true;
							}
						}
					}

					// Check y-asix collision
					if (Collision::AABB(Dtc_y1, Dtc_y2))
					{
						cc1.y_axis = true;
						cc2.y_axis = true;
						if (pc1 != nullptr)
						{
							if (pc1->direction().y() > 0)
							{
								cc1.bottom = true;
								cc2.top = true;
							}
							if (pc1->direction().x() < 0)
							{
								cc1.top = true;
								cc2.bottom = true;
							}
						}
						else if (pc2 != nullptr)
						{
							if (pc2->direction().x() > 0)
							{
								cc2.bottom = true;
								cc1.top = true;
							}
							if (pc2->direction().x() < 0)
							{
								cc2.top = true;
								cc1.bottom = true;
							}
						}
					}

				//	handling_collision(entities[i], entities[j]);
					
					if (cc1.x_axis || cc1.y_axis) 
					{
						cc1.update(cc2.Tag(), entities[j]);
						cc2.update(cc1.Tag(), entities[i]);
					}

					// zeroize collision result for next step
					entities[i]->get_component<ColliderComponent>().zeroize();
					entities[j]->get_component<ColliderComponent>().zeroize();

				}
			}
		}
	}
}

void CollisionSystem::next_step(Entity* entity, SDL_Rect& Dtc_x, SDL_Rect& Dtc_y)
{
	PhysicComponent& pc = entity->get_component<PhysicComponent>();
	SDL_Rect buf_x = Dtc_x;
	SDL_Rect buf_y = Dtc_y;

	if (pc.direction().x() != 0)
	{
		Dtc_x.x += pc.direction().x() * pc.speed().x() * DeltaTime::delta;
		if (buf_x.x == Dtc_x.x)
		{
			Dtc_x.x += pc.direction().x();
		}
	}
	if (pc.direction().y() != 0)
	{
		Dtc_y.y += pc.direction().y() * pc.speed().y() * DeltaTime::delta;
		if (buf_y.y == Dtc_y.y)
		{
			Dtc_y.y += pc.direction().y();
		}
	}

}

