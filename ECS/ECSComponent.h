#ifndef ECS_COMPONENT_H_
#define ECS_COMPONENT_H_

#include "ECSTypes.h"

namespace ecs
{
	class ECSBaseComponent
	{
	protected:
		static ComponentTypeID registerECSComponentType();
	};

	template<typename Component>
	class ECSComponent : public ECSBaseComponent
	{
	private:
		//ComponentID m_id;
		//EntityID m_entityID;

	public:
		static const ComponentTypeID ID;
		static const size_t SIZE;

		//ECSComponent() : m_id(0), m_entityID(0) { }; // TODO: INVALID_COMPONENTID
		//virtual ~ECSComponent() = default;

		//inline ComponentID GetComponentID() const
		//{
		//	return this->m_id;
		//}

		//inline ComponentTypeID GetComponentTypeID() const
		//{
		//	return this->m_type;
		//}

		//inline EntityID GetEntityID() const
		//{
		//	return this->m_entityID;
		//}
	};

	template<typename Component>
	const size_t ECSComponent<Component>::SIZE(sizeof(Component));

	template<typename Component>
	const ComponentTypeID ECSComponent<Component>::ID(ECSBaseComponent::registerECSComponentType());
}

#endif  // ECS_COMPONENT_H_
