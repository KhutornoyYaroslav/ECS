#include <stdio.h>
#include <iostream>

#include "Manager.h"
#include "Component.h"
#include "ECS_HEADER_ONLY.h"

class PositionComponent : public ecs::Component<PositionComponent>
{
public:
	PositionComponent(int v1, int v2, double v3) : val1(v1), val2(v2), val3(v3) {};

	int val1;
	int val2;
	double val3;
};

struct MovementComponent : public ecs::Component<MovementComponent>
{
public:
	MovementComponent(int v) : val1(v) {};

	int val1;
};

class MovingSystem : public ecs::System<MovingSystem>
{
private:
	double m_speed = 0.0;

public:

	explicit MovingSystem(double speed) : m_speed(speed)
	{
	};

	MovingSystem()
	{
		///this->addComponentType(MovementComponent::ID);
		//this->addComponentType(PositionComponent::ID);
	}

	void update(double delta_ms) override 
	{
	};
};

class RenderSystem : public ecs::System<RenderSystem>
{
public:
	void update(double delta_ms) override
	{
	};
};

//// TODO: 
//class RenderSystem2 : public ecs::System<RenderSystem>
//{
//public:
//	void update(double delta_ms) override
//	{
//	};
//};



int main(void)
{
	ecs::Manager ecsManager;
	//const auto newEntityId = ecsManager.makeEntity();
	//ecsManager.assignComponentToEntity<PositionComponent>(newEntityId, 10, 20, 3.3);
	//ecsManager.assignComponentToEntity<MovementComponent>(newEntityId, 123);
	std::cout << "PositionComponent SIZE is " << PositionComponent::SIZE << ", ID is " << PositionComponent::ID << "\n";
	std::cout << "MovementComponent SIZE is " << MovementComponent::SIZE << ", ID is " << MovementComponent::ID << "\n";

	///ECS::World::tick

	ecsManager.registerSystem<MovingSystem>(25.0);
	ecsManager.registerSystem<RenderSystem>();


	///*ecsManager.enableSystem<MovingSystem>();
	//ecsManager.enableSystem<RenderSystem>();
	//ecsManager.disableSystem<MovingSystem>();
	//ecsManager.disableSystem<RenderSystem>();
	//
	//ecsManager.unregisterSystem<MovingSystem>();
	//ecsManager.unregisterSystem<RenderSystem>();*/

	
	//ecsManager.updateSystems(33);

	//std::map<bool, double*> mapp;
	//auto find_it = mapp.find(true);
	//find_it->
	//const auto sys = ecsManager.registerSystem<MovingSystem>();

	std::cin.get();
	return 0;
}