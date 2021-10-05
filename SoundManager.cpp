#include "SoundManager.h"


SoundManager::SoundManager()
{
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
