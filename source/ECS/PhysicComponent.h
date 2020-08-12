#ifndef PHYSIC_H
#define PHYSIC_H

#include "ECS.h"
#include "TransformComponent.h"
#include "../Vector2D.h"

class PhysicComponent : public Component
{
private:
	TransformComponent* transform;
	Vector2D dir;

	double speed_x;
	double speed_y;
	double* delta_time;
public:
	PhysicComponent(double* delta, const double& speed_x, const double& speed_y);
	~PhysicComponent();

	void init();
	void update();
	void draw();

	double& speedX(){return speed_x;}
	double& speedY(){return speed_y;}
	Vector2D& direction(){return dir;}
};

#endif
