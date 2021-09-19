//
// Created by josip on 24.08.2021..
//

#include "FuelTank.h"


FuelTank::FuelTank(float x, float y, float speed) : GameObject(x, y, speed)
{
    sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/FuelTank.png"));
   /* position_.x = x;
    position_.y = y;*/
    active_ = true;
    //speed_ = 200;
}

void FuelTank::update(Time dt, Time totalTime)
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
