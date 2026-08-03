#include <iostream>
#include <string>
#include "PickUpManager.h"

// Simple Vector3


int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    PickUpManager manager;

    // 4a. Create 100 random pickups
    for (int i = 0; i < 100; ++i)
    {
        PickUpType type = static_cast<PickUpType>((std::rand() % 5) + 1);
        Vector3 pos(rand() % 501);
        manager.AddItem(type, pos);
    }

    // Build KDTree after all items added
    manager.BuildKD();

    // 4b. Player position
    Vector3 playerPos(250.0f);

    // 4c. Attract range 10.0f
    float attractRange = 10.0f;
    auto pickedUp = manager.ObtainPickUpskInRange(playerPos, attractRange, PickUpType::Invalid);

    std::cout << "Pickups within 10.0f of player:\n";
    for (const void* p : pickedUp)
    {
        PickUp* pickUp = (PickUp*)p;
        std::cout << " - " << pickUp->GetName() << " at " << pickUp->GetPosition().ToString() << "\n";
    }
    // 4d. Low health: find health pickups within 50.0f
    float healthRange = 50.0f;
    std::cout << "Health within 50.0f of player";
    auto healthPickups = manager.ObtainPickUpskInRange(playerPos, healthRange, PickUpType::Health);

    for (const void* p : healthPickups)
    {
        PickUp* pickUp = (PickUp*)p;
        std::cout << " - " << pickUp->GetName() << " at " << pickUp->GetPosition().ToString() << "\n";
    }

    // 4e. Closest pickup
    const PickUp* closest = manager.GetClosestPickUp(playerPos);
    if (closest)
    {
        std::cout << "\nClosest pickup to player:\n";
        std::cout << " - " << closest->GetName() << " at " << closest->GetPosition().ToString() << "\n";
    }
    else
    {
        std::cout << "\nNo pickups found.\n";
    }

    return 0;
}