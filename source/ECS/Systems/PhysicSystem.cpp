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
#ifdef DEBUG
	std::cout << "\t[DEBUG]: PhysicSystem begins" << std::endl;
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
#endif
	std::vector<Entity*>& entities = manager->get_entities();
	for (auto& item : entities)
	{
		if (!item->isActive) continue;
		if (item->has_component<PhysicComponent>() && item->has_component<TransformComponent>())
		{
			PhysicComponent& pc = item->get_component<PhysicComponent>();
			pc.direction().normalize();
			item->get_component<TransformComponent>().coords() += pc.direction() * pc.speed() * DeltaTime::delta;
		}
	}
#ifdef DEBUG
	std::chrono::system_clock::time_point e = std::chrono::system_clock::now();
	std::chrono::duration<double> d = e - b;
	std::cout << "\t[DEBUG]: PhysicSystem ends with duration: " << std::to_string(d.count()) << std::endl;
#endif

}
