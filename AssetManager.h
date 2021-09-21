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

const float LEVEL_DISTANCE = 2666;
const float GAME_SPEED = 200;
const float TILE_DIMENSION = 64;


class AssetManager {
public:
    AssetManager();
    static Texture& GetTexture(string const& filename);
    static Font& GetFont(string const& filename);
    static SoundBuffer& GetSound(string const& filename);
    //static Music& GetMusic(string const& filename);

private:
    // A map container from the STL,
    // that holds related pairs of String and Texture
    map<string, Texture> textures_;
    map<string, Font> fonts_;
    map<string, SoundBuffer> sounds_;
    //map<string, Music> music;

    // A pointer of the same type as the class itself
    // the one and only instance
    static AssetManager* instance_;
};

