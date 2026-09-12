#pragma once


#include "PriorityQueue.h"
#include <limits>

template<typename T, typename W>
class WeightedGraph
{
private:
	struct Edge
	{
		int nodeIndex = -1;
		W weight;

		bool operator>(const Edge& rhs) const { return weight > rhs.weight; }
		bool operator>=(const Edge& rhs) const { return weight >= rhs.weight; }
		bool operator==(const Edge& rhs) const { return weight == rhs.weight; }
		bool operator<=(const Edge& rhs) const { return weight <= rhs.weight; }
		bool operator<(const Edge& rhs) const { return weight < rhs.weight; }
	};
	struct Node
	{
		const T* data = nullptr;
		Vector<Edge> edges;
		Node* parent = nullptr;
		W totalWeight;
	};
public:
	WeightedGraph()
	{

	}
	~WeightedGraph()
	{
		Terminate();
	}
	std::size_t AddItem(const T* data)
	{
		Node* node = new Node();
		node->data = data;
		mNodes.PushBack(node);
		return mNodes.Size() - 1;
	}
	void AddEdge(std::size_t a, std::size_t b, W weight)
	{
		if (a >= mNodes.Size() || b >= mNodes.Size())
		{
			return;
		}

		Edge edgeA = { b, weight };
		Edge edgeB = { a, weight };
		mNodes[a]->edges.PushBack(edgeA);
		mNodes[b]->edges.PushBack(edgeB);

	}
	W GetPath(int start, int end, Vector<const T*>& pathOutput)
	{
		Reset();
		PriorityQueue<Edge, std::greater<Edge>> process;
		mNodes[start]->totalWeight = 0;
		process.Push({ start,0 });
		while (!process.Empty())
		{
			Edge edge = process.Top();
			process.Pop();
			Node* node = mNodes[edge.nodeIndex];
			if (edge.weight > node->totalWeight)
			{
				continue;
			}
			if (edge.nodeIndex == end)
			{
				break;
			}
			for (std::size_t i = 0; i < node->edges.Size(); i++)
			{
				const Edge& toEdge = node->edges[i];
				Node* toNode = mNodes[toEdge.nodeIndex];

				if (node->totalWeight < std::numeric_limits<W>::max() && node->totalWeight + toEdge.weight < toNode->totalWeight)
				{
					toNode->totalWeight = node->totalWeight + toEdge.weight;
					toNode->parent = node;
					process.Push(toEdge);
				}
			}
		}
		pathOutput.Clear();
		Node* node = mNodes[end];
		W totalWeight = node->totalWeight;
		while (node != nullptr)
		{
			pathOutput.PushBack(node->data);
			node = node->parent;
		}
		std::reverse(pathOutput.begin(), pathOutput.end());
		return totalWeight;
	}
	void Terminate()
	{
		for (std::size_t i = 0; i < mNodes.Size(); i++)
		{
			delete mNodes[i];
			mNodes[i] = nullptr;
		}
		mNodes.Clear();
	}
private:
	void Reset()
	{
		for (std::size_t i = 0; i < mNodes.Size(); i++)
		{
			mNodes[i]->parent = nullptr;
			mNodes[i]->totalWeight = std::numeric_limits<W>::max();
		}
	}
	Vector<Node*> mNodes;
};