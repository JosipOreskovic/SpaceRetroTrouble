//
// Created by josip on 23.08.2021..
//
#pragma once
#include "Game.h"


void Game::collision()
{
    const vector<shared_ptr<GameObject>>& bombs = player.getBombs();
    const vector<shared_ptr<GameObject>>& missiles = player.getMissiles();

    for_each(tanks_.begin(), tanks_.end(), [&](auto& tank) 
        { DetectCollision(player, dynamic_pointer_cast<Tank>(tank)->getTankMissile(), totalTime_); });

    DetectCollision(player, enemyFleet_, totalTime_);

    DetectCollision(player, tanks_, totalTime_);

    DetectCollision(player, fuelTanks_, totalTime_);

    DetectCollision(player, meteors_, totalTime_);

    DetectCollision(player, mines_, totalTime_);

    DetectCollision(player, rockets_, totalTime_);

    DetectCollision(player, tiles_, totalTime_);

    DetectCollision(missiles, enemyFleet_, totalTime_);

    DetectCollision(missiles, meteors_, totalTime_);

    DetectCollision(missiles, mines_, totalTime_);

    DetectCollision(missiles, rockets_, totalTime_);

    DetectCollision(missiles, tiles_, totalTime_);

    DetectCollision(missiles, tanks_, totalTime_);

    DetectCollision(missiles, fuelTanks_, totalTime_);

    DetectCollision(bombs, enemyFleet_, totalTime_);

    DetectCollision(bombs, meteors_, totalTime_);

    DetectCollision(bombs, mines_, totalTime_);

    DetectCollision(bombs, rockets_, totalTime_);

    DetectCollision(bombs, tiles_, totalTime_);

    DetectCollision(bombs, tanks_, totalTime_);

    DetectCollision(bombs, fuelTanks_, totalTime_);
}