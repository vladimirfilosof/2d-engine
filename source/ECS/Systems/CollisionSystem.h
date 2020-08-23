#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../ECS.h"
#include "../Components/TransformComponent.h"
#include "../Components/PhysicComponent.h"
#include "../Components/ColliderComponent.h"
#include "../../Collisions.h"
#include <iostream>
#include <SDL2/SDL_rect.h>

class CollisionSystem : public System
{
private:
	double* delta;
	void next_step(Entity* entity, PhysicComponent*& pc, TransformComponent& Dtc_x, TransformComponent& Dtc_y);
public:
	CollisionSystem(double* d) : delta(d){};
	~CollisionSystem();

	void update();
	virtual void handling_collision(Entity* e1, Entity* e2);
};

#endif
