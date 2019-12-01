#include "ECSComponent.h"

namespace ecs
{
	static ComponentTypeID componentTypeIDCounter = 0;

	ComponentTypeID ECSBaseComponent::registerECSComponentType()
	{
		return componentTypeIDCounter++;
	}
}