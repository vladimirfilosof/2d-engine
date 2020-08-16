#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

#include "ECS.h"
#include "PhysicComponent.h"
#include "TransformComponent.h"
#include <vector>
#include <iostream>

class PhysicSystem : public System
{
private:
	std::vector<Entity*> entities;
	double* delta;
public:
	PhysicSystem(double* d) : delta(d){}
	~PhysicSystem();

	void init();
	void update();
};

#endif
