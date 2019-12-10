#ifndef ECS_SYSTEM_H_
#define ECS_SYSTEM_H_

#include <set>
#include "Types.h"
#include "TypeRegistrator.h"

namespace ecs
{
	class ISystem
	{
	public:
		virtual void update(double delta_ms) = 0;
	};

	TypeID utils::TypeRegistrator<ISystem>::m_counter = 0;

	template<typename T>
	class System : public ISystem
	{
	public:
		static const TypeID ID;
	};

	template<typename T>
	const TypeID System<T>::ID(utils::TypeRegistrator<ISystem>::registerNewType<T>());
}

#endif // ECS_SYSTEM_H_