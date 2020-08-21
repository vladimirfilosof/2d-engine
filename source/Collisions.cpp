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
	SDL_Rect r2;

	ConvertToSDL(tc1, r1);
	ConvertToSDL(tc2, r2);

	return AABB(r1, r2);
}

void Collision::ConvertToSDL(TransformComponent& tc, SDL_Rect& r)
{
	r.h = tc.size().w();
	r.w = tc.size().h();
	r.x = tc.coords().x();
	r.y = tc.coords().y();
}


