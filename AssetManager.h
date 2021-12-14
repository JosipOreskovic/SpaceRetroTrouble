//
// Created by josip on 09.08.2021..
//
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

using namespace sf;
using namespace std;

// Global game constants

const float LEVEL_DISTANCE = 2666.0f;
const float GAME_SPEED = 200.0f;
const float BACKGROUND_SPEED = 100.0f;
const float TILE_DIMENSION = 64.0f;
const float EXPLOSION_SPRITE_DIMENSION = 128.0f;


class AssetManager {
public:
    AssetManager();
    static Texture& GetTexture(string const& filename);
    static Font& GetFont(string const& filename);
    static SoundBuffer& GetSound(string const& filename);

private:
    // A map container from the STL,
    // that holds related pairs of String and Texture
    map<string, Texture> textures_;
    map<string, Font> fonts_;
    map<string, SoundBuffer> sounds_;

    // A pointer of the same type as the class itself
    // the one and only instance
    static AssetManager* instance_;
};

