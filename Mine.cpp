//
// Created by josip on 24.08.2021..
//

#include "Mine.h"
#include "Game.h"

Mine::Mine(float x, float y, float speed) : GameObject(x,y,speed)
{
   sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/Mine.png"));
}

void Mine::update(Time dt, Time totalTime)
{
    if (!destroyed_)
    {
        position_.x -= speed_ * dt.asSeconds();
        sprite_.setPosition(position_.x, position_.y);
    }

    else
    {
        if (explosionAnim_->update(dt, Vector2f(position_.x - 64, position_.y - 86)))
        {
            active_ = false;
        }
    }
}

