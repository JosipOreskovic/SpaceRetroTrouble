//
// Created by josip on 07.08.2021..
//
#pragma once
#include "EnemyShip.h"

EnemyShip::EnemyShip(float x, float y, float speed) : GameObject(x,y,speed), startPositionY_(y), angle_(0.0), oscilation_(2.0)
{
    sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/EnemyShip.png"));
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2., sprite_.getLocalBounds().height / 2.);
}

void EnemyShip::update(Time dt, Time totalTime)
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
        if (explosionAnim_->update(dt, Vector2f(position_.x, position_.y)))
        {
            active_ = false;
        }
    }
}
