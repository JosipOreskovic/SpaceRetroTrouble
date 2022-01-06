//
// Created by josip on 17.08.2021..
//

#include "Tile.h"

Tile::Tile(float x, float y, float speed, bool destructible, int score, int fuel) : GameObject(x, y, speed, destructible, score, fuel) {}

void Tile::update(sf::Time dt, sf::Time totalTime)
{
    position_.x -= speed_ * dt.asSeconds();
    sprite_.setPosition(position_.x, position_.y);
}
