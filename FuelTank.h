//
// Created by josip on 24.08.2021..
//

#pragma once

#include "GameObject.h"

class FuelTank : public GameObject
{
public:

    FuelTank(float x, float y, float speed);
    void update(Time dt, Time totalTime) override;
private:
    int fuel_;
};

