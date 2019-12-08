#include "ECSSystem.h"

namespace ecs
{
	static SystemTypeID systemTypeIDCounter = 0;

	SystemTypeID ECSBaseSystem::registerECSSystemType()
	{
		return systemTypeIDCounter++;
	}
}