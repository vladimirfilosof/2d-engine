#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <vector>
#include <array>
#include <bitset>

#define MAX_COMPONENTS 32
#define MAX_SYSTEMS 32

class Component;
class Entity;
class System;
class EntityManager;

class Component
{
private:
public:
	Entity* entity;

	virtual ~Component(){}
	virtual void init(){}
};

class Entity
{
private:
	std::vector<Component*> components;
	std::array<Component*, MAX_COMPONENTS> components_array;
	std::bitset<MAX_COMPONENTS> components_bitset;

// ID manager for components
	inline std::size_t get_newID()
	{
		static std::size_t ID = 0;
		return ID++;
	}
	template<typename T>
	inline std::size_t get_typeID()
	{
		static std::size_t ID = get_newID();
		return ID;
	}

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
			std::cerr << "[Engine] <Entity>: Component doesn't exist!" << std::endl;
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
			std::cerr << "[Engine] <Entity>: Component already exists!" << std::endl;
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
};

class System
{
private:
public:
	EntityManager* manager;

	virtual ~System(){}
	virtual void update(){}
};

class EntityManager
{
private:
	std::vector<Entity*> entities;
	std::vector<System*> systems;
	std::array<System*, MAX_SYSTEMS> systems_array;
	std::bitset<MAX_SYSTEMS> systems_bitset;
	
// ID manager for systems
	inline std::size_t get_newID()
	{
		static std::size_t ID = 0;
		return ID++;
	}
	template<typename T>
	inline std::size_t get_typeID()
	{
		static std::size_t ID = get_newID();
		return ID;
	}

public:
	EntityManager();
	~EntityManager();

// Function creates, adds and returns reference to new entity
	Entity& add_entity();

	std::vector<Entity*>& get_entities(){return entities;}

	template<typename T>
	bool has_system()
	{
		return systems_bitset[get_typeID<T>()];
	}

	template<typename T>
	T& get_system()
	{
		if (!has_system<T>())
		{
			std::cerr << "[Engine] <EntityManager>: System doesn't exist!" << std::endl;
			exit(1);
		}
		auto buf = systems_array[get_typeID<T>()];
		return *static_cast<T*>(buf);
	}

	template<typename T, typename... TArgs>
	T& add_system(TArgs... MArgs)
	{
		if (has_system<T>())
		{
			std::cerr << "[Engine] <EntityManager>: System already exists!" << std::endl;
			exit(1);
		}
		T* buf = new T(MArgs...);
		systems.push_back(buf);
		systems_array[get_typeID<T>()] = buf;
		systems_bitset[get_typeID<T>()] = true;
		buf->manager = this;
		buf->init();
		return *buf;
	}

	void update();
};

#endif 
