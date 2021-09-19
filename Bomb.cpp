//
// Created by josip on 07.08.2021..
//

#include "Bomb.h"

Bomb::Bomb(float x, float y)
{
    sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/Bomb.png"));
    position_.x = x;
    position_.y = y;
    angle_ = 0.0;
    speed_ = 300.0;
    gravity_ = 1.3;
    rotationSpeed_ = 50;
}

void Bomb::update(Time dt)
{
    position_.x += speed_ * dt.asSeconds();
    position_.y += speed_ * gravity_ * dt.asSeconds();
    angle_ += rotationSpeed_ * dt.asSeconds();
    if (angle_ > 90)
        angle_ = 90;

    sprite_.setPosition(position_.x, position_.y);
    sprite_.setRotation(angle_);
}

void Bomb::hit()
{
    active_ = false;
}