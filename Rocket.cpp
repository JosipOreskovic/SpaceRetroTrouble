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
    position_.x -= speed_ * dt.asSeconds();

    if (!destroyed_)
    {
        if (!flying_)
        {
           
            if (position_.x < playerPosition.x + 500)
            {
                flying_ = true;
            }
        }
        else
        {
            position_.y -= speed_ * dt.asSeconds();
        }
    }

    else
    {
        if (explosionAnim_->update(dt, Vector2f(position_.x, position_.y + TILE_DIMENSION / 2.)))
        {
            active_ = false;
        }
    }

    sprite_.setPosition(position_.x, position_.y);
}
