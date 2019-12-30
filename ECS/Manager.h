#ifndef ECS_MANAGER_H_
#define ECS_MANAGER_H_

#include <map>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>

#include "System.h"
#include "Component.h"
#include "Entity.h"

namespace ecs
{
	class Manager
	{
	private:
		// components std::map<TypeID, std::vector<IComponent>> m_components;		
		std::map<TypeID, std::pair<ISystem*, bool>> m_systems;

		ObjectID m_entities_counter = 0;
		std::vector<Entity> m_entities;

	public:
		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Systems >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		~Manager()
		{
			unregisterSystems();
		}

		template<typename System, typename... Args>
		inline void registerSystem(Args&& ... args)
		{
			if (m_systems.find(System::ID) == m_systems.end())
			{
				m_systems.insert({ System::ID, { new System(std::forward<Args>(args) ...), true } });
				printf("Register new system [id = %llu]. Systems size = %llu\n", System::ID, m_systems.size());
			}
		};

		template<typename System>
		void unregisterSystem()
		{
			auto it = m_systems.find(System::ID);
			if (it != m_systems.end())
			{
				if (it->second.first)
					delete it->second.first;

				m_systems.erase(it);
				printf("Unregister system [id = %llu]. Systems size = %llu\n", System::ID, m_systems.size());
			}
		};

		void unregisterSystems()
		{
			for (auto it = m_systems.begin(); it != m_systems.end(); ++it)
				if (it->second.first)
					delete it->second.first;

			m_systems.clear();
			printf("Unregister all systems. Systems size = %llu\n", m_systems.size());
		};

		template<typename System>
		void disableSystem()
		{
			auto it = m_systems.find(System::ID);
			if (it != m_systems.end())
			{
				it->second.second = false;
				printf("System::ID %llu was disabled.\n", System::ID);
			}
		};

		template<typename System>
		void enableSystem()
		{
			auto it = m_systems.find(System::ID);
			if (it != m_systems.end())
			{
				it->second.second = true;
				printf("System::ID %llu was enabled.\n", System::ID);
			}
		};

		void updateSystems(double delta_ms) 
		{
			//for (auto& system : m_systems)
			//{
			//	if (system.second.second)
			//		system.second.first->update(delta_ms);
			//}
		};

		// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Entities >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		ObjectID createEntity() 
		{ 
			m_entities.emplace_back(std::move(Entity(m_entities_counter++)));	
			printf("New entity %llu was created. Entites number = %llu\n", m_entities.back().id(), m_entities.size());
			return m_entities.back().id();
		};

		void removeEntity(ObjectID id)
		{
			if (std::find_if(m_entities.begin(), m_entities.end(), [&](const Entity& e) { return e.id() == id; }) != m_entities.end())
				printf("Entity %llu was removed. ", m_entities.back().id());

			m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(), 
				[&](const Entity& e) { return e.id() == id; }), m_entities.end());

			printf("Entites number = %llu\n", m_entities.size());
		};

		template<typename Component, typename... Args>
		void assignComponent(ObjectID entity_id, Args&& ... args)
		{
			///printf("Entity[%llu]: new component[%llu] was assigned.\n", m_id, Component::ID);
		};

		template<typename Component>
		bool hasComponent(ObjectID entity_id)
		{

		};

		template<typename Component>
		void removeComponent(ObjectID entity_id)
		{
			///printf("Entity[%llu]: component[%llu] was removed.\n", m_id, Component::ID);
		};

		void removeComponents(ObjectID entity_id)
		{

		};

	};
}

#endif // ECS_MANAGER_H_
