//
// Created by josip on 07.08.2021..
//

#pragma once

#include "GameObject.h"

class Bomb : public GameObject
{
public:

    Bomb(float x, float y, float speed, bool destructible, int score, int fuel);
    //void hit();
    void update(Time dt) override;
private:
    float angle_;
    float gravity_;
    float rotationSpeed_;

};

