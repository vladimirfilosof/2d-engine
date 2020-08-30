#include "CameraSystem.h"

CameraSystem::CameraSystem(Entity* focus, const int& width, const int& height)
{
	this->focus = focus;
	this->width = width;
	this->height = height;
}

CameraSystem::~CameraSystem()
{}

void CameraSystem::update()
{
	int xpos = focus->get_component<TransformComponent>().coords().x() - (width - focus->get_component<TransformComponent>().size().w()) / 2; 
	int ypos = focus->get_component<TransformComponent>().coords().y() - (height - focus->get_component<TransformComponent>().size().h()) / 2; 

	for (auto& item : entities)
	{
		item->get_component<TransformComponent>().coords().x() -= xpos;
		item->get_component<TransformComponent>().coords().y() -= ypos;
	}
}
