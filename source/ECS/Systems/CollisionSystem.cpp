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

					PhysicComponent* pc1 = nullptr;
					PhysicComponent* pc2 = nullptr;

					ColliderComponent& cc1 = entities[i]->get_component<ColliderComponent>();
					ColliderComponent& cc2 = entities[j]->get_component<ColliderComponent>();

					next_step(entities[i], pc1, Dtc_x1, Dtc_y1);
					next_step(entities[j], pc2, Dtc_x2, Dtc_y2);
					
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
	ColliderComponent& cc1 = e1->get_component<ColliderComponent>();
	ColliderComponent& cc2 = e2->get_component<ColliderComponent>();

	PhysicComponent* pc1 = nullptr;
	PhysicComponent* pc2 = nullptr;
	
	if (cc1.x_axis || cc1.y_axis)
	{
		if (cc1.Tag() == "inc_area")
		{
			if (e2->get_component<TransformComponent>().size().w() < 300)
			{
				e2->get_component<TransformComponent>().size().w()++;
				e2->get_component<TransformComponent>().size().h()++;
				e2->get_component<TransformComponent>().coords().x()--;
				e2->get_component<TransformComponent>().coords().y()--;
			}
		}
		else if (cc2.Tag() == "inc_area")
		{
			if (e1->get_component<TransformComponent>().size().w() < 300)
			{
				e1->get_component<TransformComponent>().size().w()++;
				e1->get_component<TransformComponent>().size().h()++;
				e1->get_component<TransformComponent>().coords().x()--;
				e1->get_component<TransformComponent>().coords().y()--;
			}
		}	
		else if (cc1.Tag() == "dec_area")
		{
			if (e2->get_component<TransformComponent>().size().w() > 100)
			{
				e2->get_component<TransformComponent>().size().w()--;
				e2->get_component<TransformComponent>().size().h()--;
				e2->get_component<TransformComponent>().coords().x()++;
				e2->get_component<TransformComponent>().coords().y()++;
			}
		}
		else if (cc2.Tag() == "dec_area")
		{
			if (e1->get_component<TransformComponent>().size().w() > 100)
			{
				e1->get_component<TransformComponent>().size().w()--;
				e1->get_component<TransformComponent>().size().h()--;
				e1->get_component<TransformComponent>().coords().x()++;
				e1->get_component<TransformComponent>().coords().y()++;
			}
		}	
		else 
		{
			if (e1->has_component<PhysicComponent>())
			{
				pc1 = &e1->get_component<PhysicComponent>();
				if (cc1.x_axis)
				{
					pc1->direction().x() = 0;
				}
		
				if (cc1.y_axis)
				{
					pc1->direction().y() = 0;
				}
			}

			if (e2->has_component<PhysicComponent>())
			{
				pc2 = &e1->get_component<PhysicComponent>();
				if (cc2.x_axis)
				{
					pc2->direction().x() = 0;
				}
		
				if (cc2.y_axis)
				{
					pc2->direction().y() = 0;
				}
			}
		}
	}
}

void CollisionSystem::next_step(Entity* entity, PhysicComponent*& pc, TransformComponent& Dtc_x, TransformComponent& Dtc_y)
{
	if (entity->has_component<PhysicComponent>())
	{
		pc = &entity->get_component<PhysicComponent>();
		Dtc_x.coords().x() += pc->direction().x() * pc->speed().x() * (*delta);
		Dtc_y.coords().y() += pc->direction().y() * pc->speed().y() * (*delta);
	}
}

