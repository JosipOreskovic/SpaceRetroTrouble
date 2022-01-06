//
// Created by josip on 27.08.2021..
//

#pragma once
#include "GameObject.h"

class Background : public GameObject
{
public:
    Background();
    void update(sf::Time dt, sf::Vector2f resolution) override;
    void draw(sf::RenderWindow& window, sf::Vector2f resolution);
private:
    std::vector<sf::Texture*> textures_;
    bool order_;
};


