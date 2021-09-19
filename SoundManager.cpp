#include "SoundManager.h"


SoundManager::SoundManager()
{
    // Load the sound in to the buffers
    //explosionBuffer.loadFromFile("Assets/Sound/objectExplosion.wav");
    objectExplosionSound_.setBuffer(AssetManager::GetSound("Assets/Sound/objectExplosion.wav"));
    playerExplosionSound_.setBuffer(AssetManager::GetSound("Assets/Sound/playerExplosion.wav"));
}

void SoundManager::playObjectExplosionSound()
{
    objectExplosionSound_.play();
}

void SoundManager::playPlayerExplosionSound()
{
    playerExplosionSound_.play();
}
