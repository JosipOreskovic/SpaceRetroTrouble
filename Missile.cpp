//
// Created by josip on 07.08.2021..
//

#include "Missile.h"

#include "Bomb.h"

Missile::Missile(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x, y, speed, destructible, score, fuel)
{
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
    destroyed_ = true;
}