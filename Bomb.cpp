//
// Created by josip on 07.08.2021..
//

#include "Bomb.h"

Bomb::Bomb(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x, y, speed, destructible, score, fuel)
{
    angle_ = 0.0f;
    gravity_ = 1.3f;
    rotationSpeed_ = 50.0f;
    sprite_ = sf::Sprite(AssetManager::GetTexture("Assets/Graphics/Bomb.png"));
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2.0f, sprite_.getLocalBounds().height / 2.0f);
}

void Bomb::update(sf::Time dt)
{
    if (!destroyed_)
    {
        position_.x += speed_ * dt.asSeconds();
        position_.y += speed_ * gravity_ * dt.asSeconds();
        angle_ += rotationSpeed_ * dt.asSeconds();
        if (angle_ > 90.0f)
            angle_ = 90.0f;

   
    }
    else
    {
        position_.x -= GAME_SPEED * dt.asSeconds();
        if (explosionAnim_->update(dt, sf::Vector2f(position_.x, position_.y)))
        {
            active_ = false;
        }
    }

    sprite_.setPosition(position_.x, position_.y);
    sprite_.setRotation(angle_);
}


  