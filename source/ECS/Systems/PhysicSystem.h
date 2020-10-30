#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

#include "../ECS.h"
#include "../Components/PhysicComponent.h"
#include "../Components/TransformComponent.h"
#include <vector>
#include "../../dbhelper.h"

class PhysicSystem : public System
{
private:
public:
	PhysicSystem();
	~PhysicSystem();

	void update();
};

#endif
