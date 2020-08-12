#include "PhysicComponent.h"

PhysicComponent::PhysicComponent(double* delta, const double& speed_x, const double& speed_y)
{
	delta_time = delta;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
}
PhysicComponent::~PhysicComponent()
{
}

void PhysicComponent::init()
{
	if (!entity->has_component<TransformComponent>())
	{
		std::cerr << "[Engine] <PhysicComponent>: TransformComponent doesn't exist" << std::endl;
		exit(1);
	}
	transform = &entity->get_component<TransformComponent>();

	dir.zeroize();
}

void PhysicComponent::draw()
{
}

void PhysicComponent::update()
{
	if (dir.x() != 0 && dir.y() != 0 && abs(dir.x()) == 1)
	{
		dir.x() *= 0.7;
		dir.y() *= 0.7;
	}
	transform->coords().x() += dir.x() * speed_x * (*delta_time);
	transform->coords().y() += dir.y() * speed_y * (*delta_time);
}

