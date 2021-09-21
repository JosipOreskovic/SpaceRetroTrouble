//
// Created by josip on 24.08.2021..
//

#include "Meteor.h"

Meteor::Meteor(float x, float y, float speed) : GameObject(x,y,speed)
{
	sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/Meteor1.png"));
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2., sprite_.getLocalBounds().height / 2.);
	meteorAnim_ = new Animation("Meteor", "Assets/Graphics/Meteor.png", seconds(1), true,
								Vector2f(position_.x, position_.y), Vector2f(0, 0), Vector2i(64, 64), 6);
}

void Meteor::update(Time dt, Time totalTime)
{
    if (!destroyed_)
    {
        position_.x -= speed_ * dt.asSeconds();
        meteorAnim_->update(dt, position_);
        sprite_.setPosition(position_.x, position_.y);
    }
    else
    {
		if (explosionAnim_->update(dt, Vector2f(position_.x, position_.y)))
		{
			active_ = false;
		}
    }
}

void Meteor::draw(RenderWindow& window)
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