#ifndef ECS_ENTITY_H_
#define ECS_ENTITY_H_

#include <map>
#include "ECSTypes.h"
#include "ECSComponent.h"

namespace ecs
{
	class ECSEntity
	{
	private:
		EntityID m_id;
		//std::map<ComponentTypeID, ECSComponent*> m_components;

	public:
		explicit ECSEntity(EntityID id) : m_id(id) { };
		EntityID getID() const { return m_id; };

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

	};
}


#endif // ECS_ENTITY_H_
