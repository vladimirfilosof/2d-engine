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
	SDL_Rect r1;
	r1.h = tc1.size().w();
	r1.w = tc1.size().h();
	r1.x = tc1.coords().x();
	r1.y = tc1.coords().y();

	SDL_Rect r2;
	r2.h = tc2.size().w();
	r2.w = tc2.size().h();
	r2.x = tc2.coords().x();
	r2.y = tc2.coords().y();

	return AABB(r1, r2);
}
