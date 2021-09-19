//
// Created by josip on 23.08.2021..
//
#pragma once
#include "Game.h"


void Game::collision()
{
	const vector<GameObject*>& bombs = player.getBombs();
	const vector<GameObject*>& missiles = player.getMissiles();

    for (auto& tank : tanks_)
    {
        detectCollision(player, static_cast<Tank*>(tank)->getTankMissile(), totalTime_, true);
    }

    detectCollision(player, enemyFleet_, totalTime_, true);

    detectCollision(player, tanks_, totalTime_, true);

    detectCollision(player, fuelTanks_, totalTime_, true);
  
    detectCollision(player, meteors_, totalTime_, true);
   
    detectCollision(player, mines_, totalTime_, true);
  
    detectCollision(player, rockets_, totalTime_, true);
   
    detectCollision(player, tiles_, totalTime_, false);

    detectCollision(missiles, enemyFleet_, totalTime_, true, 10, 0);

    detectCollision(missiles, meteors_, totalTime_, true, 10, 0);

    detectCollision(missiles, mines_, totalTime_, true, 10, 0);

    detectCollision(missiles, rockets_, totalTime_, true, 10, 0);

    detectCollision(missiles, tiles_, totalTime_, false, 10, 0);

    detectCollision(missiles, tanks_, totalTime_, true, 10, 0);

    detectCollision(missiles, fuelTanks_, totalTime_, true, 10, 10);

    detectCollision(bombs, enemyFleet_, totalTime_, true, 10, 0);

    detectCollision(bombs, meteors_, totalTime_, true, 10, 0);

    detectCollision(bombs, mines_, totalTime_, true, 10, 0);

    detectCollision(bombs, rockets_, totalTime_, true, 10, 0);

    detectCollision(bombs, tiles_, totalTime_, false, 10, 0);

    detectCollision(bombs, tanks_, totalTime_, true, 10, 0);

    detectCollision(bombs, fuelTanks_, totalTime_, true, 10, 10);



    // Spawn collision detection - DELETE in case of using the objects level files

    // Tank spawn collision with rocket (stop tank)

    for (const auto& rocket : rockets_)
    {
        for (const auto& tank : tanks_)
        {
            if (rocket->isActive() && (rocket->getSprite().getGlobalBounds().intersects(tank->getSprite().getGlobalBounds())))
            {
                tank->stop();
            }
        }
    }

    // Fuel tank spawn collision with rocket (stop fuelTank)

    for (const auto& rocket : rockets_)
    {
        for (const auto& fuelTank : fuelTanks_)
        {
            if (rocket->isActive() && (rocket->getSprite().getGlobalBounds().intersects(fuelTank->getSprite().getGlobalBounds())))
            {
                fuelTank->stop();
            }
        }
    }

    // Fuel tank spawn collision with tank (stop fuelTank)

        for (const auto& tank : tanks_)
        {
            for (const auto& fuelTank : fuelTanks_)
            {
                if (tank->isActive() && (tank->getSprite().getGlobalBounds().intersects(fuelTank->getSprite().getGlobalBounds())))
                {
                    fuelTank->stop();
                }
            }
        }
}

