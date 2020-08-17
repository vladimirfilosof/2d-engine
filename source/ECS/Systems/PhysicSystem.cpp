#include "PhysicSystem.h"

PhysicSystem::~PhysicSystem()
{}

void PhysicSystem::init()
{
	entities = manager->get_entities();
}

void PhysicSystem::update()
{
	for (auto& item : entities)
	{
		if (item->has_component<TransformComponent>() && item->has_component<PhysicComponent>())
		{
			item->get_component<PhysicComponent>().direction().normalize();
			item->get_component<TransformComponent>().coords() += item->get_component<PhysicComponent>().direction() * item->get_component<PhysicComponent>().speed() * (*delta);
		}
	}
}
