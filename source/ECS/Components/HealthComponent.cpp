#include "HealthComponent.h"

HealthComponent::HealthComponent(const double& max_health)
{
	this->max_health = max_health;
	current_health = max_health;
}

HealthComponent::~HealthComponent()
{
}

void HealthComponent::init()
{
	damage_time = std::chrono::system_clock::now();
}

void HealthComponent::add_damage (const double& damage)
{
	double d = ((std::chrono::duration<double>)(std::chrono::system_clock::now() - damage_time)).count();
	if (d > 1)
	{
		current_health -= damage;
		damage_time = std::chrono::system_clock::now();
	}
}
