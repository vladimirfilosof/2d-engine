#include "PhysicSystem.h"

PhysicSystem::~PhysicSystem()
{}

void PhysicSystem::update()
{
	for (auto& item : entities)
	{
		if (item->has_component<TransformComponent>() && item->has_component<PhysicComponent>())
		{
			PhysicComponent& pc = item->get_component<PhysicComponent>();
			pc.direction().normalize();
			item->get_component<TransformComponent>().coords() += pc.direction() * pc.speed() * (*delta);
		}
	}
}
