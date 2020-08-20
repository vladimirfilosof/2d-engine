#include "ColorComponent.h"

ColorComponent::ColorComponent(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

ColorComponent::~ColorComponent()
{
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
