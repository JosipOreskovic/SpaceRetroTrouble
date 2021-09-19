//
// Created by josip on 21.08.2021..
//
#include "Game.h"

void Game::draw() {

    if (state_ == State::Playing)
    {
        window_.clear();

        background_.draw(window_, resolution_);

        for (const auto& tile : tiles_)
        {
            if (tile->isActive())
                tile->draw(window_);
        }

        player.draw(window_);

        for (const auto& ship : enemyFleet_)
        {
            if (ship->isActive())
                ship->draw(window_);
        }
        for (const auto& meteor : meteors_)
        {
            if (meteor->isActive())
                meteor->draw(window_);
        }
        for (const auto& rocket : rockets_)
        {
            if (rocket->isActive())
                rocket->draw(window_);
        }
        for (const auto& tank : tanks_)
        {
            if (tank->isActive())
                tank->draw(window_);
        }
        for (const auto& fuelTank : fuelTanks_)
        {
            if (fuelTank->isActive())
                fuelTank->draw(window_);
        }
        for (const auto& mine : mines_)
        {
            if (mine->isActive())
                mine->draw(window_);
        }

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

