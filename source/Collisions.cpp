#include "Collisions.h"

bool Collision::AABB(const SDL_Rect& r1, const SDL_Rect& r2)
{
	if (r1.x < r2.x + r2.w && r1.x + r1.w > r2.x &&
		r1.y < r2.y + r2.h && r1.y + r1.h > r2.y)
	{
		return true;
	}
	return false;
}

bool Collision::AABB(TransformComponent& tc1, TransformComponent& tc2)
{
	return AABB(tc1.get_rect(), tc2.get_rect());
}
