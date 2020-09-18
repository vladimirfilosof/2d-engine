#include "PhysicComponent.h"

#ifdef DEBUG
	#include <iostream>
#endif

PhysicComponent::PhysicComponent(const double& speed_x, const double& speed_y)
{
	sp.x() = speed_x;
	sp.y() = speed_y;
}
PhysicComponent::~PhysicComponent()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: PhysicComponent destructor calling" << std::endl;
#endif
}

void PhysicComponent::init()
{
	dir.zeroize();
}
