//
// Created by josip on 09.08.2021..
//
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>


// Global game constants

const float LEVEL_DISTANCE = 2666.0f;
const float GAME_SPEED = 200.0f;
const float BACKGROUND_SPEED = 100.0f;
const float TILE_DIMENSION = 64.0f;
const float EXPLOSION_SPRITE_DIMENSION = 128.0f;


class AssetManager {
public:
    AssetManager();
    static sf::Texture& GetTexture(std::string const& filename);
    static sf::Font& GetFont(std::string const& filename);
    static sf::SoundBuffer& GetSound(std::string const& filename);

private:
    // A map container from the STL,
    // that holds related pairs of String and Texture
    std::map<std::string, sf::Texture> textures_;
    std::map<std::string, sf::Font> fonts_;
    std::map<std::string, sf::SoundBuffer> sounds_;

    // A pointer of the same type as the class itself
    // the one and only instance
    static AssetManager* instance_;
};

