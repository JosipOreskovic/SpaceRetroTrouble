#pragma once
#include <SFML/Audio.hpp>
#include "AssetManager.h"

class SoundManager
{
public:
    SoundManager();
    void playObjectExplosionSound();
    void playPlayerExplosionSound();
private:
    sf::Sound objectExplosionSound_;
    sf::Sound playerExplosionSound_;
};

