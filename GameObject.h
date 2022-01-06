//
// Created by josip on 22.08.2021..
//

#pragma once

#include "AssetManager.h"
#include "Animation.h"
#include "SoundManager.h"

class GameObject
{
public:
    GameObject();
    GameObject(float x, float y, float speed, bool destructible, int score, int fuel);
    virtual ~GameObject() = default;

    sf::Sprite& getSprite();
    //void setSprite(Sprite&);

    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);

    float getSpeed() const;
    void setSpeed(float speed);

    bool isActive() const;
    bool isDestroyed() const;

    int getScore() const;
    int getFuel() const;
    bool isDestructible() const;

    void start();
    void stop();
    virtual void hit();

    virtual void update(sf::Time dt) {}
    virtual void update(sf::Time dt, sf::Time totalTime) {}
    virtual void update(sf::Time dt, sf::Vector2f playerPosition) {}
    virtual void update(sf::Time dt, sf::Time totalTime, sf::Vector2f playerPosition) {}

    virtual void draw(sf::RenderWindow & window);

protected:
    sf::Sprite sprite_;
    sf::Vector2f position_;
    bool active_;
    float speed_;
    bool destroyed_;
    bool destructible_;
    int score_;
    int fuel_;

    Animation* explosionAnim_;
};


