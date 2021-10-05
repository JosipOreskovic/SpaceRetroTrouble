//
// Created by josip on 22.08.2021..
//

#include "GameObject.h"

GameObject::GameObject() : destroyed_(false), active_(true)
{
    explosionAnim_ = new Animation("ObjectExplosion", "Assets/Graphics/ObjectExplosion.png", seconds(1), false,
								Vector2f(position_.x, position_.y), Vector2f(0, 0), Vector2i(128, 128), 10);
}

GameObject::GameObject(float x, float y, float speed) : position_(Vector2f(x,y)), speed_(speed), destroyed_(false), active_(true)
{
    explosionAnim_ = new Animation("ObjectExplosion", "Assets/Graphics/ObjectExplosion.png", seconds(1), false,
								Vector2f(position_.x, position_.y), Vector2f(0, 0), Vector2i(128, 128), 10);
}


Sprite& GameObject::getSprite()
{
    return sprite_;
}

Vector2f GameObject::getPosition()
{
    return position_;
}

void GameObject::setPosition(float x, float y)
{
    position_.x = x;
    position_.y = y;
}

float GameObject::getSpeed()
{
    return speed_;
}

void GameObject::setSpeed(float speed)
{
    speed_ = speed;
}

bool GameObject::isActive() const
{
    return active_;
}

int GameObject::getScore()
{
    return score_;
}

void GameObject::start()
{
    active_ = true;
}

void GameObject::stop()
{
    active_ = false;
}


void GameObject::hit()
{
    destroyed_ = true;
}


void GameObject::draw(RenderWindow& window)
{
    if (!destroyed_)
    {
        window.draw(sprite_);
    }
    else
    {
        window.draw(explosionAnim_->getSprite());
    }

}