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
void HealthComponent::change_maxHealth(const double& new_maxHealth)
{
	if (max_health == 0) throw std::runtime_error("[HealthComponent] <change_maxHealth>: division by zero! max_health is equal to zero");
	current_health = (current_health * new_maxHealth) / max_health; 
	max_health = new_maxHealth;
}
