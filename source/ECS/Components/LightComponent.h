#ifndef LIGHTCOMPONENT_H
#define LIGHTCOMPONENT_H

#include "../ECS.h"

class LightComponent : public Component
{
private:
	unsigned int rad;
public:
	LightComponent(const unsigned int& radius);
	~LightComponent();

	unsigned int& radius(){return rad;}
};

#endif
