#ifndef CAMERASYSTEM_H
#define CAMERASYSTEM_H

#include "../ECS.h"
#include "../Components/TransformComponent.h"

class CameraSystem : public System
{
private:
	Entity* focus;
	int width;
	int height;
public:
	CameraSystem(const int& width, const int& height);
	CameraSystem(Entity* focus, const int& width, const int& height);
	~CameraSystem();

	void update();

	void change_focus(Entity* new_focus);
};

#endif
