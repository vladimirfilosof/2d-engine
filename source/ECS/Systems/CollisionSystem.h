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
public:
	CollisionSystem();
	~CollisionSystem();

	void update();
};

#endif
