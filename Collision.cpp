//
// Created by josip on 23.08.2021..
//
#pragma once
#include "Game.h"


void Game::collision()
{
    const vector<shared_ptr<GameObject>>& bombs = player.getBombs();
    const vector<shared_ptr<GameObject>>& missiles = player.getMissiles();

    for (auto& tank : tanks_)
    {
        DetectCollision(player, dynamic_pointer_cast<Tank>(tank)->getTankMissile(), totalTime_, true);
    }

    DetectCollision(player, enemyFleet_, totalTime_, true);

    DetectCollision(player, tanks_, totalTime_, true);

    DetectCollision(player, fuelTanks_, totalTime_, true);

    DetectCollision(player, meteors_, totalTime_, true);

    DetectCollision(player, mines_, totalTime_, true);

    DetectCollision(player, rockets_, totalTime_, true);

    DetectCollision(player, tiles_, totalTime_, false);

    DetectCollision(missiles, enemyFleet_, totalTime_, true, 10, 0);

    DetectCollision(missiles, meteors_, totalTime_, true, 10, 0);

    DetectCollision(missiles, mines_, totalTime_, true, 10, 0);

    DetectCollision(missiles, rockets_, totalTime_, true, 10, 0);

    DetectCollision(missiles, tiles_, totalTime_, false, 10, 0);

    DetectCollision(missiles, tanks_, totalTime_, true, 10, 0);

    DetectCollision(missiles, fuelTanks_, totalTime_, true, 10, 10);

    DetectCollision(bombs, enemyFleet_, totalTime_, true, 10, 0);

    DetectCollision(bombs, meteors_, totalTime_, true, 10, 0);

    DetectCollision(bombs, mines_, totalTime_, true, 10, 0);

    DetectCollision(bombs, rockets_, totalTime_, true, 10, 0);

    DetectCollision(bombs, tiles_, totalTime_, false, 10, 0);

    DetectCollision(bombs, tanks_, totalTime_, true, 10, 0);

    DetectCollision(bombs, fuelTanks_, totalTime_, true, 10, 10);
}