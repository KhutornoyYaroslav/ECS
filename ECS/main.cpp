#include <stdio.h>
#include <iostream>

#include "ECSManager.h"
#include "ECSSystem.h"
#include "ECSEntity.h"

#include "ECS_HEADER_ONLY.h"

class PositionComponent : public ecs::ECSComponent<PositionComponent>
{
public:
	PositionComponent(int v1, int v2, double v3) : val1(v1), val2(v2), val3(v3) {};

	int val1;
	int val2;
	double val3;
};

struct MovementComponent : public ecs::ECSComponent<MovementComponent>
{
public:
	MovementComponent(int v) : val1(v) {};

	int val1;
};

class MovingSystem : public ecs::ECSSystem<MovingSystem>
{
public:
	MovingSystem()
	{
		///this->addComponentType(MovementComponent::ID);
		//this->addComponentType(PositionComponent::ID);
	}

	void update(double delta_ms) override 
	{
	};
};

class RenderSystem : public ecs::ECSSystem<RenderSystem>
{
public:
	void update(double delta_ms) override
	{
	};
};


int main(void)
{
	ecs::ECSManager ecsManager;
	//const auto newEntityId = ecsManager.makeEntity();
	//ecsManager.assignComponentToEntity<PositionComponent>(newEntityId, 10, 20, 3.3);
	//ecsManager.assignComponentToEntity<MovementComponent>(newEntityId, 123);
	//std::cout << "PositionComponent SIZE is " << PositionComponent::SIZE << ", ID is " << PositionComponent::ID << "\n";
	//std::cout << "MovementComponent SIZE is " << MovementComponent::SIZE << ", ID is " << MovementComponent::ID << "\n";

	///ECS::World::registerSystem

	ecsManager.registerSystem<MovingSystem>();
	ecsManager.registerSystem<RenderSystem>();

	ecsManager.unregisterSystem<MovingSystem>();

	ecsManager.enableSystem<MovingSystem>();
	ecsManager.updateSystems(33);

	//const auto sys = ecsManager.registerSystem<MovingSystem>();

	std::cin.get();
	return 0;
}