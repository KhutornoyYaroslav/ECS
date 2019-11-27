#ifndef ECS_COMPONENT_MANAGER_H_
#define ECS_COMPONENT_MANAGER_H_

#include "Component.h"
#include <map>
//class Component;

namespace ecs
{
	using EntityID = size_t; // TODO: поместить в entity.h


	class IComponentContainer
	{
	//public:

		//virtual ~IComponentContainer() {};
		//virtual const char* GetComponentContainerTypeName() const = 0;
		//virtual void DestroyComponent(IComponent* object) = 0;
	};

	template<typename T>
	class ComponentContainer : public IComponentContainer
	{
		// add component
		// remove component
	};

	class ComponentManager
	{
	public:

		template<typename T>
		void AddComponent(EntityID entity_id);

		template<typename T>
		void RemoveComponent(EntityID entity_id);

		void RemoveAllComponents(EntityID entity_id);

		template<typename T>
		ComponentContainer<T>* GetComponentContainer();

	private:
		std::map<ComponentTypeID, IComponentContainer*> m_componentContainerMap;
	};
}

#endif  // ECS_COMPONENT_MANAGER_H_
