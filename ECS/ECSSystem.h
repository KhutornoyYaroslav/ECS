#ifndef ECS_SYSTEM_H_
#define ECS_SYSTEM_H_

#include <set>
#include "ECSTypes.h"

namespace ecs
{
	///class ECSManager;

	class ECSBaseSystem
	{
	protected:
		static SystemTypeID registerECSSystemType();
	};

	template<typename System>
	class ECSSystem : public ECSBaseSystem
	{
	private:
		std::set<ComponentTypeID> m_componentTypes;

	public:
		static const SystemTypeID ID;

	protected:
		void addComponentType(ComponentTypeID typeID)
		{
			m_componentTypes.insert(typeID);
		};

	public:
		virtual ~ECSSystem() = default;
		virtual void update(double delta_ms) = 0;
		///virtual void configure(ECSManager* manager) = 0;
	};

	template<typename System>
	const SystemTypeID ECSSystem<System>::ID(ECSBaseSystem::registerECSSystemType());
}

#endif // ECS_SYSTEM_H_