#include "ColliderComponent.h"
#include <iostream>


ColliderComponent::ColliderComponent(std::string tag)
{
	this->tag = tag;
}

ColliderComponent::~ColliderComponent()
{
}

void ColliderComponent::init()
{
}

std::string& ColliderComponent::Tag()
{
	return tag;
}

void ColliderComponent::update(const std::string& tag, Entity* ent2)
{
	if (event_list.find(tag) != event_list.end())
	{	
		event_list[tag](entity, ent2);
	}
}

void ColliderComponent::add_collisionEvent(const std::string& str, void(*buf)(Entity*, Entity*))
{
	event_list[str] = buf;
}

void ColliderComponent::zeroize()
{
	x_axis = false;
	y_axis = false;
	top = false;
	bottom = false;
	left = false;
	right = false;
}


