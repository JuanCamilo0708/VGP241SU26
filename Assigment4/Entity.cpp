#include "Entity.h"
#include "TextureManager.h"
#include "Texture.h"
void Entity::Initialize(const std::string& textureFilePath)
{
	mTextureId = TextureManager::Get()->LoadTexture(textureFilePath);
	mPos = { (float)(rand() % 200),(float)(rand() % 200) };
}

void Entity::Update()
{
	mPos = { (float)(rand() % 400) - 200, (float)(rand() % 400) - 200 };
}

void Entity::Render()
{
	Texture texture = TextureManager::Get()->LoadTextureById(mTextureId);
	texture.Print();
	std::cout << "Position ( " << mPos.x << ", " << mPos.y << ")\n";
}

bool Entity::operator<(const Entity& rhs) const
{
	return SquaredDistance(mPos) < SquaredDistance(rhs.mPos);
}

float Entity::SquaredDistance(Vector2 vec) const
{
	return (mPos.x*mPos.x) + (mPos.y * mPos.y);
}

