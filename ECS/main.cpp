#include <stdio.h>
#include <iostream>

#include "ECSManager.h"
#include "ECSSystem.h"
#include "ECSEntity.h"


class PositionComponent : public ecs::ECSComponent<PositionComponent>
{
public:
	int val1;
	uint8_t val2;
	double val3;
};

class MovementComponent : public ecs::ECSComponent<MovementComponent>
{
public:
	int val1;
};

class MovingSystem : public ecs::ECSSystem
{
public:
	MovingSystem()
	{
		this->addComponentType(MovementComponent::ID);
		this->addComponentType(PositionComponent::ID);
	}

	void update(double delta_ms) override 
	{
		// TODO:
	};
};

void main(void)
{
	std::cout << "Start programm.\n";

	ecs::ECSManager ecsManager;
	//const ecs::EntityID new_id = ecsManager.makeEntity(entity_components);	
	ecsManager.makeEntity<MovementComponent, PositionComponent>();

	std::cout << "PositionComponent SIZE is " << PositionComponent::SIZE << ", ID is " << PositionComponent::ID << "\n";
	std::cout << "MovementComponent SIZE is " << MovementComponent::SIZE << ", ID is " << MovementComponent::ID << "\n";

	std::cout << "End programm.\n";
	std::cin.get();
}