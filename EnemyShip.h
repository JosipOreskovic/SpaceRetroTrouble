//
// Created by josip on 07.08.2021..
//
#pragma once

#include "GameObject.h"

class EnemyShip : public GameObject
{
public:

    EnemyShip(float x, float y, float speed, bool destructible, int score, int fuel);

    void update(sf::Time dt, sf::Time totalTime) override;
private:
    float angle_;
    int oscilation_;
    float startPositionY_;
};

