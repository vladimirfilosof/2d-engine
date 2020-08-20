#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "../ECS.h"

class ColliderComponent : public Component
{
private:
public:
	ColliderComponent();
	~ColliderComponent();
	void init();
};
#endif
