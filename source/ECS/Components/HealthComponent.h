#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "../ECS.h"
#include <chrono>
#include <iostream>

class HealthComponent : public Component
{
private:
	double max_health;
	double current_health;

	std::chrono::system_clock::time_point damage_time;
public:
	HealthComponent(const double& max_health);
	~HealthComponent();

	void init();

	double& maximum_health(){return max_health;}

	double& health(){return current_health;}

	void change_maxHealth(const double& new_maxHealth);

	void add_damage(const double& damage);
	
};

#endif
