//
// Created by josip on 24.08.2021..
//

#pragma once

#include "GameObject.h"

class Tank : public GameObject
{
public:
    Tank(float x, float y, float speed);
    void update(Time dt, Time totalTime, Vector2f playerPosition) override;
    void updateTankMissile(Time dt, Time totalTime, Vector2f playerPosition);
    void hit() override;
    void draw(RenderWindow& window) override;

    GameObject*& getTankMissile();

    friend void removeObject(GameObject*& objects);
private:
    GameObject* tankMissile_;

};

