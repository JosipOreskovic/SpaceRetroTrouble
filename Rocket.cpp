//
// Created by josip on 09.08.2021..
//

#include "Rocket.h"
#include "Player.h"
#include "Tile.h"

Rocket::Rocket(float x, float y, float speed) : GameObject(x, y, speed)
{
    sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/Rocket.png"));
  /*  position_.x = x;
    position_.y = y;*/
    flying_ = false;
    //speed_ = 200;
}

void Rocket::update(Time dt, Time totalTime, Vector2f playerPosition)
{
    if (!destroyed_)
    {
        if (!flying_)
        {
            position_.x -= speed_ * dt.asSeconds();
            if (position_.x < playerPosition.x + 500)
            {
                flying_ = true;
            }
        }
        else
        {
            position_.x -= speed_ * dt.asSeconds();
            position_.y -= speed_ * dt.asSeconds();
        }
    }

    else
    {
        if (explosionAnim_->update(dt, Vector2f(position_.x - 64, position_.y - 86)))
        {
            active_ = false;
        }
    }

    sprite_.setPosition(position_.x, position_.y);
}
