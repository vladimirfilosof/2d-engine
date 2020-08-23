#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "../ECS.h"
#include <string>
#include <SDL2/SDL_rect.h>

class ColliderComponent : public Component
{
private:
	std::string tag;

public:
	ColliderComponent(std::string tag);
	~ColliderComponent();
	void init();
	std::string& Tag();
	void collision(SDL_Rect r1, SDL_Rect r2);
	void zeroize();

	bool x_axis = false;
	bool y_axis = false;
	bool right = false;
	bool left = false;
	bool top = false;
	bool bottom	= false;
};
#endif
