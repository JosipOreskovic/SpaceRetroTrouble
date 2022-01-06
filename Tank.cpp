//
// Created by josip on 24.08.2021..
//

#include "Tank.h"
#include "TankMissile.h"


Tank::Tank(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x, y, speed, destructible, score, fuel)
{
    sprite_ = sf::Sprite(AssetManager::GetTexture("Assets/Graphics/Tank.png"));
    tankMissile_ = std::make_shared<TankMissile>(position_.x, position_.y);
}

std::shared_ptr<GameObject>& Tank::getTankMissile()
{
    return tankMissile_;
}

void Tank::update(sf::Time dt, sf::Time totalTime, sf::Vector2f playerPosition)
{
    position_.x -= speed_ * dt.asSeconds();

    if (!destroyed_)
    {
        sprite_.setPosition(position_.x , position_.y);
    }
	else
    {
		if (explosionAnim_->update(dt, sf::Vector2f(position_.x, position_.y + TILE_DIMENSION / 2.0f)))
		{
			active_ = false;
		}
    }

    if (tankMissile_->isActive())
    {
        updateTankMissile(dt, totalTime, playerPosition);
    }
}

void Tank::updateTankMissile(sf::Time dt, sf::Time totalTime, sf::Vector2f playerPosition)
{
    tankMissile_->update(dt, playerPosition);
    if (tankMissile_->getPosition().x < -TILE_DIMENSION * 2 || tankMissile_->getPosition().y < 0)
    {
        tankMissile_->stop();
    }
}

void Tank::draw(sf::RenderWindow& window)
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
    if (!((std::static_pointer_cast<TankMissile>(tankMissile_))->isFlying()))
        tankMissile_->stop();
}

