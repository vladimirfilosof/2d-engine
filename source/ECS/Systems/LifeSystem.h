#ifndef LIFESYSTEM_H
#define LIFESYSTEM_H

#include <iostream>
#include "../ECS.h"
#include "../Components/HealthComponent.h"
#include "../Components/SpriteComponent.h"

class LifeSystem : public System
{
private:
public:
	LifeSystem();
	~LifeSystem();
	void update();
};

#endif
