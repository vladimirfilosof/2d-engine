#include "ECS.h"

Entity::Entity()
{
}

Entity::~Entity()
{
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

	for (auto& system : systems)
	{
		delete system;
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
	buf->isActive = true;
	entities.push_back(buf);
	return *buf;
}
