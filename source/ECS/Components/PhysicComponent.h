#ifndef PHYSIC_H
#define PHYSIC_H

#include "../ECS.h"
#include "../../Vector2D.h"

class PhysicComponent : public Component
{
private:
	Vector2D dir;

	Vector2D sp;
public:
	PhysicComponent(const double& speed_x, const double& speed_y);
	~PhysicComponent();

	void init();

	Vector2D& speed(){return sp;}

	Vector2D& direction(){return dir;}
};

#endif
