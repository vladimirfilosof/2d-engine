#include "LightComponent.h"

#ifdef debug
	#include <iostream>
#endif


LightComponent::LightComponent(const unsigned int& radius)
{
	rad = rad;
}
LightComponent::~LightComponent()
{
#ifdef debug
	std::cout << "[DEBUG]: LightComponent destructor calling" << std::endl;
#endif
}


