//
// Created by josip on 27.08.2021..
//

#include "Background.h"

Background::Background()
{
    order_ = true;
    position_.x = 0.0;

    textures_.push_back(&AssetManager::GetTexture("Assets\\Graphics\\Background1.png"));
    textures_.push_back(&AssetManager::GetTexture("Assets\\Graphics\\Background2.png"));
}

void Background::update(Time dt, Vector2f resolution)
{
    position_.x -= 100 * dt.asSeconds();
    if (position_.x  < -resolution.x)
    {
        position_.x  = 0.0;
        order_ = !order_;
    }
}

void Background::draw(RenderWindow &window, Vector2f resolution)
{
    sprite_.setTexture(*textures_[order_]);
    sprite_.setPosition(position_.x,0);
    window.draw(sprite_);
    sprite_.setTexture(*textures_[!order_]);
    sprite_.setPosition(resolution.x + position_.x, 0);
    window.draw(sprite_);
}
