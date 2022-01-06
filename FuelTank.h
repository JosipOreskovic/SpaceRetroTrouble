//
// Created by josip on 24.08.2021..
//

#pragma once

#include "GameObject.h"

class FuelTank : public GameObject
{
public:

    FuelTank(float x, float y, float speed, bool destructible, int score, int fuel);
    void update(sf::Time dt, sf::Time totalTime) override;
private:
    int fuel_;
};

