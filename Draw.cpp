//
// Created by josip on 21.08.2021..
//

#include "Game.h"

void Game::draw() {

    if (state_ == State::Playing)
    {
        window_.clear();

        background_.draw(window_, resolution_);

        for_each(tiles_.begin(), tiles_.end(), [&](auto& tile) { if (tile->isActive()) tile->draw(window_); });

        player.draw(window_);

        for_each(enemyFleet_.begin(), enemyFleet_.end(), [&](auto& ship) { if (ship->isActive()) ship->draw(window_); });

        for_each(meteors_.begin(), meteors_.end(), [&](auto& meteor) { if (meteor->isActive()) meteor->draw(window_); });

		for_each(rockets_.begin(), rockets_.end(), [&](auto& rocket) { if (rocket->isActive()) rocket->draw(window_); });
  
		for_each(tanks_.begin(), tanks_.end(), [&](auto& tank) { if (tank->isActive()) tank->draw(window_); });

        for_each(fuelTanks_.begin(), fuelTanks_.end(), [&](auto& fuelTank) { if (fuelTank->isActive()) fuelTank->draw(window_); });
    
        for_each(mines_.begin(), mines_.end(), [&](auto& mine) { if (mine->isActive()) mine->draw(window_); });

        window_.draw(livesText_);
        window_.draw(scoreText_);
    }

    if (state_ == State::Start)
    {
        window_.clear();
        window_.draw(messageText_);
    }

    if (state_ == State::Game_Over)
    {
        window_.clear();
        window_.draw(messageText_);
    }
    if (state_ == State::Paused)
    {
        window_.draw(messageText_);
    }

    window_.display();
}

