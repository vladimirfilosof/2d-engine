#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <SDL2/SDL_rect.h>
#include "ECS/Components/TransformComponent.h"

class Collision
{
private:
public:
	static bool AABB(const SDL_Rect& r1, const SDL_Rect& r2);
	static bool AABB(TransformComponent& tc1, TransformComponent& tc2);
};

#endif
