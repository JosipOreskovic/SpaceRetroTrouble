//
// Created by josip on 24.08.2021..
//

#pragma once

#include "GameObject.h"

class Tank : public GameObject
{
public:
    Tank(float x, float y, float speed, bool destructible, int score, int fuel);
    void update(sf::Time dt, sf::Time totalTime, sf::Vector2f playerPosition) override;
    void updateTankMissile(sf::Time dt, sf::Time totalTime, sf::Vector2f playerPosition);
    void hit() override;
    void draw(sf::RenderWindow& window) override;

    std::shared_ptr<GameObject>& getTankMissile();

    friend void removeObject(std::shared_ptr<GameObject>& objects);
private:
    std::shared_ptr<GameObject> tankMissile_;

};

