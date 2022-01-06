//
// Created by josip on 24.08.2021..
//

#include "Meteor.h"

Meteor::Meteor(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x,y,speed, destructible, score, fuel)
{
	sprite_ = sf::Sprite(AssetManager::GetTexture("Assets/Graphics/Meteor1.png"));
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2., sprite_.getLocalBounds().height / 2.);
	meteorAnim_ = new Animation("Meteor", "Assets/Graphics/Meteor.png", sf::seconds(1), true,
        sf::Vector2f(position_.x, position_.y), sf::Vector2f(0, 0), sf::Vector2i(64, 64), 6);
}

void Meteor::update(sf::Time dt, sf::Time totalTime)
{
    if (!destroyed_)
    {
        position_.x -= speed_ * dt.asSeconds();
        meteorAnim_->update(dt, position_);
        sprite_.setPosition(position_.x, position_.y);
    }
    else
    {
        position_.x -= GAME_SPEED * dt.asSeconds();

		if (explosionAnim_->update(dt, sf::Vector2f(position_.x, position_.y)))
		{
			active_ = false;
		}
    }
}

void Meteor::draw(sf::RenderWindow& window)
{
    if (!destroyed_)
    {
        //window.draw(sprite);
        window.draw(meteorAnim_->getSprite());
    }
    else
    {
        window.draw(explosionAnim_->getSprite());
    }

}