#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "../ECS.h"
#include <SDL2/SDL_rect.h>
#include "../../Vector2D.h"

class Size
{
public:
	Size();
	~Size();
	Size(const double& height, const double& width);
	double& h();
	double& w();
private:
	double height = 0;
	double width = 0;
};

class TransformComponent : public Component
{
public:
	TransformComponent();
	~TransformComponent();
	TransformComponent(const double& x, const double& y, const double& h, const double& w);
	Vector2D& coords();
	Size& size();

	SDL_Rect get_rect();
private:
	Vector2D obj_coords;
	Size obj_size;
};

#endif

