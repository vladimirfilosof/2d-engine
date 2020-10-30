#include "LifeSystem.h"

#ifdef DEBUG
	#include <iostream>
	#include <chrono>
#endif

LifeSystem::LifeSystem(void(*FUNC)(Entity* entity))
{
	LifePTR = FUNC;
}

LifeSystem::~LifeSystem()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: LifeSystem destructor calling" << std::endl;
#endif
}

void LifeSystem::update()
{
	std::vector<Entity*>& entities = manager->get_entities();
	std::for_each(entities.begin(), entities.end(), LifePTR);

}
