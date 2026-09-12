#pragma once

#include <MSTGraph.h>
#include <MSTGraphK.h>
#include "House.h"

class City
{
public:
	void AddHouse(const std::string& name, const Vector2& pos);
	void ConnectAllHouses();
	float GetTotalRoadDistancePrim();
	float GetTotalRoadDistanceKruskal();
private:
	Vector<House> mHouses;
	MSTGraph<House, float> mHousesGraph;
	MSTGraphK<House, float> mHousesEdgeGraph;
};