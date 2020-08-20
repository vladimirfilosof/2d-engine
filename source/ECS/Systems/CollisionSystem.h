#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../ECS.h"
#include "../Components/TransformComponent.h"
#include "../Components/PhysicComponent.h"
#include "../Components/ColliderComponent.h"
#include "../../Collisions.h"
#include <iostream>

class CollisionSystem : public System
{
private:
	std::vector<Entity*> entities;
public:
	CollisionSystem();
	~CollisionSystem();

	void init();
	void update();
};

#endif