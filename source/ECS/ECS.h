#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <vector>
#include <array>
#include <bitset>

#define MAX_COMPONENTS 32

// Return new free integer value
std::size_t get_newID();

template<typename T>
std::size_t get_typeID()
{
	static std::size_t typeID = get_newID();
	return typeID;
}

class Component;
class Entity;
class EntityManager;

class Component
{
private:
public:
	Entity* entity;

	virtual ~Component(){}
	virtual void init(){};
	virtual void update(){};
	virtual void draw(){};
};

class Entity
{
private:
	std::vector<Component*> components;
	std::array<Component*, MAX_COMPONENTS> components_array;
	std::bitset<MAX_COMPONENTS> components_bitset;
public:
	Entity();
	~Entity();

	template<typename T>
	bool has_component()
	{
		return components_bitset[get_typeID<T>()];
	}
	template<typename T>
	T& get_component()
	{
		if (!has_component<T>())
		{
			std::cerr << "[Engine]: Component doesn't exist!" << std::endl;
			exit(1);
		}
		auto buf = components_array[get_typeID<T>()];
		return *static_cast<T*>(buf);
	}
	template<typename T, typename... TArgs>
	T& add_component(TArgs... MArgs)
	{
		if (has_component<T>())
		{
			std::cerr << "[Engine]: Component already exists!" << std::endl;
			exit(1);
		}
		T* buf = new T(MArgs...);
		components.push_back(buf);
		components_array[get_typeID<T>()] = buf;
		components_bitset[get_typeID<T>()] = true;
		buf->entity = this;
		buf->init();
		return *buf;
	}

	void update();
	void draw();

};

class EntityManager
{
private:
	std::vector<Entity*> entities;
public:
	EntityManager();
	~EntityManager();

	Entity& add_entity();
	void update();
	void draw();
};

#endif 
