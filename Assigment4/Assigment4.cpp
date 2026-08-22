// Assigment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Vector.h>
#include "Entity.h"
#include <Global.h>
int main()
{
	Vector<Entity> myEntities;
	myEntities.PushBack(Entity());
	myEntities.PushBack(Entity());
	myEntities[0].Initialize("Player 1");
	myEntities[1].Initialize("Player 2");

	for (int i = 2; i < 22; i++)
	{
		myEntities.PushBack(Entity());
		myEntities[i].Initialize("Enemy" + std::to_string(i - 1));

	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < myEntities.Size(); j++)
		{
			myEntities[j].Update();
		}
		Global::BubbleSort(myEntities);
		for (int j = 0; j < myEntities.Size(); j++)
		{
			myEntities[j].Render();
		}
	}

}

