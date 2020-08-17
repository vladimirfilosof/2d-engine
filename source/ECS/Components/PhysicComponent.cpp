#include "PhysicComponent.h"

PhysicComponent::PhysicComponent(const double& speed_x, const double& speed_y)
{
	sp.x() = speed_x;
	sp.y() = speed_y;
}
PhysicComponent::~PhysicComponent()
{
}

void PhysicComponent::init()
{
	dir.zeroize();
}
