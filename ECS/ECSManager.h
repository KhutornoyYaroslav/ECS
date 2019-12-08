#ifndef ECS_MANAGER_H_
#define ECS_MANAGER_H_

#include <vector>
#include <map>
#include "ECSSystem.h"
#include "ECSComponent.h"

namespace ecs
{
	class ECSManager
	{
	private:
		// components
		// entities
		std::map<SystemTypeID, ECSBaseSystem*> m_systems;

		//std::map<ComponentTypeID, std::vector<ECSBaseComponent*>> m_components;
		size_t m_entity_counter = 0;

	public:

		template<typename System>
		inline void registerSystem()
		{
			// TODO: if already same type system exists
			m_systems.emplace(std::pair<SystemTypeID, ECSBaseSystem*>(System::ID, new System));
			printf("Register new system [id = %llu]. Systems size = %llu\n", System::ID, m_systems.size());
		};

		template<typename System>
		void unregisterSystem()
		{
			m_systems.erase(System::ID);
			printf("Unregister system [id = %llu]. Systems size = %llu\n", System::ID, m_systems.size());
		};

		template<typename System>
		void disableSystem()
		{
			// TODO:
		};

		template<typename System>
		void enableSystem()
		{
			// TODO:
		};


		void updateSystems(double delta_ms) { };


		EntityID createEntity() 
		{ 
			return 0;
		};

		//// TODO: move this method to Entity class
		//template<typename Component, typename... Args>
		//void assignComponentToEntity(EntityID id, Args&& ... args)
		//{
		//	Component new_cmp(std::forward<Args>(args) ...);
		//}

		void removeEntity(EntityID id) { };
	};
}

#endif // ECS_MANAGER_H_
