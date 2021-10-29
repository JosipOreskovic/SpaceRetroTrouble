//
// Created by josip on 24.08.2021..
//

#include "FuelTank.h"


FuelTank::FuelTank(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x, y, speed, destructible, score, fuel)
{
    sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/FuelTank.png"));
    active_ = true;
}

void FuelTank::update(Time dt, Time totalTime)
{
    position_.x -= speed_ * dt.asSeconds();

    if (!destroyed_)
    {
        sprite_.setPosition(position_.x, position_.y);
    }
	else
    {
		if (explosionAnim_->update(dt, Vector2f(position_.x, position_.y + TILE_DIMENSION / 2.)))
		{
			active_ = false;
		}
    }
}
