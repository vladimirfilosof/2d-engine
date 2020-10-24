#include "ECS.h"

#ifdef DEBUG
	#include <iostream>
	#include <chrono>
#endif

Entity::Entity()
{
}

Entity::~Entity()
{
	for (auto& component : components)
	{
		delete component;
	}
}

void System::init()
{
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
#ifdef DEBUG
	std::cout << "[DEBUG]: Update loop begins" << std::endl;
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
#endif
	for (auto& item : systems)
	{
		item->update();
	}
#ifdef DEBUG
	std::chrono::system_clock::time_point e = std::chrono::system_clock::now();
	std::chrono::duration<double> d = e - b;
	std::cout << "[DEBUG]: Update loop ends with duration: " << std::to_string(d.count()) << std::endl; 
#endif
}

Entity& EntityManager::add_entity()
{
	Entity* buf = new Entity();
	buf->isActive = true;
	entities.push_back(buf);
	return *buf;
}
