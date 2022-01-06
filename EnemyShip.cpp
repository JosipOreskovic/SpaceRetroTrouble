//
// Created by josip on 07.08.2021..
//
#pragma once
#include "EnemyShip.h"

EnemyShip::EnemyShip(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x,y,speed, destructible, score, fuel), startPositionY_(y), angle_(0.0f), oscilation_(2)
{
    sprite_ = sf::Sprite(AssetManager::GetTexture("Assets/Graphics/EnemyShip.png"));
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2.0f, sprite_.getLocalBounds().height / 2.0f);
}

void EnemyShip::update(sf::Time dt, sf::Time totalTime)
{
    if (!destroyed_)
    {
        position_.x -= speed_ * dt.asSeconds();
        angle_ += oscilation_ * dt.asSeconds();
        if (angle_ > 360.)
            angle_ = 0.0;
        position_.y = startPositionY_ + sin(angle_) * 100;
        sprite_.setPosition(position_.x, position_.y);
    }
    else
    {
        position_.x -= GAME_SPEED * dt.asSeconds();
        if (explosionAnim_->update(dt, sf::Vector2f(position_.x, position_.y)))
        {
            active_ = false;
        }
    }
}
