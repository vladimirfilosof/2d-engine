#ifndef LIFESYSTEM_H
#define LIFESYSTEM_H

#include <iostream>
#include "../ECS.h"
#include "../Components/HealthComponent.h"
#include "../Components/SpriteComponent.h"
#include <algorithm>

class LifeSystem : public System
{
private:
	void (*LifePTR)(Entity* entity);
public:
	LifeSystem(void(*FUNC)(Entity* entity));
	~LifeSystem();
	void update();
};

#endif
