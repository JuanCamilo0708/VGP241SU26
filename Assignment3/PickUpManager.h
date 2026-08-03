#pragma once
#include "PickUp.h"
#include <Vector.h>
#include <KDTree.h>
class PickUpManager
{
public:
	void AddItem(PickUpType pickUpType, const Vector3& pos);
	const PickUp* GetClosestPickUp(const Vector3& pos);
	Vector<const void*> ObtainPickUpskInRange(const Vector3& pos, float range, PickUpType pickUpType);
	void BuildKD();

	KDTree<float, 3> mPositions;
private:
	Vector<PickUp> mPickUps;

};
