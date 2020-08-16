#include "PhysicComponent.h"

PhysicComponent::PhysicComponent(const double& speed_x, const double& speed_y)
{
	this->speed_x = speed_x;
	this->speed_y = speed_y;
}
PhysicComponent::~PhysicComponent()
{
}

void PhysicComponent::init()
{
	dir.zeroize();
}
