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

void ColliderComponent::collision(SDL_Rect r1, SDL_Rect r2)
{
	std::cout << "Collision" << std::endl;
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


