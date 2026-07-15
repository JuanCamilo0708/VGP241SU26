// ArraysAndVectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Array.h>
#include <Vector.h>
int main()
{
	srand(time(NULL));
	Vector<int> myVector;
	myVector.Resize(10);
	for (std::size_t i = 0; i < myVector.Size(); ++i) {
		std::cout << (myVector[i] += rand()) << "\n";
	}
	myVector.PopBack();
	myVector.PopBack();
	for (std::size_t i = 0; i < myVector.Size(); ++i) {
		std::cout << (myVector[i]) << "\n";
	}


}
void TestArray() {
	Array<int, 10> myCustomArray(0);
	for (int i = 0; i < myCustomArray.Size(); i++)
	{
		myCustomArray[i] = rand() % 100;
		std::cout << myCustomArray[i] << std::endl;
	}

	Array<int, 10> myCustomArray2 = myCustomArray;

	for (int i = 0; i < myCustomArray2.Size(); i++)
	{
		myCustomArray2[i] += 5;
		std::cout << myCustomArray2[i] << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
