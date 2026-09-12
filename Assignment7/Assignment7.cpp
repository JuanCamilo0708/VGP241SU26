#include <iostream>
#include "City.h"
int main()
{
    std::cout << "City Graphs!\n";
    City city;

    city.AddHouse("A", { 20.0f, 40.0f });
    city.AddHouse("B", { 50.0f, 20.0f });
    city.AddHouse("C", { 90.0f, 40.0f });
    city.AddHouse("D", { 60.0f, 80.0f });
    city.AddHouse("E", { 30.0f, 120.0f });
    city.AddHouse("F", { 100.0f, 110.0f });
    city.AddHouse("G", { 150.0f, 130.0f });
    city.AddHouse("H", { 160.0f, 90.0f });
    city.AddHouse("I", { 140.0f, 60.0f });
    city.AddHouse("J", { 180.0f, 30.0f });
    city.AddHouse("K", { 200.0f, 120.0f });
    city.AddHouse("L", { 220.0f, 70.0f });
    city.AddHouse("M", { 240.0f, 50.0f });

    city.ConnectAllHouses();
    float totalWeightPrim = city.GetTotalRoadDistancePrim();
    std::cout << "The total cost for the road is " << totalWeightPrim * 10 << "$\n";
    float totalWeightKrus = city.GetTotalRoadDistanceKruskal();
    std::cout << "The total cost for the road is " << totalWeightKrus * 10 << "$\n";

    
}
