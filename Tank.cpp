//
// Created by josip on 24.08.2021..
//

#include "Tank.h"
#include "TankMissile.h"


Tank::Tank(float x, float y, float speed) : GameObject(x, y, speed)
{
    sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/Tank.png"));
    tankMissile_ = shared_ptr<TankMissile>(new TankMissile(position_.x, position_.y));
}

shared_ptr<GameObject>& Tank::getTankMissile()
{
    return tankMissile_;
}

void Tank::update(Time dt, Time totalTime, Vector2f playerPosition)
{
    position_.x -= speed_ * dt.asSeconds();

    if (!destroyed_)
    {
        sprite_.setPosition(position_.x , position_.y);
    }
	else
    {
		if (explosionAnim_->update(dt, Vector2f(position_.x, position_.y + TILE_DIMENSION / 2.)))
		{
			active_ = false;
		}
    }

    if (tankMissile_->isActive())
    {
        updateTankMissile(dt, totalTime, playerPosition);
    }
}

void Tank::updateTankMissile(Time dt, Time totalTime, Vector2f playerPosition)
{
    tankMissile_->update(dt, playerPosition);
    if (tankMissile_->getPosition().x < 0 || tankMissile_->getPosition().y < 0)
    {
        tankMissile_->stop();
    }
}

void Tank::draw(RenderWindow& window)
{
    if (!destroyed_)
    {
        window.draw(sprite_);
    }
    else
    {
        window.draw(explosionAnim_->getSprite());
    }

    tankMissile_->draw(window);
}


void Tank::hit()
{
    destroyed_ = true;
    if (!((dynamic_pointer_cast<TankMissile>(tankMissile_))->isFlying()))
        tankMissile_->stop();
}

