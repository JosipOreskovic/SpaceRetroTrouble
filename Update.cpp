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

        if (tiles_.empty())
			spawnTiles();
        if (rockets_.empty())
            spawnRockets(dt);
        if (fuelTanks_.empty())
            spawnFuelTanks(dt);

        if (level_ == 1 && mines_.empty())
            spawnMines();
        if (level_ >= 2 && tanks_.empty())
			spawnTanks(dt);
        if (level_ == 3 && meteors_.empty())
			spawnMeteors();
        if (level_ == 4 && enemyFleet_.empty())
			spawnEnemyFleet();

       

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

        if (level_ >= 2 || !tanks_.empty())
        {
            updateGameObjects(dt, tanks_, player.getPosition());
        }

       
        updateGameObjects(dt, fuelTanks_);
        updateGameObjects(dt, tiles_);
        updateGameObjects(dt, rockets_, player.getPosition());

        background_.update(dt, resolution_);

        updateHUD();

        if (nextLevelTime_.asSeconds() > 10)
        {
            level_++;
            nextLevelTime_ = seconds(0.0);
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


void Game::spawnTiles()
{
    string fileName("Assets/Levels/Tiles.txt");
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
    string fileName("Assets/Levels/EnemyFleet.txt");
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
    string fileName("Assets/Levels/Meteors.txt");
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
    string fileName("Assets/Levels/Mines.txt");
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
    string fileName("Assets/Levels/Rockets.txt");
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
    string fileName("Assets/Levels/PlasmaCannons.txt");
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
    string fileName("Assets/Levels/FuelTanks.txt");
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
