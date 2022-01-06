//
// Created by josip on 07.08.2021..
//

#pragma once

#include "GameObject.h"

class Missile : public GameObject
{
public:
    Missile(float x, float y, float speed, bool destructible, int score, int fuel);
    void hit();
    void update(sf::Time dt) override;
};


