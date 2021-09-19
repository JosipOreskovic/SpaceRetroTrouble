#include "Game.h"

void Game::spawnTiles()
{
    string fileName("Assets/Levels/Level" + to_string(level_) + "/Tiles.txt");
    string s;
    ifstream inFile(fileName);

    while (getline(inFile, s))
    {
        Vector2f position;
        float speed;
        int type;
        stringstream ss(s);
        ss >> position.x >> position.y >> speed;
        ss >> type;
        tiles_.push_back(new Tile(resolution_.x + position.x, resolution_.y - position.y, speed));
        tiles_.back()->getSprite().setTexture(AssetManager::GetTexture("Assets/Graphics/Tile" + to_string(type) + ".png"));
    }
}

void Game::spawnEnemyFleet()
{
    string fileName("Assets/Levels/Level" + to_string(level_) + "/EnemyFleet.txt");
    string s;
    ifstream inFile(fileName);

    while (getline(inFile, s))
    {
        Vector2f position;
        float speed;
        stringstream ss(s);
        ss >> position.x >> position.y >> speed;
        enemyFleet_.push_back(new EnemyShip(resolution_.x + position.x, position.y, speed));
    }
}

void Game::spawnMeteors()
{
    string fileName("Assets/Levels/Level" + to_string(level_) + "/Meteors.txt");
    string s;
    ifstream inFile(fileName);

    while (getline(inFile, s))
    {
        Vector2f position;
        float speed;
        stringstream ss(s);
        ss >> position.x >> position.y >> speed;
        meteors_.push_back(new Meteor(resolution_.x + position.x, position.y, speed));
    }
}

void Game::spawnMines()
{
    string fileName("Assets/Levels/Level" + to_string(level_) + "/Mines.txt");
    string s;
    ifstream inFile(fileName);

    while (getline(inFile, s))
    {
        Vector2f position;
        float speed;
        stringstream ss(s);
        ss >> position.x >> position.y >> speed;
        mines_.push_back(new Mine(resolution_.x + position.x, position.y, speed));
    }
}

void Game::spawnRockets(Time dt)
{
    string fileName("Assets/Levels/Level" + to_string(level_) + "/Rockets.txt");
    string s;
    ifstream inFile(fileName);

    while (getline(inFile, s))
    {
        Vector2f position;
        float speed;
        stringstream ss(s);
        ss >> position.x >> position.y >> speed;
        rockets_.push_back(new Rocket(resolution_.x + position.x, resolution_.y - position.y, speed));
    }
}

void Game::spawnTanks(Time dt)
{
    string fileName("Assets/Levels/Level" + to_string(level_) + "/PlasmaCannons.txt");
    string s;
    ifstream inFile(fileName);

    while (getline(inFile, s))
    {
        Vector2f position;
        float speed;
        stringstream ss(s);
        ss >> position.x >> position.y >> speed;
        tanks_.push_back(new Tank(resolution_.x + position.x, resolution_.y - position.y, speed));
    }
}

void Game::spawnFuelTanks(Time dt)
{
    string fileName("Assets/Levels/Level" + to_string(level_) + "/FuelTanks.txt");
    string s;
    ifstream inFile(fileName);

    while (getline(inFile, s))
    {
        Vector2f position;
        float speed;
        stringstream ss(s);
        ss >> position.x >> position.y >> speed;
        fuelTanks_.push_back(new FuelTank(resolution_.x + position.x, resolution_.y - position.y, speed));
    }
}
