#include <iostream>
#include <Global.h>
#include <UnorderedMap.h>

void ExerciseSortCheck() {
	Vector<int> numbersBubble;
	Vector<int> numbersSelection;
	std::cout << "Sort Check:\n";
	for (size_t i = 0; i < 10; i++)
	{
		int value = (rand() % 200) + 1;
		numbersBubble.PushBack(value);
		numbersSelection.PushBack(value);
		std::cout << value << " ";
	}

	Global::BubbleSort(numbersBubble);
	Global::SelectionSort(numbersSelection);
	std::cout << "\nBubble Sort:\n";
	for (size_t i = 0; i < numbersBubble.Size(); i++)
	{
		std::cout << numbersBubble[i] << " ";
	}
	std::cout << "\nSelection Sort:\n";
	for (size_t i = 0; i < numbersSelection.Size(); i++)
	{
		std::cout << numbersSelection[i] << " ";
	}
	std::cout << "\n\n";
}
void Exercise2() {
	UnorderedMap<std::size_t, int> map;
	for (rsize_t i = 1; i < 21; i++)
	{
		map.Insert(i, rand() % 200);

	}
	for (rsize_t i = 1; i < 21; i++)
	{
		std::cout << map[i] << " ";
	}
	std::cout << "\nMap has key 30: " << map.Has(30) << "\n";
	int outValue = 0;
	if (map.Find(15, outValue)) {
		std::cout << "Map has key 15: " << outValue << "\n";
	}
	else
	{
		std::cout << "Map does not have key 15\n";

	}
	if (map.Remove(10)) {
		std::cout << "Map Remove key 10\n";
	}
	else
	{
		std::cout << "Map does not have key 10\n";

	}
	map[35] = 2;
	std::cout << "Map value 35: " << map[35] << "\n";
	std::cout << "Map value 40: " << map[40] << "\n";
	map.Clear();

}



int main()
{
	std::cout << "Sorting and Unordered Map\n";
	Exercise2();
}
