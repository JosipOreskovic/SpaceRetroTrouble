//
// Created by josip on 07.08.2021..
//

#include "Bomb.h"

Bomb::Bomb(float x, float y, float speed) : GameObject(x, y, speed)
{
    /*position_.x = x;
    position_.y = y;*/
    angle_ = 0.0;
    //speed_ = speed;
    gravity_ = 1.3;
    rotationSpeed_ = 50;
    //destroyed_ = false;
    sprite_ = Sprite(AssetManager::GetTexture("Assets/Graphics/Bomb.png"));
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2., sprite_.getLocalBounds().height / 2.);
}

//void Bomb::update(Time dt)
//{
//    position_.x += speed_ * dt.asSeconds();
//    position_.y += speed_ * gravity_ * dt.asSeconds();
//    angle_ += rotationSpeed_ * dt.asSeconds();
//    if (angle_ > 90)
//        angle_ = 90;
//
//    sprite_.setPosition(position_.x, position_.y);
//    sprite_.setRotation(angle_);
//}

//void Bomb::hit()
//{
//    //active_ = false;
//    destroyed_ = true;
//}

void Bomb::update(Time dt)
{
    if (!destroyed_)
    {
        position_.x += speed_ * dt.asSeconds();
        position_.y += speed_ * gravity_ * dt.asSeconds();
        angle_ += rotationSpeed_ * dt.asSeconds();
        if (angle_ > 90)
            angle_ = 90;

   
    }
    else
    {
        position_.x -= GAME_SPEED * dt.asSeconds();
        if (explosionAnim_->update(dt, Vector2f(position_.x, position_.y)))
        {
            active_ = false;
        }
    }

    sprite_.setPosition(position_.x, position_.y);
    sprite_.setRotation(angle_);
}


  