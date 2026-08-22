#include "TextureManager.h"
#include <Global.h>
TextureManager* TextureManager::Get()
{
    static TextureManager sInstance;
    return &sInstance;
}

size_t TextureManager::LoadTexture(const std::string& filePath)
{
    size_t key = Global::HashFunction(filePath);
    if (!mTextures.Has(key)) {
        mTextures.Insert(key, filePath);
    }
    return key;
}

std::string TextureManager::LoadTextureById(const size_t key)
{
    return mTextures[key];
}


