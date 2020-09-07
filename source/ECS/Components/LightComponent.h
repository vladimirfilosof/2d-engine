#ifndef LIGHTCOMPONENT_H
#define LIGHTCOMPONENT_H

#include "../ECS.h"

class LightComponent : public Component
{
private:
	unsigned int rad;
	int xpos;
	int ypos;
public:
	LightComponent(const int& x, const int& y, const unsigned int& radius);
	~LightComponent();

	unsigned int& radius(){return rad;}

	int& x(){return xpos;}
	int& y(){return ypos;}
};

#endif
