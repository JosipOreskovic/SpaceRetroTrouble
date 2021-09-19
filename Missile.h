//
// Created by josip on 07.08.2021..
//

#pragma once

#include "GameObject.h"

class Missile : public GameObject
{
public:
    Missile(float x, float y);
    void hit();
    void update(Time dt) override;
};


