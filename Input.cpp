//
// Created by josip on 21.08.2021..
//

#include "Game.h"

void Game::input() {

    sf::Event event;
    Vector2f playerPosition = player.getPosition();
    Time pauseTime;

    while (window_.pollEvent(event))
    {

        switch (event.type)
        {
            case sf::Event::Closed:
                isRunning_ = false;
                break;
                default:
                    break;
        }

        window_.setKeyRepeatEnabled(false);

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                if (state_ == State::Playing)
                {
                    state_ = State::Paused;
                    pauseTime = nextLevelTime_;
                    
                }
                else if (state_ == State::Paused)
                {
                    state_ = State::Playing;
                    nextLevelTime_ = pauseTime;
                }
            }

            if ((event.key.code == sf::Keyboard::P) && (state_ == State::Start || state_ == State::Game_Over))
            {
                if (state_ == State::Game_Over)
                    initialize();
                state_ = State::Playing;
            }

            if ((event.key.code == sf::Keyboard::Q) && (state_ == State::Start || state_ == State::Game_Over || state_ == State::Paused))
            {
                isRunning_ = false;
            }
        }
    }

    if (state_ == State::Playing)
        player.input(event, totalTime_);

}
