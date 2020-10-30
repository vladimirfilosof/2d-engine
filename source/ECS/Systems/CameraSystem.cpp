#include "CameraSystem.h"

#ifdef DEBUG
	#include <iostream>
	#include <chrono>
#endif

CameraSystem::CameraSystem(const int& width, const int& height)
{
	this->width = width;
	this->height = height;
}
CameraSystem::CameraSystem(Entity* focus, const int& width, const int& height)
{
	this->focus = focus;
	this->width = width;
	this->height = height;
}

CameraSystem::~CameraSystem()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: CameraSystem destructor calling" << std::endl;
#endif
}

void CameraSystem::update()
{
	std::vector<Entity*>& entities = manager->get_entities();
	int xpos = focus->get_component<TransformComponent>().coords().x() - (width - focus->get_component<TransformComponent>().size().w()) / 2; 
	int ypos = focus->get_component<TransformComponent>().coords().y() - (height - focus->get_component<TransformComponent>().size().h()) / 2; 

	for (auto& item : entities)
	{
		item->get_component<TransformComponent>().coords().x() -= xpos;
		item->get_component<TransformComponent>().coords().y() -= ypos;
	}
}

void CameraSystem::change_focus(Entity* new_focus)
{
	focus = new_focus;
}
