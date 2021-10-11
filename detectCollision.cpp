
#include "Game.h"
#include "TankMissile.h"

void Game::DetectCollision(Player& player, const shared_ptr<GameObject>& gameObject, Time totalTime, bool destruct)
{
        if (player.getShipSprite().getGlobalBounds().intersects(gameObject->getSprite().getGlobalBounds()) && player.isActive() && gameObject->isActive())
        {
            player.hit(player.getPosition(), totalTime);
            soundManager_.playPlayerExplosionSound();
            if (destruct)
            {
                gameObject->hit();
                soundManager_.playObjectExplosionSound();
            }
            lives_--;
        }
}


void Game::DetectCollision(Player& player, vector<shared_ptr<GameObject>>& gameObjects, Time totalTime, bool destruct)
{
    for_each(gameObjects.begin(), gameObjects.end(), [&](auto& gameObject) { DetectCollision(player, gameObject, totalTime_, destruct); });
}




void Game::DetectCollision(const vector<shared_ptr<GameObject>>& playerObjects, const vector<shared_ptr<GameObject>>& gameObjects, Time totalTime,
     bool destruct, int score, int fuel)
{
    for (const auto& playerObject : playerObjects)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!playerObject->isDestroyed() && !gameObject->isDestroyed() && (playerObject->getSprite().getGlobalBounds().intersects(gameObject->getSprite().getGlobalBounds())))
            {
                playerObject->hit();
                if(playerObject->isActive())
                    soundManager_.playObjectExplosionSound();
                
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