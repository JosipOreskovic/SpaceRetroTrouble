//
// Created by josip on 24.08.2021..
//
#pragma once

#include "GameObject.h"

class Meteor : public GameObject
{
public:
    Meteor(float x, float y, float speed, bool destructible, int score, int fuel);
    void update(sf::Time dt, sf::Time totalTime) override;
    void draw(sf::RenderWindow& window) override;
private:
    Animation* meteorAnim_;
};

