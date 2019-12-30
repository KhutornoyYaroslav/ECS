#include <stdio.h>
#include <iostream>

#include "Manager.h"
#include "Component.h"
#include "Entity.h"
#include "ECS_HEADER_ONLY.h"

class PositionComponent : public ecs::Component<PositionComponent>
{
public:
	PositionComponent(double x, double y, double z) : x(x), y(y), z(z) {};

	double x;
	double y;
	double z;
};

struct MovementComponent : public ecs::Component<MovementComponent>
{
public:
	MovementComponent(double speed) : speed(speed) {};

	double speed;
};

class MovingSystem : public ecs::System<MovingSystem>
{
public:
	MovingSystem()
	{
		addComponentType(PositionComponent::ID);
		addComponentType(MovementComponent::ID);
	};

	void update(double delta_ms, ecs::IComponent** p_components) override
	{
		PositionComponent* pose = (PositionComponent*)p_components[0];
		MovementComponent* move = (MovementComponent*)p_components[1];
		
		pose->x += move->speed * delta_ms;
		pose->y += move->speed * delta_ms;
		pose->z += move->speed * delta_ms;
	};
};

class StopSystem : public ecs::System<StopSystem>
{
public:
	StopSystem()
	{
		addComponentType(MovementComponent::ID);
	};

	void update(double delta_ms, ecs::IComponent** p_components) override
	{
		MovementComponent* move = (MovementComponent*)p_components[0];

		if(move->speed >= 0.0)
			move->speed -= 0.01;
	};
};

int main(void)
{
	ecs::Manager ecsManager;

	std::cout << "PositionComponent SIZE is " << PositionComponent::SIZE << ", ID is " << PositionComponent::ID << "\n";
	std::cout << "MovementComponent SIZE is " << MovementComponent::SIZE << ", ID is " << MovementComponent::ID << "\n";

	/// New entity creation
	const auto e_id = ecsManager.createEntity();
	ecsManager.assignComponent<PositionComponent>(e_id, 0.0, 0.0, 0.0);
	ecsManager.assignComponent<MovementComponent>(e_id, 1.0);

	/// Register systems
	ecsManager.registerSystem<MovingSystem>();
	ecsManager.registerSystem<StopSystem>();
	
	/// Disable / unable systems
	ecsManager.disableSystem<MovingSystem>();
	ecsManager.enableSystem<MovingSystem>();

	/// Unregister systems
	ecsManager.unregisterSystem<MovingSystem>();
	ecsManager.unregisterSystem<StopSystem>();
	//ecsManager.updateSystems(33);

	std::cin.get();
	return 0;
}