//
// Created by josip on 21.08.2021..
//

#include "Game.h"

void Game::update(Time dt) {

    if (state_ == State::Start)
    {
        messageText_.setString("SPACE RETRO TROUBLE\n\nPress P to play\nPress Q to quit");
        messageText_.setCharacterSize(70);
        messageText_.setFillColor(Color::White);
        messageText_.setPosition(resolution_.x / 2 - 300, resolution_.y / 2 - 200);
    }

    if (state_ == State::Game_Over)
    {
        shutDown();

        messageText_.setString("Game over!\n\nPress P to play\nPress Q to quit");
        messageText_.setCharacterSize(70);
        messageText_.setFillColor(Color::White);
        messageText_.setPosition(resolution_.x / 2  - 300, resolution_.y / 2  - 200);
    }

    if (state_ == State::Paused)
    {
        messageText_.setString("Paused\n\nPress Esc to resume\nPress Q to quit");
        messageText_.setCharacterSize(70);
        messageText_.setFillColor(Color::White);
        messageText_.setPosition(resolution_.x / 2  - 300, resolution_.y / 2  - 200);
    }

    if (state_ == State::Playing)
    {
        collision();

        // Spawn game objects from files

        if (tiles_.empty() || levelChange_)
            spawnTiles();
        if (rockets_.empty() || levelChange_)
            spawnRockets(dt);
        if (fuelTanks_.empty() || levelChange_)
            spawnFuelTanks(dt);
        if (tanks_.empty() || levelChange_)
            spawnTanks(dt);

        if (level_ == 2 && mines_.empty())
            spawnMines();
        if (level_ == 3 && meteors_.empty())
			spawnMeteors();
        if (level_ == 4 && enemyFleet_.empty())
			spawnEnemyFleet();

        if (levelChange_)
            levelChange_ = false;

        // Player update

        if (player.update(dt, totalTime_, resolution_))
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
        }

        // Game objects update

        if (level_ == 4 || !enemyFleet_.empty())
        {
            updateGameObjects(dt, enemyFleet_);
        }

        if (level_ == 3 || !meteors_.empty())
        {
            updateGameObjects(dt, meteors_);
        }

        if (level_ == 1 || !mines_.empty())
        {
            updateGameObjects(dt,mines_);
        }


        updateGameObjects(dt, rockets_, player.getPosition());
        updateGameObjects(dt, tanks_, player.getPosition());
        updateGameObjects(dt, fuelTanks_);
        updateGameObjects(dt, tiles_);

        background_.update(dt, resolution_);

        updateHUD();
        totalDistance_ += 200 * dt.asSeconds();

        if (totalDistance_ > 1984 * level_)
        {
        	level_++;
            levelChange_ = true;
            if (level_ == 5)
                state_ = State::Game_Over;
        }
    }
}

void Game::updateGameObjects(Time dt, vector<GameObject*>& gameObjects)
{
    for (const auto& gameObject : gameObjects)
    {
        if (gameObject->getPosition().x < -256 || gameObject->getPosition().y < 0)
        {
            gameObject->stop();
        }
        if (gameObject->isActive())
            gameObject->update(dt, totalTime_);
    }
}

void Game::updateGameObjects(Time dt, vector<GameObject*>& gameObjects, Vector2f playerPosition)
{
    for (const auto& gameObject : gameObjects)
    {
        if (gameObject->getPosition().x < -256 || gameObject->getPosition().y < 0)
        {
            gameObject->stop();
        }
        if (gameObject->isActive())
            gameObject->update(dt, totalTime_, playerPosition);
    }
}

void Game::updateHUD()
{

    stringstream ss;
    ss << "Score: " << score_;
    ss << "         " << "Lives: " << lives_;
    ss << "         " << "Fuel: " << player.getFuelLevel();
    ss << "         " << "Level: " << level_;

    scoreText_.setString(ss.str());
    scoreText_.setCharacterSize(55);
    scoreText_.setFillColor(Color::White);
    scoreText_.setPosition(20, 0);

    ss.str("");
}
