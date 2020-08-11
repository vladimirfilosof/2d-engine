#include "TransformComponent.h"

// difinition Size class
Size::Size(){}
Size::Size(unsigned int height, unsigned int width)
{
	this->height = height;
	this->width = width;
}

Size::~Size(){}

unsigned int& Size::h()
{
	return height;
}

unsigned int& Size::w()
{
	return width;
}

// difinition TransformComponent

TransformComponent::TransformComponent(){}
TransformComponent::TransformComponent(double x, double y, unsigned int h, unsigned int w)
{
	obj_coords.X() = x;
	obj_coords.Y() = y;
	obj_size.h() = h;
	obj_size.w() = w;
	
}

TransformComponent::~TransformComponent(){}

Vector2D& TransformComponent::coords()
{
	return obj_coords;
}

Size& TransformComponent::size()
{
	return obj_size;
}



