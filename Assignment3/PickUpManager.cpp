#include "PickUpManager.h"
void PickUpManager::AddItem(PickUpType pickUpType, const Vector3& pos)
{
	if (pickUpType == Invalid) {
		std::cout << "Invalid Pick up type";
		return;
	}
	PickUp pickUp(pickUpType, pos);
	mPickUps.PushBack(pickUp);

	mPositions.AddItem(&pos.x, &mPickUps[mPickUps.Size() - 1]);
}

const PickUp* PickUpManager::GetClosestPickUp(const Vector3& pos)
{
	PickUp* pickUp = (PickUp*)mPositions.FindNearest(&pos.x);
	return pickUp;
}

Vector<const void*> PickUpManager::ObtainPickUpskInRange(const Vector3& pos, float range, PickUpType pickUpType)
{
	Vector3 minRange(pos.x - range, pos.y - range, pos.z - range);
	Vector3 maxRange(pos.x + range, pos.y + range, pos.z + range);

	Vector<const void*> pickUpInRange;

	mPositions.FindInRange(pickUpInRange, &minRange.x, &maxRange.x);

	Vector<const void*> result;
	for (auto pickUp : pickUpInRange) {
		const PickUp* tmpPickUp = (PickUp*)(pickUp);
		if (pickUpType == Invalid || tmpPickUp->GetType() == pickUpType) {
			result.PushBack(tmpPickUp);
		}
	}
	return result;

}

void PickUpManager::BuildKD()
{
	mPositions.BuildTree();
}
