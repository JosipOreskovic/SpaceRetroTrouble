//
// Created by josip on 09.08.2021..
//

#include "AssetManager.h"
#include <assert.h>

using namespace sf;
using namespace std;

AssetManager* AssetManager::instance_ = nullptr;

AssetManager::AssetManager()
{
    assert(instance_ == nullptr);
    instance_ = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{
    // Get a reference to m_Textures using m_S_Instance
    auto& m = instance_->textures_;
    // auto is the equivalent of map<string, Texture>

    // Create an iterator to hold a key-value-pair (kvp)
    // and search for the required kvp
    // using the passed in file name
    auto keyValuePair = m.find(filename);
    // auto is equivelant of map<string, Texture>::iterator


    // Did we find a match?
    if (keyValuePair != m.end())
    {
        // Yes
        // Return the texture,
        // the second part of the kvp, the texture
        return keyValuePair->second;
    }
    else
    {
        // File name not found
        // Create a new key value pair using the filename
        auto& texture = m[filename];
        // Load the texture from file in the usual way
        texture.loadFromFile(filename);

        // Return the texture to the calling code
        return texture;
    }
}

Font& AssetManager::GetFont(const string &filename) {
    auto& m = instance_->fonts_;
    auto keyValuePair = m.find(filename);
    if (keyValuePair != m.end())
    {
        return keyValuePair->second;
    }
    else
    {
        auto& font = m[filename];
        font.loadFromFile(filename);
        return font;
    }
}


SoundBuffer& AssetManager::GetSound(const string &filename) {
    auto& m = instance_->sounds_;
    auto keyValuePair = m.find(filename);
    if (keyValuePair != m.end())
    {
        return keyValuePair->second;
    }
    else
    {
        auto& sound = m[filename];
        sound.loadFromFile(filename);
        return sound;
    }
}