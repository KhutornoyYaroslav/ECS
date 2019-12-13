#ifndef ECS_ENTITY_H_
#define ECS_ENTITY_H_

#include <map>
#include "Types.h"
#include "Component.h"

namespace ecs
{
	class Entity
	{
	private:
		ObjectID m_id;
		//std::map<ComponentTypeID, ECSComponent*> m_components;

	public:
		explicit Entity(ObjectID id) : m_id(id) { };

		ObjectID id() const 
		{ 
			return m_id; 
		};

		template<typename Component, typename... Args>
		void assignComponent(Args&& ... args)
		{
			///printf("Entity[%llu]: new component[%llu] was assigned.\n", m_id, Component::ID);
		};

		template<typename Component>
		bool hasComponent()
		{

		};

		template<typename Component>
		void removeComponent()
		{
			///printf("Entity[%llu]: component[%llu] was removed.\n", m_id, Component::ID);
		};

		void removeComponents()
		{

		};


		/*template<class Component>
		Component* getComponent() const
		{
			auto it = m_components.find(Component::ID);

			if (it == m_components.end())
			{
				return nullptr;
			}
			else
			{
				return it->second;
			}		
		};*/

		// TODO:
		/// void assignComponent

	};
}


#endif // ECS_ENTITY_H_
