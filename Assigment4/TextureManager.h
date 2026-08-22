#pragma once
#include <string>
#include <UnorderedMap.h>
class TextureManager {
public:
	static TextureManager* Get();
	size_t LoadTexture(const std::string& filePath);
	std::string LoadTextureById(const size_t key);

private:
	UnorderedMap < size_t, std::string> mTextures;
};