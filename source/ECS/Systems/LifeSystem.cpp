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
#ifdef DEBUG
	std::cout << "\t[DEBUG]: LifeSystem begins" << std::endl;
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
#endif
	std::vector<Entity*>& entities = manager->get_entities();
	std::for_each(entities.begin(), entities.end(), LifePTR);

#ifdef DEBUG
	std::chrono::system_clock::time_point e = std::chrono::system_clock::now();
	std::chrono::duration<double> d = e - b;
	std::cout << "\t[DEBUG]: LifeSystem ends with duration: " << std::to_string(d.count()) << std::endl;
#endif

}
