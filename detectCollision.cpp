
#include "Game.h"
#include "TankMissile.h"

void Game::DetectCollision(Player& player, std::shared_ptr<GameObject> const& gameObject, sf::Time const& totalTime)
{
        if (player.getShipSprite().getGlobalBounds().intersects(gameObject->getSprite().getGlobalBounds()) && player.isActive() && gameObject->isActive())
        {
            player.hit(player.getPosition(), totalTime);
            soundManager_.playPlayerExplosionSound();
            if (gameObject->isDestructible())
            {
                gameObject->hit();
                soundManager_.playObjectExplosionSound();
            }
            lives_--;
        }
}


void Game::DetectCollision(Player& player, std::vector<std::shared_ptr<GameObject>> const& gameObjects, sf::Time const& totalTime)
{
    for_each(begin(gameObjects), end(gameObjects), [&](auto& gameObject) { DetectCollision(player, gameObject, totalTime); }
    );
}


void Game::DetectCollision(std::vector<std::shared_ptr<GameObject>> const& playerObjects, std::vector<std::shared_ptr<GameObject>> const& gameObjects, sf::Time const& totalTime)
{
    for (auto const& playerObject : playerObjects)
    {
        for (auto const& gameObject : gameObjects)
        {
            if (!playerObject->isDestroyed() && !gameObject->isDestroyed() && (playerObject->getSprite().getGlobalBounds().intersects(gameObject->getSprite().getGlobalBounds())))
            {
                playerObject->hit();
                if(playerObject->isActive())
                    soundManager_.playObjectExplosionSound();
                
                if (gameObject->isDestructible())
                {
                    gameObject->hit();
                    soundManager_.playObjectExplosionSound();
                    score_ += gameObject->getScore();
                    player.setFuelLevel(gameObject->getFuel());
                }
            }
        }
    }
}