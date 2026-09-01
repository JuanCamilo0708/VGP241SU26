// AdvanceSorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Global.h>
void PrintVectorInt(Vector<int>& vec) {
	for (int i = 0; i < 20; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}
void Exercise1() {
	std::cout << "Insertion Sort\n";
	Vector<int> numbers;
	for (int i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		numbers.PushBack(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	Global::InsertionSort(numbers.begin(), numbers.end());
	PrintVectorInt(numbers);
}
void Exercise2() {
	std::cout << "Merge Sort\n";
	Vector<int> numbers;
	for (int i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		numbers.PushBack(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	Global::MergeSort(numbers.begin(), numbers.end());
	PrintVectorInt(numbers);
}
void Exercise3() {
	std::cout << "Quick Sort\n";
	Vector<int> numbers;
	for (int i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		numbers.PushBack(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	Global::QuickSort(numbers.begin(), numbers.end());
	PrintVectorInt(numbers);
}
void Exercise4() {
	std::cout << "Bucket Sort\n";
	Vector<int> numbers;
	for (int i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		numbers.PushBack(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	Global::BucketSort(numbers.begin(), numbers.end());
	PrintVectorInt(numbers);
}
void Exercise5() {
	std::cout << "Heap Sort\n";
	Vector<int> numbers;
	for (int i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		numbers.PushBack(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	Global::HeapSort(numbers.begin(), numbers.end());
	PrintVectorInt(numbers);
}
void Exercise6() {
	std::cout << "Intro Sort\n";
	Vector<int> numbers;
	for (int i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		numbers.PushBack(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	Global::IntroSort(numbers.begin(), numbers.end());
	PrintVectorInt(numbers);
}
int main()
{
	srand(time(NULL));
	Exercise1();
	Exercise2();
	Exercise3();
	Exercise4();
	Exercise5();
	Exercise6();
}

