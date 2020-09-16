#ifndef ECS_H
#define ECS_H

/* 
 *	This header contains classes that are required for realizing
 *	"Entity Component System". It includes Component, System, 
 *	Entity and Manager classes.
 *
 *	Component class is abstract class that is required for creating 
 *	your own components. Inherit it and describe properties that you need.
 *	Component class contains encapsulated properties of object. For 
 *	example TransformComponent contains size and position of object.
 *
 * 	System class is abstract class that is required for creating your
 * 	own systems. As in component you need inherit it and then overload update
 * 	function.
 * 	System class is required for updating components' properties. For example 
 * 	PhysicSystem updates the object position
 *
 * Entity contains components. You can use add_component function to add 
 * new one. Function has_component returns true if component exists in 
 * this entity. Function get_component returns reference to component
 *	
 * Manager contains all entities and systems. Use add_entity to create new one.
 * Function add_system add new system to manager. Get and has functions are 
 * the same as functions in Entity.
 */

#include <stdexcept>
#include <vector>
#include <array>
#include <bitset>
#include <algorithm>

// Max components quantity that you can create
#define MAX_COMPONENTS 32
// Max systems quantity that you can create
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
	bool isActive;

	virtual ~Component(){}
	virtual void init(){}
};

class System
{
private:
protected:
	std::vector<Entity*> entities;
public:
	EntityManager* manager;
	bool isActive;

	virtual ~System(){}
	virtual void update(){}
	virtual void init();
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
	bool isActive;

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
			throw std::runtime_error("[Entity] <get_component>: Component doesn't exist! Component ID: " + std::to_string(get_typeID<T>()));
		}
		auto buf = components_array[get_typeID<T>()];
		return *static_cast<T*>(buf);
	}
	template<typename T, typename... TArgs>
	T& add_component(TArgs... MArgs)
	{
		if (has_component<T>())
		{
			throw std::runtime_error("[Entity] <add_component>: Component already exists! Component ID: " + std::to_string(get_typeID<T>()));
		}

		T* buf = new T(MArgs...);
		components.push_back(buf);
		components_array[get_typeID<T>()] = buf;
		components_bitset[get_typeID<T>()] = true;
		buf->entity = this;
		buf->init();
		buf->isActive = true;
		return *buf;
	}
	template<typename T>
	void remove_component()
	{
		if (!has_component<T>())
		{
			throw std::runtime_error("[Entity] <remove_component>: Component doesn't exist! Component ID: " + std::to_string(get_typeID<T>()));
		}
		components.erase(std::remove(components.begin(), components.end(), components_array[get_typeID<T>()]), components.end());
		components_bitset[get_typeID<T>()] = false;
		delete components_array[get_typeID<T>()];
		components_array[get_typeID<T>()] = nullptr;
	}
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
			throw std::runtime_error ("[Manager] <get_system>: System doesn't exist! System ID: " + std::to_string(get_typeID<T>()));
		}
		auto buf = systems_array[get_typeID<T>()];
		return *static_cast<T*>(buf);
	}

	template<typename T, typename... TArgs>
	T& add_system(TArgs... MArgs)
	{
		if (has_system<T>())
		{
			throw std::runtime_error("[Manager] <add_system>: System already exists! System ID: " + std::to_string(get_typeID<T>()));
			exit(1);
		}
		T* buf = new T(MArgs...);
		systems.push_back(buf);
		systems_array[get_typeID<T>()] = buf;
		systems_bitset[get_typeID<T>()] = true;
		buf->manager = this;
		buf->init();
		buf->isActive = true;
		return *buf;
	}

	void update();
};

#endif 
