#include <stdio.h>
#include <iostream>

#include "Component.h"
#include "ComponentManager.h"

void main(void)
{
	std::cout << "Start programm.\n";

	ecs::BaseComponent bc;
	ecs::ComponentManager cm;

	class PositionComponent;

	const auto cont = cm.GetComponentContainer<PositionComponent>();


	std::cout << "End programm.\n";
	std::cin.get();
}