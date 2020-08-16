#ifndef PHYSIC_H
#define PHYSIC_H

#include "ECS.h"
#include "../Vector2D.h"

class PhysicComponent : public Component
{
private:
	Vector2D dir;

	double speed_x;
	double speed_y;
public:
	PhysicComponent(const double& speed_x, const double& speed_y);
	~PhysicComponent();

	void init();

	double& speedX(){return speed_x;}
	double& speedY(){return speed_y;}
	Vector2D& direction(){return dir;}
};

#endif
