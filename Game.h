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
#include "DeleteObjects.h"


using namespace sf;

class Game {
public:
    Game();
    void run();

private:

    // Private methods

    void input();
    void update(Time dt);
    void draw();
    void initialize();
    void shutDown();
    void restart();

    Time getTotalTime();

    void spawnTiles();
    void spawnMines();
    void spawnEnemyFleet();
    void spawnMeteors();
    void spawnRockets(Time dt);
    void spawnTanks(Time dt);
    void spawnFuelTanks(Time dt);

    void updateGameObjects(Time dt, vector<GameObject*>& gameObjects);
    void updateGameObjects(Time dt, vector<GameObject*>& gameObjects, Vector2f playerPosition);

    void updateHUD();
    void updateBackground(Time dt);

    void collision();

    int getLives();
    void setLives(int lives);

    int getScore();
    void setScore(int score);

    void detectCollision(Player& player, GameObject*& gameObject, Time totalTime, bool destruct);
    void detectCollision(Player& player, vector<GameObject*>& gameObjects, Time totalTime, bool destruct);
    void detectCollision(const vector<GameObject*>& playerObjects, const vector<GameObject*>& gameObjects, Time totalTime,
         bool destruct, int score, int fuel);

    //friend void removeObjects(vector<GameObject*>& objects);
    friend void deleteObjects(vector<GameObject*>& objects);

    // Private members

    RenderWindow window_;

    bool isRunning_;

    AssetManager assetManager_;
    SoundManager soundManager_;

    Player player;

    enum class State {Start, Playing, Paused, Next_Level, Game_Over} state_;

    Background background_;

    vector<GameObject*> enemyFleet_;
    vector<GameObject*> meteors_;
    vector<GameObject*> rockets_;
    vector<GameObject*> tanks_;
    vector<GameObject*> fuelTanks_;
    vector<GameObject*> tiles_;
    vector<vector<GameObject*>> tileSets_;
    vector<GameObject*> mines_;

    Time lastEnemyShipTime_;
    Time lastMeteorTime_;
    Time lastRocketTime_;
    Time lastTankTime_;
    Time lastfuelTankTime_;
    Time lastMineTime_;

    Vector2f resolution_;
    Time totalTime_;
    float totalDistance_ = 0.0;
    bool levelChange_ = false;

    int score_;
    int hiScore_;
    int lives_;
    int level_;

    Music music_;

    Text scoreText_;
    Text livesText_;
    Text messageText_;
};
