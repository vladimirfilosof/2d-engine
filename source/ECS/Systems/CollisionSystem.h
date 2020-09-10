#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "../ECS.h"
#include "../Components/TransformComponent.h"
#include "../Components/PhysicComponent.h"
#include "../Components/ColliderComponent.h"
#include "../../Collisions.h"
#include <iostream>
#include <SDL2/SDL_rect.h>
#include "../../DeltaTime.h"

class CollisionSystem : public System
{
private:
	void next_step(Entity* entity, PhysicComponent*& pc, TransformComponent& Dtc_x, TransformComponent& Dtc_y);
public:
	CollisionSystem(); 
	~CollisionSystem();

	void update();
};

#endif
