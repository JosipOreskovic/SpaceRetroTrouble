//
// Created by josip on 09.08.2021..
//

#include "Rocket.h"
#include "Player.h"
#include "Tile.h"

Rocket::Rocket(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x, y, speed, destructible, score, fuel)
{
    sprite_ = sf::Sprite(AssetManager::GetTexture("Assets/Graphics/Rocket.png"));
    flying_ = false;
}

void Rocket::update(sf::Time dt, sf::Time totalTime, sf::Vector2f playerPosition)
{
    position_.x -= speed_ * dt.asSeconds();

    if (!destroyed_)
    {
        if (!flying_)
        {
           
            if (position_.x < playerPosition.x + 500)
            {
                flying_ = true;
            }
        }
        else
        {
            position_.y -= speed_ * dt.asSeconds();
        }
    }

    else
    {
        if (explosionAnim_->update(dt, sf::Vector2f(position_.x, position_.y + TILE_DIMENSION / 2.)))
        {
            active_ = false;
        }
    }

    sprite_.setPosition(position_.x, position_.y);
}
