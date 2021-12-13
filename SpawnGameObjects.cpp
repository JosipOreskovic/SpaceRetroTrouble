#include "Game.h"

void Game::spawnGameObjects()
{
    if (tiles_.empty() || levelChange_)
        spawn("Tiles", tiles_);
    if (rockets_.empty() || levelChange_)
        spawn("Rockets", rockets_);
    if (fuelTanks_.empty() || levelChange_)
        spawn("FuelTanks", fuelTanks_);
    if (tanks_.empty() || levelChange_)
        spawn("PlasmaCannons", tanks_);

    if (level_ == 2 && mines_.empty())
        spawn("Mines", mines_);
    if (level_ == 3 && meteors_.empty())
        spawn("Meteors", meteors_);
    if (level_ == 4 && enemyFleet_.empty())
        spawn("EnemyFleet", enemyFleet_);

    if (levelChange_)
        levelChange_ = false;
}

void Game::spawn(string objectName, vector<shared_ptr<GameObject>>& gameObjects)
{
    string fileName("Assets/Levels/Level" + to_string(level_) + "/" + objectName + ".txt");
    string s;
    ifstream inFile(fileName);

    while (getline(inFile, s))
    {
        Vector2f pos;
        stringstream ss(s);
        ss >> pos.x >> pos.y;

        if (objectName == "Tiles")
        {
            int type;
            ss >> type;
            tiles_.push_back(make_shared<Tile>(resolution_.x + pos.x * TILE_DIMENSION, resolution_.y - pos.y * TILE_DIMENSION, GAME_SPEED, false, 0, 0));
            tiles_.back()->getSprite().setTexture(AssetManager::GetTexture("Assets/Graphics/Tiles/Level" + to_string(level_) + "/Tile" + to_string(type) + ".png"));
        }


        if (objectName == "Rockets")
        {
            rockets_.push_back(make_shared<Rocket>(resolution_.x + pos.x * TILE_DIMENSION, resolution_.y - pos.y * TILE_DIMENSION, GAME_SPEED, true, 10, 0));
        }


        if (objectName == "PlasmaCannons")
        {
            tanks_.push_back(make_shared<Tank>(resolution_.x + pos.x * TILE_DIMENSION, resolution_.y - pos.y * TILE_DIMENSION, GAME_SPEED, true, 10, 0));
        }


        if (objectName == "FuelTanks")
        {
            fuelTanks_.push_back(make_shared<FuelTank>(resolution_.x + pos.x * TILE_DIMENSION, resolution_.y - pos.y * TILE_DIMENSION, GAME_SPEED, true, 10, 10));
        }

        if (objectName == "Mines")
        {
            mines_.push_back(make_shared<Mine>(resolution_.x + pos.x * TILE_DIMENSION, pos.y * TILE_DIMENSION, GAME_SPEED, true, 10, 0));
        }


        if (objectName == "Meteors")
        {
            float speed;
            ss >> speed;
            meteors_.push_back(make_shared<Meteor>(resolution_.x + pos.x * TILE_DIMENSION, pos.y * TILE_DIMENSION, speed, true, 10, 0));
        }

        if (objectName == "EnemyFleet")
        {
            float speed;
            ss >> speed;
            enemyFleet_.push_back(make_shared<EnemyShip>(resolution_.x + pos.x * TILE_DIMENSION, pos.y * TILE_DIMENSION, speed, true, 10, 0));
        }
    }
}