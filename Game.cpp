//
// Created by josip on 13.08.2021..
//
#pragma once
#include <sstream>
#include "Game.h"

Game::Game()
{
    resolution_.x = static_cast<float>(VideoMode::getDesktopMode().width);
    resolution_.y = static_cast<float>(VideoMode::getDesktopMode().height);
    player.setPosition(resolution_.x, resolution_.y);
    window_.create(VideoMode(static_cast<int>(resolution_.x), static_cast<int>(resolution_.y)), "Space Retro Trouble", Style::Fullscreen);
    window_.setFramerateLimit(60);
    window_.setMouseCursorVisible(false);

    totalDistance_ = 0.0f;
	levelChange_ = false;
	levelRestart_ = false;

    state_ = State::Start;
    isRunning_ = true;

    score_ = 0;;
    hiScore_ = 0;
    lives_ = 3;
    level_ = 1;

}

void Game::run()
{

    Clock clock;

    srand(static_cast<Uint32>(time(0)));

    initialize();

    while (isRunning_)
    {
        Time dt = clock.restart();
        totalTime_ += dt;
  
        input();
        update(dt);
        draw();
        lateUpdate();
    }
    window_.close();
}

void Game::lateUpdate()
{
	if (levelRestart_)
	{
          if (lives_ > 0)
          {
              shutDown();
              restart();
          }
          else
          {
              state_ = State::Game_Over;
          }

          levelRestart_ = false;
	}
}

void Game::initialize()
{
    player.setPosition(resolution_.x / 2.0f,resolution_.y / 2.0f);
    player.setActive();

    state_ = State::Start;

    isRunning_ = true;
    score_ = 0;
    lives_ = 3;
    level_ = 1;
    totalDistance_ = 0.0;

    player.reset();

    scoreText_.setFont(AssetManager::GetFont("Assets/Fonts/8bitOperatorPlus8-Regular.ttf"));
    livesText_.setFont(AssetManager::GetFont("Assets/Fonts/8bitOperatorPlus8-Regular.ttf"));
    messageText_.setFont(AssetManager::GetFont("Assets/Fonts/8bitOperatorPlus8-Regular.ttf"));

    music_.openFromFile("Assets\\Sound\\main_music_loop.wav");
    music_.setLoop(true);
    music_.play();

}

void Game::shutDown()
{
	enemyFleet_.clear();
    meteors_.clear();
    rockets_.clear();
    tanks_.clear();
    fuelTanks_.clear();
    tiles_.clear();
    mines_.clear();
}

void Game::restart()
{
    state_ = State::Playing;

    isRunning_ = true;

    player.reset();

    totalDistance_ = 2666.0f * (level_ - 1);

    player.setPosition(resolution_.x / 2.0f, resolution_.y / 2.0f);
}

int Game::getLives()
{
    return lives_;
}
void Game::setLives(int lives)
{
    lives_ += lives;
}

Time Game::getTotalTime()
{
    return totalTime_;
}

int Game::getScore()
{
    return score_;
}
void Game::setScore(int score)
{
    score_ += score;
}
