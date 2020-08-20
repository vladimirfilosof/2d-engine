#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "../ECS.h"
#include "../../Vector2D.h"

class Size
{
public:
	Size();
	~Size();
	Size(const unsigned int& height, const unsigned int& width);
	unsigned int& h();
	unsigned int& w();
private:
	unsigned int height = 0;
	unsigned int width = 0;
};

class TransformComponent : public Component
{
public:
	TransformComponent();
	~TransformComponent();
	TransformComponent(const double& x, const double& y, const unsigned int& h, const unsigned int& w);
	Vector2D& coords();
	Size& size();

private:
	Vector2D obj_coords;
	Size obj_size;
};

#endif

