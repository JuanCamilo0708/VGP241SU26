#pragma once
#include <string>
#include <Vector3.h>
enum PickUpType {
    Invalid = -1,
    Health, 
    WeaponAmmo, 
    Coins, 
    Upgrade, 
    SpecialItem
};
const std::string PickUpNames[] =
{
    "Health",
    "WeaponAmmo",
    "Coins",
    "Upgrade",
    "SpecialItem"
};
class PickUp {
public:
    PickUp() : 
        mName(""),
        mPosition(),
        mType(Invalid)
    {
    }
    PickUp(PickUpType pickUpType, const Vector3& pos):
        mType(pickUpType),
        mName(PickUpNames[pickUpType]),
        mPosition(pos)
    {
    }
    std::string GetName() const {
        return mName;
    }
    Vector3 GetPosition() const {
        return mPosition;
    }
    PickUpType GetType() const  { 
        return mType; 
    }
private:
    PickUpType mType;
    std::string mName;
    Vector3 mPosition;
};