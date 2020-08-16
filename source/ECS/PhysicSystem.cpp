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
		item->get_component<TransformComponent>().coords().x() += item->get_component<PhysicComponent>().direction().x() * item->get_component<PhysicComponent>().speedX() * (*delta);
		item->get_component<TransformComponent>().coords().y() += item->get_component<PhysicComponent>().direction().y() * item->get_component<PhysicComponent>().speedY() * (*delta);
	}
}
