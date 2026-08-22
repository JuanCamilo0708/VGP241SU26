#pragma once

#include <algorithm>
#include <functional>
#include "Vector.h"

template<typename KeyType, typename ValueType>
class UnorderedMap
{
private:
	struct KeyValuePair {
		KeyType key;
		ValueType value;
	};
public:
	UnorderedMap(std::size_t initialBucketSize = 8, double loadFactor = 0.8)
		: mLoadFactorThreashold(loadFactor),
		mCount(0)
	{
		mBucketCount = std::max<std::size_t>(initialBucketSize, 1);
		mTable.Resize(mBucketCount);
	}

	UnorderedMap(const UnorderedMap&) = delete;
	UnorderedMap(UnorderedMap&&) = delete;
	UnorderedMap& operator=(const UnorderedMap&) = delete;
	UnorderedMap& operator=(UnorderedMap&&) = delete;

	void Insert(const KeyType& key, const ValueType& value) {
		std::size_t index = GetTableIndex(key);
		Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < bucket.Size(); i++)
		{
			if (bucket[i]->key == key) {
				bucket[i]->value = value;
				return;
			}

		}
		KeyValuePair* kv = new KeyValuePair();
		kv->key = key;
		kv->value = value;
		mTable[index].PushBack(kv);
		++mCount;
		if ((double)mCount / (double)mBucketCount > mLoadFactorThreashold) {
			Rehash();
		}
	}
	bool Find(const KeyType& key, ValueType& outValue) const {
		std::size_t index = GetTableIndex(key);
		const Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < bucket.Size(); i++)
		{
			if (bucket[i]->key == key) {
				outValue = bucket[i]->value;
				return true;
			}
		}
		return false;
	}
	bool Has(const KeyType& key) const {
		std::size_t index = GetTableIndex(key);
		const Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < bucket.Size(); i++)
		{
			if (bucket[i]->key == key) {
				return true;
			}
		}
		return false;

	}
	bool Remove(const KeyType& key) {
		std::size_t index = GetTableIndex(key);
		Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < bucket.Size(); i++)
		{
			if (bucket[i]->key == key) {
				KeyValuePair* tmp = bucket[i];
				bucket[i] = bucket[bucket.Size() - 1];
				bucket[bucket.Size() - 1] = tmp;

				delete tmp;
				tmp = nullptr;
				bucket.PopBack();
				return true;
			}
		}
		return false;
	}
	std::size_t Count() const {
		return mCount;
	}
	void Clear() {
		for (size_t t = 0; t < mTable.Size(); t++)
		{
			Vector<KeyValuePair*>& bucket = mTable[t];
			for (size_t b = 0; b < bucket.Size(); b++)
			{
				delete bucket[b];
				bucket[b] = nullptr;

			}
			bucket.Clear();
		}
		mCount = 0;
	}

	ValueType& operator[](const KeyType& key) {
		if (!Has(key)) {
			Insert(key, mDefault);
		}
		std::size_t index = GetTableIndex(key);
		Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < bucket.Size(); i++)
		{
			if (bucket[i]->key == key) {
				return bucket[i]->value;
			}
		}
		assert(false, "UnorderedMap: Key never gets added");
		return mDefault;

	}
	const ValueType& operator[](const KeyType& key) const {
		std::size_t index = GetTableIndex(key);
		Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < bucket.Size(); i++)
		{
			if (bucket[i]->key == key) {
				return bucket[i]->value;
			}
		}
		return mDefault;

	}
	
private:
	std::size_t GetTableIndex(const KeyType& key) const {
		return mHashFunction(key) % mBucketCount;
	}
	void Rehash() {
		std::size_t newBucketCount = mBucketCount * 2;
		Vector<Vector<KeyValuePair*>> newTable;
		newTable.Resize(newBucketCount);

		mCount = newBucketCount;
		for (size_t t = 0; t < mTable.Size(); t++)
		{
			Vector<KeyValuePair*>& bucket = mTable[t];
			for (size_t b = 0; b < bucket.Size(); b++)
			{
				std::size_t index = GetTableIndex(bucket[b]->key);
				newTable[index].PushBack(bucket[b]);
			}
			bucket.Clear();
		}
		mTable = std::move(newTable);
		newTable.Clear();
	}
	ValueType mDefault;
	Vector<Vector<KeyValuePair*>> mTable;
	std::size_t mBucketCount = 0;
	std::size_t mCount = 0;
	double mLoadFactorThreashold = 1.0;
	std::hash<KeyType> mHashFunction;

};