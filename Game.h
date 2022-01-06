//
// Created by josip on 13.08.2021..
//

#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Animation.h"
#include "AssetManager.h"
#include "SoundManager.h"
#include "Player.h"
#include "Background.h"
#include "EnemyShip.h"
#include "Meteor.h"
#include "Bomb.h"
#include "Missile.h"
#include "Rocket.h"
#include "Tank.h"
#include "Tile.h"
#include "FuelTank.h"
#include "Mine.h"
#include "TankMissile.h"

class Game
{
public:

	// Public methods

	Game();
    void run();

private:

    // Private methods

    void input();
    void update(sf::Time dt);
    void draw();
    void lateUpdate();
    void initialize();
    void shutDown();
    void restart();

	sf::Time getTotalTime() const;

    void spawnTiles();
    void spawnMines();
    void spawnEnemyFleet();
    void spawnMeteors();
    void spawnRockets(sf::Time dt);
    void spawnTanks(sf::Time dt);
    void spawnFuelTanks(sf::Time dt);

    void updateGameObjects(sf::Time dt, std::vector<std::shared_ptr<GameObject>>& gameObjects);
    void updateGameObjects(sf::Time dt, std::vector<std::shared_ptr<GameObject>>& gameObjects, sf::Vector2f playerPosition);

    void spawnGameObjects();
    void spawn(std::string objectName, std::vector<std::shared_ptr<GameObject>>& gameObjects);

    void updateHUD();
    void updateBackground(sf::Time dt);

    void collision();

    int getLives() const;
    void setLives(int lives);

    int getScore() const;
    void setScore(int score);

    void DetectCollision(Player& player, std::shared_ptr<GameObject> const& gameObject, sf::Time const& totalTime);
    void DetectCollision(Player& player, std::vector<std::shared_ptr<GameObject>> const& gameObjects, sf::Time const& totalTime);
    void DetectCollision(std::vector<std::shared_ptr<GameObject>> const& playerObjects, std::vector<std::shared_ptr<GameObject>> const& gameObjects, sf::Time const &totalTime);

    //friend void removeObjects(vector<shared_ptr<GameObject>>& objects);
    friend void deleteObjects(std::vector<std::shared_ptr<GameObject>>& objects);

    // Private members

    sf::RenderWindow window_;

    bool isRunning_;

    AssetManager assetManager_;
    SoundManager soundManager_;

    Player player;

    enum class State {Start, Playing, Paused, Next_Level, Game_Over} state_;

    Background background_;

    std::vector<std::shared_ptr<GameObject>> enemyFleet_;
    std::vector<std::shared_ptr<GameObject>> meteors_;
    std::vector<std::shared_ptr<GameObject>> rockets_;
    std::vector<std::shared_ptr<GameObject>> tanks_;
    std::vector<std::shared_ptr<GameObject>> fuelTanks_;
    std::vector<std::shared_ptr<GameObject>> tiles_;
    std::vector<std::vector<std::shared_ptr<GameObject>>> tileSets_;
    std::vector<std::shared_ptr<GameObject>> mines_;

    sf::Time lastEnemyShipTime_;
    sf::Time lastMeteorTime_;
    sf::Time lastRocketTime_;
    sf::Time lastTankTime_;
    sf::Time lastfuelTankTime_;
    sf::Time lastMineTime_;

    sf::Vector2f resolution_;
    sf::Time totalTime_;
    float totalDistance_;
    bool levelChange_;
    bool levelRestart_;

    int score_;
    int hiScore_;
    int lives_;
    int level_;

    sf::Music music_;

    sf::Text scoreText_;
    sf::Text livesText_;
    sf::Text messageText_;
};
