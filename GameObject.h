//
// Created by josip on 22.08.2021..
//

#pragma once

#include "AssetManager.h"
#include "Animation.h"
#include "SoundManager.h"

using namespace sf;
using namespace std;

class GameObject
{
public:
    GameObject();
    GameObject(float x, float y, float speed, bool destructible, int score, int fuel);
    virtual ~GameObject() = default;

    Sprite& getSprite();
    //void setSprite(Sprite&);

    Vector2f getPosition();
    void setPosition(float x, float y);

    float getSpeed();
    void setSpeed(float speed);

    bool isActive() const;
    bool isDestroyed() const;

    int getScore();
    int getFuel();
    bool isDestructible();

    void start();
    void stop();
    virtual void hit();

    virtual void update(Time dt) {}
    virtual void update(Time dt, Time totalTime) {}
    virtual void update(Time dt, Vector2f playerPosition) {}
    virtual void update(Time dt, Time totalTime, Vector2f playerPosition) {}

    virtual void draw(RenderWindow & window);

protected:
    Sprite sprite_;
    Vector2f position_;
    bool active_;
    float speed_;
    bool destroyed_;
    bool destructible_;
    int score_;
    int fuel_;

    Animation* explosionAnim_;
};


