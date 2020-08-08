#include "ECS.h"

std::size_t get_newID()
{
	static std::size_t ID = 0;
	return ID++;
}

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::draw()
{
	for (auto& item : components)
	{
		item->draw();
	}
}

void Entity::update()
{
	for (auto& item : components)
	{
		item->update();
	}
}

EntityManager::EntityManager()
{
}
EntityManager::~EntityManager()
{
}

void EntityManager::draw()
{
	for (auto& item : entities)
	{
		item->draw();
	}
}

void EntityManager::update()
{
	for (auto& item : entities)
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
