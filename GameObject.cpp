//
// Created by josip on 22.08.2021..
//

#include "GameObject.h"

GameObject::GameObject() : destroyed_(false), active_(true)
{
    explosionAnim_ = new Animation("ObjectExplosion", "Assets/Graphics/ObjectExplosion.png", seconds(1), false,
		Vector2f(position_.x, position_.y), Vector2f(0, 0),
        Vector2i(EXPLOSION_SPRITE_DIMENSION, EXPLOSION_SPRITE_DIMENSION), 10);
}

GameObject::GameObject(float x, float y, float speed, bool destructible, int score, int fuel) : position_(Vector2f(x,y)), speed_(speed), destructible_(destructible),
	score_(score), fuel_(fuel), destroyed_(false), active_(true)
{
    explosionAnim_ = new Animation("ObjectExplosion", "Assets/Graphics/ObjectExplosion.png", seconds(0.5f), false,
		Vector2f(position_.x, position_.y), Vector2f(0, 0),
        Vector2i(EXPLOSION_SPRITE_DIMENSION, EXPLOSION_SPRITE_DIMENSION), 10);
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

bool GameObject::isDestroyed() const
{
    return destroyed_;
}

int GameObject::getScore()
{
    return score_;
}

int GameObject::getFuel()
{
    return fuel_;
}

bool GameObject::isDestructible()
{
    return  destructible_;
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