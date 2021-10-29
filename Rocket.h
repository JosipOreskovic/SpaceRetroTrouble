//
// Created by josip on 09.08.2021..
//

#pragma once

#include "GameObject.h"

class Rocket : public GameObject
{
public:
    Rocket(float x, float y, float speed, bool destructible, int score, int fuel);
    void update(Time dt, Time totalTime, Vector2f playerPosition) override;
private:
    bool flying_;
};


