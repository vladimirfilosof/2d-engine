#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "../ECS.h"
#include <string>
#include <SDL2/SDL_rect.h>
#include <map>

class ColliderComponent : public Component
{
private:
	std::string tag;
	std::map<std::string, void(*)(Entity*, Entity*, const double*)> event_list;
public:
	ColliderComponent(std::string tag);
	~ColliderComponent();
	void init();
	std::string& Tag();
	void zeroize();

	void update(const std::string& str, Entity* en2, const double* deltaTime);

	void add_collisionEvent(const std::string& str, void(*)(Entity*, Entity*, const double*));

	bool x_axis = false;
	bool y_axis = false;
	bool right = false;
	bool left = false;
	bool top = false;
	bool bottom	= false;
};
#endif
