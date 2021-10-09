//
// Created by josip on 24.08.2021..
//

#include "Mine.h"
#include "Game.h"

Mine::Mine(float x, float y, float speed) : GameObject(x,y,speed)
{
   sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/Mine.png"));
   sprite_.setOrigin(sprite_.getLocalBounds().width / 2., sprite_.getLocalBounds().height / 2.);
}

void Mine::update(Time dt, Time totalTime)
{
    position_.x -= speed_ * dt.asSeconds();

    if (!destroyed_)
    {
        sprite_.setPosition(position_.x, position_.y);
    }

    else
    {
        if (explosionAnim_->update(dt, Vector2f(position_.x, position_.y)))
            active_ = false;
    }
}

