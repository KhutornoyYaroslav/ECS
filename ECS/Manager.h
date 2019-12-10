#ifndef ECS_MANAGER_H_
#define ECS_MANAGER_H_

#include <vector>
#include <map>
#include "System.h"
#include "Component.h"

#include <memory>

namespace ecs
{
	class Manager
	{
	private:
		// components
		// entities	
		std::map<TypeID, std::pair<std::unique_ptr<ISystem>, bool>> m_systems;

		//std::map<ComponentTypeID, std::vector<ECSBaseComponent*>> m_components;
		///size_t m_entity_counter = 0;

	public:

		template<typename System, typename... Args>
		inline void registerSystem(Args&& ... args)
		{
			//ECSBaseSystem* p_sys = new System(std::forward<Args>(args) ...);

			//auto find_it = m_systems.find(System::ID);
			//if (find_it == m_systems.end())
			//{
			//	m_systems.insert(std::pair<SystemTypeID, std::pair<ECSBaseSystem*, bool>>(System::ID, std::pair<ECSBaseSystem*, bool>(p_sys, true)));
			//}
			//else
			//{
			//	if (find_it->second.first)
			//		delete find_it->second.first;

			//	find_it->second.first = p_sys;
			//	find_it->second.second = true;
			//}

			printf("Register new system [id = %llu]. Systems size = %llu\n", System::ID, m_systems.size());
		};

		template<typename System>
		void unregisterSystem()
		{
			//auto find_it = m_systems.find(System::ID);
			//if (find_it != m_systems.end())
			//{
			//	printf("lol\n");

			//	if (find_it->second.first)
			//		delete find_it->second.first;

			//	printf("lol2\n");
			//	m_systems.erase(find_it);

			//	printf("Unregister system [id = %llu]. Systems size = %llu\n", System::ID, m_systems.size());
			//}
		};

		template<typename System>
		void disableSystem()
		{
			//auto find_it = m_systems.find(System::ID);
			//if (find_it != m_systems.end())
			//{
			//	find_it->second.second = false;
			//	printf("System::ID %llu was disabled.\n", System::ID);
			//}
		};

		template<typename System>
		void enableSystem()
		{
			//auto find_it = m_systems.find(System::ID);
			//if (find_it != m_systems.end())
			//{
			//	find_it->second.second = true;
			//	printf("System::ID %llu was enabled.\n", System::ID);
			//}
		};

		void updateSystems(double delta_ms) 
		{
			//for (auto& system : m_systems)
			//{
			//	if (system.second.second)
			//		system.second.first->update(delta_ms);
			//}
		};


		ObjectID createEntity() 
		{ 
			return 0;
		};

		//// TODO: move this method to Entity class
		//template<typename Component, typename... Args>
		//void assignComponentToEntity(EntityID id, Args&& ... args)
		//{
		//	Component new_cmp(std::forward<Args>(args) ...);
		//}

		void removeEntity(ObjectID id) { };
	};
}

#endif // ECS_MANAGER_H_
