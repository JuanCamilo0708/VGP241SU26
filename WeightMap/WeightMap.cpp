
#include <iostream>
#include <WeightedGraph.h>
int GetIndex(const Vector<std::string>& nodes, const std::string& input)
{
    for (int i = 0; i < nodes.Size(); ++i)
    {
        if (nodes[i] == input)
        {
            return i;
        }
    }
    return -1;
}



int main()
{
    std::cout << "Custom Weight Graph\n";

    Vector<std::string> nodes;
    nodes.PushBack("A");
    nodes.PushBack("B");
    nodes.PushBack("C");
    nodes.PushBack("D");
    nodes.PushBack("E");

    WeightedGraph<std::string, int> nodeGraph;
    for (std::size_t i = 0; i < nodes.Size(); ++i)
    {
        nodeGraph.AddItem(&nodes[i]);
    }
    nodeGraph.AddEdge(0, 1, 9); 
    nodeGraph.AddEdge(0, 2, 5); 
    nodeGraph.AddEdge(0, 3, 2); 
    nodeGraph.AddEdge(1, 3, 6); 
    nodeGraph.AddEdge(1, 4, 5); 
    nodeGraph.AddEdge(2, 3, 4); 
    nodeGraph.AddEdge(2, 4, 5); 
    nodeGraph.AddEdge(3, 4, 4); 

    std::string input;
    bool done = false;
    int startIndex = -1;
    int endIndex = -1;
    while (!done)
    {
        system("cls");
        std::cout << "Enter Start Point (A-E)\n";
        std::cin >> input;

        startIndex = GetIndex(nodes, input);
        if (startIndex < 0)
        {
            done = input == "done";
            std::cout << "Invalid Input\n";
            std::cout << "Try Again\n";
            system("pause");
            continue;
        }
        std::cout << "Enter endIndex Point (A-E)\n";
        std::cin.clear();
        std::cin >> input;
        endIndex = GetIndex(nodes, input);
        if (endIndex < 0 || endIndex == startIndex)
        {
            done = input == "done";
            std::cout << "Invalid Input\n";
            std::cout << "Try Again\n";
            system("pause");
            continue;
        }

        Vector<const std::string*> path;
        int toalWeight = nodeGraph.GetPath(startIndex, endIndex, path);
        if (path.Size() == 0)
        {
            std::cout << "No path was found from [" << nodes[startIndex] << "-" << nodes[endIndex] << "]\n";
            system("pause");
            continue;
        }
        std::cout << "Path from [" << nodes[startIndex] << "-" << nodes[endIndex] << "]\n";
        for (std::size_t i = 0; i < path.Size(); ++i)
        {
            std::cout << (*path[i]) << " ";
        }
        std::cout << "\n";
        std::cout << "Total Weight: " << toalWeight << "\n";
        system("pause");

    }
}
