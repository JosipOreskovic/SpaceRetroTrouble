//
// Created by josip on 07.08.2021..
//

#include "Missile.h"

#include "Bomb.h"

Missile::Missile(float x, float y)
{
    position_.x = x;
    position_.y = y;
    speed_ = 600;
    sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/Missile.png"));
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2., sprite_.getLocalBounds().height / 2.);
}

void Missile::update(Time dt)
{
    position_.x += speed_ * dt.asSeconds();
    sprite_.setPosition(position_.x, position_.y);
}

void Missile::hit()
{
    active_ = false;
}