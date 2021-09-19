#pragma once
#include <SFML/Audio.hpp>
#include "AssetManager.h"

using namespace sf;

class SoundManager
{
public:
    SoundManager();
    void playObjectExplosionSound();
    void playPlayerExplosionSound();
private:
    Sound objectExplosionSound_;
    Sound playerExplosionSound_;
};

