#include "TransformComponent.h"

// difinition Size class
Size::Size()
{
	height = 0;
	width = 0;
}
Size::Size(const double& height, const double& width)
{
	this->height = height;
	this->width = width;
}

Size::~Size()
{}

double& Size::h()
{
	return height;
}

double& Size::w()
{
	return width;
}

// difinition TransformComponent

TransformComponent::TransformComponent()
{
	obj_coords.x() = 0;
	obj_coords.y() = 0;
}
TransformComponent::TransformComponent(const double& x, const double& y, const double& h, const double& w)
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

SDL_Rect TransformComponent::get_rect()
{
	SDL_Rect rect;
	rect.w = static_cast<int>(obj_size.w());
	rect.h = static_cast<int>(obj_size.h());
	rect.x = static_cast<int>(obj_coords.x());
	rect.y = static_cast<int>(obj_coords.y());
	return rect;
}
