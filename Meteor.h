//
// Created by josip on 24.08.2021..
//
#pragma once

#include "GameObject.h"

class Meteor : public GameObject
{
public:
    Meteor(float x, float y, float speed, bool destructible, int score, int fuel);
    void update(Time dt, Time totalTime) override;
    void draw(RenderWindow& window) override;
private:
    Animation* meteorAnim_;
};

