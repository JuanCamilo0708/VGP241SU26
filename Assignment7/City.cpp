#include "City.h"
float DistanceHouseToHouse(House& a, House& b)
{
	Vector2 vectorDist = b.mPosition - a.mPosition;
	return std::sqrtf((vectorDist.x * vectorDist.x) + (vectorDist.y * vectorDist.y));
}
void City::AddHouse(const std::string& name, const Vector2& pos)
{
	for (std::size_t i = 0; i < mHouses.Size(); i++)
	{
		if (mHouses[i].mPosition == pos)
		{
			return;
		}
	}
	mHouses.PushBack(House(name, pos));
}

void City::ConnectAllHouses()
{
	for (std::size_t i = 0; i < mHouses.Size(); i++)
	{
		mHousesGraph.AddItem(&mHouses[i]);
		mHousesEdgeGraph.AddItem(&mHouses[i]);
	}
	for (std::size_t i = 0; i < mHouses.Size(); i++)
	{
		for (std::size_t j = i+1; j < mHouses.Size(); j++)
		{
			float distance = DistanceHouseToHouse(mHouses[i], mHouses[j]);
			if (distance < 75.0f)
			{
				mHousesGraph.AddLink(i, j, distance);
				mHousesEdgeGraph.AddEdge(i, j, distance);
			}
		}
	}
}

float City::GetTotalRoadDistancePrim()
{
	Vector<const House*> mst;
	Vector<const House*> links;

	float totalWeight = 0;
	mHousesGraph.ObtainMST(0,mst, links, totalWeight);
	std::cout << "Mst Nodes:\n";
	for (std::size_t i = 0; i < mst.Size(); ++i)
	{
		std::cout << mst[i]->mName << " ";
	}
	std::cout << "\n";
	std::cout << "Link Nodes:\n";
	for (std::size_t i = 0; i < links.Size(); ++i)
	{
		if (links[i] != nullptr)
		{

			std::cout << mHouses[i].mName << "-" << (links[i]->mName) << "\n";
		}
	}

	return totalWeight;
}

float City::GetTotalRoadDistanceKruskal()
{
	Vector<const House*> mst;
	Vector<const House*> links;

	float totalWeight = 0;
	mHousesEdgeGraph.ObtainMST(mst, links, totalWeight);
	std::cout << "Mst Nodes:\n";
	for (std::size_t i = 0; i < mst.Size(); ++i)
	{
		std::cout << mst[i]->mName << " ";
	}
	std::cout << "\n";
	std::cout << "Link Nodes:\n";
	for (std::size_t i = 0; i < links.Size(); ++i)
	{
		if (links[i] != nullptr)
		{

			std::cout << mHouses[i].mName << "-" << (links[i]->mName) << "\n";
		}
	}

	return totalWeight;
}

