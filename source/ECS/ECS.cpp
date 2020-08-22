#include "ECS.h"

Entity::Entity()
{
}

Entity::~Entity()
{
	for (auto& item : components)
	{
		delete item;
	}
}

void System::init()
{
	entities = manager->get_entities();
}

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
	for (auto& item : entities)
	{
		delete item;
	}
}

void EntityManager::update()
{
	for (auto& item : systems)
	{
		item->update();
	}
}

Entity& EntityManager::add_entity()
{
	Entity* buf = new Entity();
	entities.push_back(buf);
	return *buf;
}
