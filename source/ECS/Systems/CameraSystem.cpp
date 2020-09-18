#include "CameraSystem.h"

#ifdef DEBUG
	#include <iostream>
	#include <chrono>
#endif

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
#ifdef DEBUG
	std::cout << "\t[DEBUG]: CameraSystem begins" << std::endl;
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
#endif
	int xpos = focus->get_component<TransformComponent>().coords().x() - (width - focus->get_component<TransformComponent>().size().w()) / 2; 
	int ypos = focus->get_component<TransformComponent>().coords().y() - (height - focus->get_component<TransformComponent>().size().h()) / 2; 

	for (auto& item : entities)
	{
		item->get_component<TransformComponent>().coords().x() -= xpos;
		item->get_component<TransformComponent>().coords().y() -= ypos;
	}
#ifdef DEBUG
	std::chrono::system_clock::time_point e = std::chrono::system_clock::now();
	std::chrono::duration<double> d = e - b;
	std::cout << "\t[DEBUG]: CameraSystem ends with duration: " << std::to_string(d.count()) << std::endl;
#endif
}

void CameraSystem::change_focus(Entity* new_focus)
{
	focus = new_focus;
}
