
#include "Game.h"
#include "TankMissile.h"

void Game::detectCollision(Player& player, GameObject*& gameObject, Time totalTime, bool destruct)
{
        if (player.getShipSprite().getGlobalBounds().intersects(gameObject->getSprite().getGlobalBounds()) && player.isActive() && gameObject->isActive())
        {
            player.hit(player.getPosition(), totalTime);
            soundManager_.playPlayerExplosionSound();
            if (destruct)
                gameObject->hit();
            lives_--;
        }
}


void Game::detectCollision(Player& player, vector<GameObject*>& gameObjects, Time totalTime, bool destruct)
{
    for (const auto& gameObject : gameObjects)
    {
        if (player.getShipSprite().getGlobalBounds().intersects(gameObject->getSprite().getGlobalBounds()) && player.isActive() && gameObject->isActive())
        {
            player.hit(player.getPosition(), totalTime);
            soundManager_.playPlayerExplosionSound();
            if (destruct)
            {
                gameObject->hit();
            }
            lives_--;
        }
    }
}


void Game::detectCollision(const vector<GameObject*>& playerObjects, const vector<GameObject*>& gameObjects, Time totalTime,
     bool destruct, int score, int fuel)
{
    for (const auto& playerObject : playerObjects)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (playerObject->isActive() && gameObject->isActive() && (playerObject->getSprite().getGlobalBounds().intersects(gameObject->getSprite().getGlobalBounds())))
            {
                playerObject->hit();
                if (destruct)
                {
                    gameObject->hit();
                    soundManager_.playObjectExplosionSound();
                    score_ += score;
                    player.setFuelLevel(fuel);
                }
            }
        }
    }
}