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
		ObjectID getID() const { return m_id; };

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
