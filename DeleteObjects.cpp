//
// Created by josip on 23.08.2021..
//

#pragma once

#include "GameObject.h"
#include "DeleteObjects.h"

void deleteObjects(vector<GameObject*>& objects)
{
    for (auto& object : objects)
    {
        delete object;
    }
    objects.clear();
}
