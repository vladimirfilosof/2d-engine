#include "TransformComponent.h"

// difinition Size class
Size::Size()
{
	height = 0;
	width = 0;
}
Size::Size(const unsigned int& height, const unsigned int& width)
{
	this->height = height;
	this->width = width;
}

Size::~Size()
{}

unsigned int& Size::h()
{
	return height;
}

unsigned int& Size::w()
{
	return width;
}

// difinition TransformComponent

TransformComponent::TransformComponent()
{
	obj_coords.x() = 0;
	obj_coords.y() = 0;
}
TransformComponent::TransformComponent(const double& x, const double& y, const unsigned int& h, const unsigned int& w)
{
	obj_coords.x() = x;
	obj_coords.y() = y;
	obj_size.h() = h;
	obj_size.w() = w;
}

TransformComponent::~TransformComponent()
{}

Vector2D& TransformComponent::coords()
{
	return obj_coords;
}

Size& TransformComponent::size()
{
	return obj_size;
}
