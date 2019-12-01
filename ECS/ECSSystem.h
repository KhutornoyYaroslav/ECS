#ifndef ECS_SYSTEM_H_
#define ECS_SYSTEM_H_

#include <set>
#include "ECSTypes.h"

namespace ecs
{
	class ECSSystem
	{
	private:
		std::set<ComponentTypeID> m_componentTypes;

	public:
		virtual ~ECSSystem() = default;
		virtual void update(double delta_ms) = 0;

	protected:
		void addComponentType(ComponentTypeID typeID)
		{
			m_componentTypes.insert(typeID);
		};
	};
}

#endif // ECS_SYSTEM_H_