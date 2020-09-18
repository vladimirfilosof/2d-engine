#include "ColorComponent.h"

#ifdef debug
	#include <iostream>
#endif


ColorComponent::ColorComponent(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

ColorComponent::~ColorComponent()
{
#ifdef debug
	std::cout << "[DEBUG]: ColorComponent destructor calling" << std::endl;
#endif
}

void ColorComponent::init()
{
}

void ColorComponent::rgba(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}
