//
// Created by josip on 27.08.2021..
//

#pragma once
#include "GameObject.h"


class Background : public GameObject
{
public:
    Background();
    void update(Time dt, Vector2f resolution) override;
    void draw(RenderWindow& window, Vector2f resolution);
private:
    vector<Texture*> textures_;
    bool order_;
};


