//
// Created by josip on 24.08.2021..
//

#pragma once

#include "GameObject.h"

class Tank : public GameObject
{
public:
    Tank(float x, float y, float speed, bool destructible, int score, int fuel);
    void update(Time dt, Time totalTime, Vector2f playerPosition) override;
    void updateTankMissile(Time dt, Time totalTime, Vector2f playerPosition);
    void hit() override;
    void draw(RenderWindow& window) override;

    shared_ptr<GameObject>& getTankMissile();

    friend void removeObject(shared_ptr<GameObject>& objects);
private:
    shared_ptr<GameObject> tankMissile_;

};

