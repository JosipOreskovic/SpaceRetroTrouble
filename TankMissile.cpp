#include "TankMissile.h"

TankMissile::TankMissile(float x, float y)
{
    sprite_ = sf::Sprite(AssetManager::GetTexture("Assets/Graphics/TankMissile.png"));
    position_.x = x;
    position_.y = y;
    active_ = true;
    flying_ = false;
    speed_ = 400;
    destructible_ = true;
}

void TankMissile::update(sf::Time dt, sf::Vector2f playerPosition)
{
    if (!flying_)
    {
        position_.x -= speed_ / 2 * dt.asSeconds();
        if (position_.x < playerPosition.x + 500)
        {
            flying_ = true;
        }
    }
    else
    {
        position_.x -= 2 * speed_ * dt.asSeconds();
        position_.y -= speed_ * dt.asSeconds();
    }

    sprite_.setPosition(position_.x, position_.y);
}

void TankMissile::hit()
{
    active_ = false;
    flying_ = false;
}

bool TankMissile::isFlying()
{
    return flying_;
}

void TankMissile::draw(sf::RenderWindow& window)
{
	if (flying_)
		window.draw(sprite_);
}
