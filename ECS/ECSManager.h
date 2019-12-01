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
		// systems
		//std::vector<ECSSystem*> m_systems;
		//std::map<ComponentTypeID, std::vector<ECSBaseComponent*>> m_components;
		size_t m_entity_counter = 0;

	public:
		void updateSystems(double delta_ms) { };

		template<class... Components>
		EntityID makeEntity() 
		{ 
			return 0;
		};



		void removeEntity(EntityID id) { };
	};
}

#endif // ECS_MANAGER_H_
