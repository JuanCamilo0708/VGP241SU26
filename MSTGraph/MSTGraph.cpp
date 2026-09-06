// MSTGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <MSTGraph.h>
#include <MSTGraphK.h>
void Exercise1()
{
	std::cout << "Test MST: \n";
	Vector<std::string> nodes;
	nodes.PushBack("A");
	nodes.PushBack("B");
	nodes.PushBack("C");
	nodes.PushBack("D");
	nodes.PushBack("E");

	MSTGraph<std::string, int> mstGraph;
	for (std::size_t i = 0; i < nodes.Size(); ++i)
	{
		mstGraph.AddItem(&nodes[i]);
	}

	mstGraph.AddLink(0, 1, 9);
	mstGraph.AddLink(0, 2, 5);
	mstGraph.AddLink(0, 3, 2);
	mstGraph.AddLink(1, 3, 6);
	mstGraph.AddLink(1, 4, 5);
	mstGraph.AddLink(2, 3, 4);
	mstGraph.AddLink(2, 4, 5);
	mstGraph.AddLink(3, 4, 4);

	Vector<const std::string*> mst;
	Vector<const std::string*> links;

	int totalWeight = 0;
	mstGraph.ObtainMST(0, mst, links, totalWeight);
	std::cout << "Mst Nodes:\n";
	for (std::size_t i = 0; i < mst.Size(); ++i)
	{
		std::cout << (*mst[i]) << " ";
	}
	std::cout << "\n";
	std::cout << "Link Nodes:\n";
	for (std::size_t i = 0; i < links.Size(); ++i)
	{
		if (links[i] != nullptr)
		{

			std::cout << nodes[i] << "-" << (*links[i]) << "\n";
		}
	}
	std::cout << "Total Weight: " << totalWeight << "\n";


}
void Exercise2() 
{

	std::cout << "Test MSTK: \n";
	Vector<std::string> nodes;
	nodes.PushBack("A");
	nodes.PushBack("B");
	nodes.PushBack("C");
	nodes.PushBack("D");
	nodes.PushBack("E");

	MSTGraphK<std::string, int> mstGraph;
	for (std::size_t i = 0; i < nodes.Size(); ++i)
	{
		mstGraph.AddItem(&nodes[i]);
	}

	mstGraph.AddEdge(0, 1, 9);
	mstGraph.AddEdge(0, 2, 5);
	mstGraph.AddEdge(0, 3, 2);
	mstGraph.AddEdge(1, 3, 6);
	mstGraph.AddEdge(1, 4, 5);
	mstGraph.AddEdge(2, 3, 4);
	mstGraph.AddEdge(2, 4, 5);
	mstGraph.AddEdge(3, 4, 4);

	Vector<const std::string*> mst;
	Vector<const std::string*> links;

	int totalWeight = 0;
	mstGraph.ObtainMST(mst, links, totalWeight);
	std::cout << "Mst Nodes:\n";
	for (std::size_t i = 0; i < mst.Size(); ++i)
	{
		std::cout << (*mst[i]) << " ";
	}
	std::cout << "\n";
	std::cout << "Link Nodes:\n";
	for (std::size_t i = 0; i < links.Size(); ++i)
	{
		if (links[i] != nullptr)
		{

			std::cout << nodes[i] << "-" << (*links[i]) << "\n";
		}
	}
	std::cout << "Total Weight: " << totalWeight << "\n";


}
int main()
{
	Exercise1();
	Exercise2();
}