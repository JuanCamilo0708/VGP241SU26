// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Graph.h>

void Exercise1() {
	Graph<int> myGraph;
	Vector<int> graphData;
	for (int i = 0; i < 10; ++i) {
		graphData.PushBack(i);
	}
	for (int i = 0; i < graphData.Size(); ++i) {
		myGraph.AddItem(&graphData[i]);
	}
	myGraph.AddLink(0, 1);
	myGraph.AddLink(0, 2);
	myGraph.AddLink(1, 3);
	myGraph.AddLink(1, 4);
	myGraph.AddLink(0, 5);
	myGraph.AddLink(2, 5);
	myGraph.AddLink(2, 6);
	myGraph.AddLink(3, 7);
	myGraph.AddLink(4, 8);
	myGraph.AddLink(4, 7);
	myGraph.AddLink(5, 9);
	myGraph.PrintGraph();

	Vector<const int*> dfsConnections;
	Vector<const int*> bfsConnections;

	myGraph.GetAllConnectionsDFS(0, dfsConnections);
	myGraph.GetAllConnectionsBFS(0, bfsConnections);

	std::cout << "Connections (DFS):\n";
	for (size_t i = 0; i < dfsConnections.Size(); i++)
	{
		std::cout << (*dfsConnections[i]) << " ";
	}
	std::cout << "\n\nConnections (BFS):\n";
	for (size_t i = 0; i < bfsConnections.Size(); i++)
	{
		std::cout << (*bfsConnections[i]) << " ";
	}
	std::cout << "\n\n";

	int startIndex = 0;
	int endIndex = 9;
	Vector<const int*> pathDFS;
	Vector<const int*> pathBFS;
	std::cout << "Path from " << startIndex << " - " << endIndex << " (DFS)\n";
	if (myGraph.GetPathDFS(startIndex, endIndex, pathDFS)) {
		for (int i = pathDFS.Size() - 1; i >= 0; i--)
		{
			std::cout << (*pathDFS[i]) << " ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << "Path is not found!\n";
	}
	std::cout << "\n\n";
	std::cout << "Path from " << startIndex << " - " << endIndex << " (BFS)\n";
	if (myGraph.GetPathBFS(startIndex, endIndex, pathBFS)) {
		for (int i = pathBFS.Size() - 1; i >= 0; i--)
		{
			std::cout << (*pathBFS[i]) << " ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << "Path is not found!\n";
	}
}
void Exercise2() {

	Vector<std::string> cities;
	cities.PushBack("Vancouver");			//0
	cities.PushBack("Burnaby");				//1
	cities.PushBack("North_Vancouver");		//2
	cities.PushBack("Delta");				//3
	cities.PushBack("Richmond");			//4
	cities.PushBack("New_West");			//5
	cities.PushBack("Victoria");			//6
	cities.PushBack("Nanaimo");				//7
	cities.PushBack("Quesnel");				//8
	cities.PushBack("Langley");				//9
	cities.PushBack("Abbostford");			//10
	cities.PushBack("Maple_Ridge");			//11
	cities.PushBack("Coquitlam");			//12
	cities.PushBack("Surrey");				//13


	Graph<std::string> citiesGraph;

	for (size_t i = 0; i < cities.Size(); i++)
	{
		citiesGraph.AddItem(&cities[i]);
	}

	citiesGraph.AddLink(0, 1);
	citiesGraph.AddLink(0, 4);
	citiesGraph.AddLink(0, 2);
	citiesGraph.AddLink(1, 5);
	citiesGraph.AddLink(1, 12);
	citiesGraph.AddLink(3, 4);
	citiesGraph.AddLink(3, 5);
	citiesGraph.AddLink(3, 13);
	citiesGraph.AddLink(4, 5);
	citiesGraph.AddLink(5, 12);
	citiesGraph.AddLink(5, 13);
	citiesGraph.AddLink(6, 7);
	citiesGraph.AddLink(9, 10);
	citiesGraph.AddLink(9, 11);
	citiesGraph.AddLink(9, 13);
	citiesGraph.AddLink(10, 13);
	citiesGraph.AddLink(11, 12);
	citiesGraph.AddLink(12, 13);

	citiesGraph.PrintGraph();
	Vector<const std::string*> dfsConnections;
	Vector<const std::string*> bfsConnections;

	citiesGraph.GetAllConnectionsDFS(0, dfsConnections);
	citiesGraph.GetAllConnectionsBFS(0, bfsConnections);
	for (size_t i = 0; i < dfsConnections.Size(); i++)
	{
		std::cout << (*dfsConnections[i]) << " ";
	}
	std::cout << "\n\nConnections (BFS):\n";
	for (size_t i = 0; i < bfsConnections.Size(); i++)
	{
		std::cout << (*bfsConnections[i]) << " ";
	}
	std::cout << "\n\n";
	int startIndex = 0;
	int endIndex = 10;

	Vector<const std::string*> pathDFS;
	Vector<const std::string*> pathBFS;
	std::cout << "Path from " << startIndex << " - " << endIndex << " (DFS)\n";
	if (citiesGraph.GetPathDFS(startIndex, endIndex, pathDFS)) {
		for (int i = pathDFS.Size() - 1; i >= 0; i--)
		{
			std::cout << (*pathDFS[i]) << " ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << "Path is not found!\n";
	}
	std::cout << "\n\n";
	std::cout << "Path from " << startIndex << " - " << endIndex << " (BFS)\n";
	if (citiesGraph.GetPathBFS(startIndex, endIndex, pathBFS)) {
		for (int i = pathBFS.Size() - 1; i >= 0; i--)
		{
			std::cout << (*pathBFS[i]) << " ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << "Path is not found!\n";
	}
}

int main()
{
	Exercise2();
}
