#include "BoxComponent.h"

#ifdef DEBUG
	#include <iostream>
#endif

BoxComponent::BoxComponent()
{
}

BoxComponent::~BoxComponent()
{
#ifdef DEBUG
	std::cout << "[DEBUG]: BoxComponent destructor calling" << std::endl;
#endif
}

void BoxComponent::init()
{
}
