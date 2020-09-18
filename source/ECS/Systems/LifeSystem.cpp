#include "LifeSystem.h"

#ifdef DEBUG
	#include <iostream>
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
#ifdef DEBUG
	std::cout << "[DEBUG]: LifeSystem begin" << std::endl;
#endif

	std::for_each(entities.begin(), entities.end(), LifePTR);

#ifdef DEBUG
	std::cout << "[DEBUG]: LifeSystem end" << std::endl;
#endif

}
