#include "PhysicSystem.h"

PhysicSystem::PhysicSystem()
{
}

PhysicSystem::~PhysicSystem()
{
}

void PhysicSystem::update()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: PhysicSystem begin" << std::endl;
#endif

	for (auto& item : entities)
	{
		if (item->has_component<TransformComponent>() && item->has_component<PhysicComponent>())
		{
			PhysicComponent& pc = item->get_component<PhysicComponent>();
			pc.direction().normalize();
			item->get_component<TransformComponent>().coords() += pc.direction() * pc.speed() * DeltaTime::delta;
		}
	}
#ifdef DEBUG
	std::cout << "[DEBUG]: PhysicSystem end" << std::endl;
#endif

}
