#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

#include "../ECS.h"
#include "../Components/PhysicComponent.h"
#include "../Components/TransformComponent.h"
#include <vector>
#include <iostream>

class PhysicSystem : public System
{
private:
	double* delta;
public:
	PhysicSystem(double* d) : delta(d){}
	~PhysicSystem();

	void update();
};

#endif
