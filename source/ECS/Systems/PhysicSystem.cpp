#include "PhysicSystem.h"

#ifdef DEBUG
	#include <iostream>
	#include <chrono>
#endif

PhysicSystem::PhysicSystem()
{
}

PhysicSystem::~PhysicSystem()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: PhysicSystem destructor calling" << std::endl;
#endif
}

void PhysicSystem::update()
{
	std::vector<Entity*>& entities = manager->get_entities();
	for (auto& item : entities)
	{
		if (!item->isActive) continue;
		if (item->has_component<PhysicComponent>() && item->has_component<TransformComponent>())
		{
			PhysicComponent& pc = item->get_component<PhysicComponent>();
			pc.direction().normalize();
			item->get_component<TransformComponent>().coords() += pc.direction() * pc.speed() * DBHelper::delta;
		}
	}
}
