#ifndef ECS_COMPONENT_H_
#define ECS_COMPONENT_H_

#include "Types.h"
#include "TypeRegistrator.h"

namespace ecs
{
	class IComponent
	{
		///virtual ~IComponent() {};
	};

	TypeID utils::TypeRegistrator<IComponent>::m_counter = 0;

	template<typename T>
	class Component : public IComponent
	{
	public:
		static const TypeID ID;
		static const size_t SIZE;
	};

	template<typename T>
	const size_t Component<T>::SIZE(sizeof(T));

	template<typename T>
	const TypeID Component<T>::ID(utils::TypeRegistrator<IComponent>::registerNewType<T>());
}

#endif  // ECS_COMPONENT_H_
