//
// Created by josip on 24.08.2021..
//

#include "Mine.h"
#include "Game.h"

Mine::Mine(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x,y,speed, destructible, score, fuel)
{
   sprite_ = sf::Sprite(AssetManager::GetTexture("Assets/Graphics/Mine.png"));
   sprite_.setOrigin(sprite_.getLocalBounds().width / 2., sprite_.getLocalBounds().height / 2.);
}

void Mine::update(sf::Time dt, sf::Time totalTime)
{
    position_.x -= speed_ * dt.asSeconds();

    if (!destroyed_)
    {
        sprite_.setPosition(position_.x, position_.y);
    }

    else
    {
        if (explosionAnim_->update(dt, sf::Vector2f(position_.x, position_.y)))
            active_ = false;
    }
}

