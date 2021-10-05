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
            tiles_.push_back(shared_ptr<Tile>(new Tile(resolution_.x + pos.x * TILE_DIMENSION, resolution_.y - pos.y * TILE_DIMENSION, GAME_SPEED)));
            tiles_.back()->getSprite().setTexture(AssetManager::GetTexture("Assets/Graphics/Tiles/Level" + to_string(level_) + "/Tile" + to_string(type) + ".png"));
        }


        if (objectName == "Rockets")
        {
            rockets_.push_back(shared_ptr<Rocket>(new Rocket(resolution_.x + pos.x * TILE_DIMENSION, resolution_.y - pos.y * TILE_DIMENSION, GAME_SPEED)));
        }


        if (objectName == "PlasmaCannons")
        {
            tanks_.push_back(shared_ptr<Tank>(new Tank(resolution_.x + pos.x * TILE_DIMENSION, resolution_.y - pos.y * TILE_DIMENSION, GAME_SPEED)));
        }


        if (objectName == "FuelTanks")
        {
            fuelTanks_.push_back(shared_ptr<FuelTank>(new FuelTank(resolution_.x + pos.x * TILE_DIMENSION, resolution_.y - pos.y * TILE_DIMENSION, GAME_SPEED)));
        }

        if (objectName == "Mines")
        {
            mines_.push_back(shared_ptr<Mine>(new Mine(resolution_.x + pos.x * TILE_DIMENSION, pos.y * TILE_DIMENSION, GAME_SPEED)));
        }


        if (objectName == "Meteors")
        {
            float speed;
            ss >> speed;
            meteors_.push_back(shared_ptr<Meteor>(new Meteor(resolution_.x + pos.x * TILE_DIMENSION, pos.y * TILE_DIMENSION, speed)));
        }

        if (objectName == "EnemyFleet")
        {
            float speed;
            ss >> speed;
            enemyFleet_.push_back(shared_ptr<EnemyShip>(new EnemyShip(resolution_.x + pos.x * TILE_DIMENSION, pos.y * TILE_DIMENSION, speed)));
        }
    }
}
//
//void Game::spawnTiles()
//{
//    string fileName("Assets/Levels/Level" + to_string(level_) + "/Tiles.txt");
//    string s;
//    ifstream inFile(fileName);
//
//    while (getline(inFile, s))
//    {
//        Vector2f pos;
//        float speed;
//        int type;
//        stringstream ss(s);
//        ss >> pos.x >> pos.y >> speed;
//        ss >> type;
//        tiles_.push_back(new Tile(resolution_.x + pos.x, resolution_.y - pos.y, speed));
//        tiles_.back()->getSprite().setTexture(AssetManager::GetTexture("Assets/Graphics/Tile" + to_string(type) + ".png"));
//    }
//}
//
//void Game::spawnEnemyFleet()
//{
//    string fileName("Assets/Levels/Level" + to_string(level_) + "/EnemyFleet.txt");
//    string s;
//    ifstream inFile(fileName);
//
//    while (getline(inFile, s))
//    {
//        Vector2f pos;
//        float speed;
//        stringstream ss(s);
//        ss >> pos.x >> pos.y >> speed;
//        enemyFleet_.push_back(new EnemyShip(resolution_.x + pos.x, pos.y, speed));
//    }
//}
//
//void Game::spawnMeteors()
//{
//    string fileName("Assets/Levels/Level" + to_string(level_) + "/Meteors.txt");
//    string s;
//    ifstream inFile(fileName);
//
//    while (getline(inFile, s))
//    {
//        Vector2f pos;
//        float speed;
//        stringstream ss(s);
//        ss >> pos.x >> pos.y >> speed;
//        meteors_.push_back(new Meteor(resolution_.x + pos.x, pos.y, speed));
//    }
//}
//
//void Game::spawnMines()
//{
//    string fileName("Assets/Levels/Level" + to_string(level_) + "/Mines.txt");
//    string s;
//    ifstream inFile(fileName);
//
//    while (getline(inFile, s))
//    {
//        Vector2f pos;
//        float speed;
//        stringstream ss(s);
//        ss >> pos.x >> pos.y >> speed;
//        mines_.push_back(new Mine(resolution_.x + pos.x, pos.y, speed));
//    }
//}
//
//void Game::spawnRockets()
//{
//    string fileName("Assets/Levels/Level" + to_string(level_) + "/Rockets.txt");
//    string s;
//    ifstream inFile(fileName);
//
//    while (getline(inFile, s))
//    {
//        Vector2f pos;
//        float speed;
//        stringstream ss(s);
//        ss >> pos.x >> pos.y >> speed;
//        rockets_.push_back(new Rocket(resolution_.x + pos.x, resolution_.y - pos.y, speed));
//    }
//}
//
//void Game::spawnTanks()
//{
//    string fileName("Assets/Levels/Level" + to_string(level_) + "/PlasmaCannons.txt");
//    string s;
//    ifstream inFile(fileName);
//
//    while (getline(inFile, s))
//    {
//        Vector2f pos;
//        float speed;
//        stringstream ss(s);
//        ss >> pos.x >> pos.y >> speed;
//        tanks_.push_back(new Tank(resolution_.x + pos.x, resolution_.y - pos.y, speed));
//    }
//}
//
//void Game::spawnFuelTanks()
//{
//    string fileName("Assets/Levels/Level" + to_string(level_) + "/FuelTanks.txt");
//    string s;
//    ifstream inFile(fileName);
//
//    while (getline(inFile, s))
//    {
//        Vector2f pos;
//        float speed;
//        stringstream ss(s);
//        ss >> pos.x >> pos.y >> speed;
//        fuelTanks_.push_back(new FuelTank(resolution_.x + pos.x, resolution_.y - pos.y, speed));
//    }
//}
