#pragma once
#include "GameObject.h"


class TankMissile : public GameObject
{
public:
    TankMissile(float x, float y);
    bool isFlying();
    void hit() override;
    void update(Time dt, Vector2f playerPosition) override;
    void draw(RenderWindow& window) override;
private:
    bool flying_;
};


