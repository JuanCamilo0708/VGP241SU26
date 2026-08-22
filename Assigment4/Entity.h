#pragma once
#include <Vector2.h>
#include <string>
class Entity {
public:

	void Initialize(const std::string& textureFilePath);
	void Update();
	void Render();
	bool operator<(const Entity& rhs) const;
private:
	float SquaredDistance(Vector2 vec) const;
	size_t mTextureId;
	Vector2 mPos;
};