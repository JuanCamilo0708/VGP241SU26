// IteratorsAndPriorityQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Array.h>
#include <Vector.h>
#include <PriorityQueue.h>
void Exercise1() {
	Array<int, 20> arrayNumbers;
	Vector<int> vectorNumbers;
	PriorityQueue<int> pq;
	for (int i = 0; i < 20; ++i) {
		arrayNumbers[i] = (rand() % 100) + 1;
		int value = (rand() % 100) + 1;
		vectorNumbers.PushBack(value);
		pq.Push(value);
	}
	std::cout << "Iterate Through Array:";
	for (Array<int, 20>::Iterator it = arrayNumbers.begin(); it != arrayNumbers.end(); ++it) {
		std::cout << (*it) << " ";
	}
	std::cout << "\n\n";
	std::cout << "Iterate Through Array:";
	for (Vector<int>::Iterator it = vectorNumbers.begin(); it != vectorNumbers.end(); ++it) {
		std::cout << (*it) << " ";
	}
	std::cout << "\n\n";
	std::cout << "Priority Queue:";
	for (int i = 0; i < 20; i++)
	{
		std::cout << pq.Top() << " ";
		pq.Pop();
	}
}
int main()
{
	Exercise1();

}
