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
	for (auto& item : components)
	{
		delete item;
	}
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
	for (auto& item : entities)
	{
		delete item;
	}
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
