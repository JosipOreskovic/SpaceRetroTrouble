//
// Created by josip on 07.08.2021.
//

#include "AssetManager.h"
#include "Animation.h"
#include "Bomb.h"
#include "Missile.h"

class Player
{
public:
    Player();
   
    sf::Sprite& getShipSprite();
    sf::Vector2f getPosition() const;

    int getFuelLevel() const;
    void setFuelLevel(int fuel);

	std::vector<std::shared_ptr<GameObject>>& getMissiles();
    std::vector<std::shared_ptr<GameObject>>& getBombs();

	void setPosition(float x, float y);
    void reset();

    void input(sf::Event& event, sf::Time totalTime);

    bool update(sf::Time dt, sf::Time totalTime, sf::Vector2f resolution);
    void updateBombs(sf::Time dt, sf::Time totalTime, sf::Vector2f resolution);
    void updateMissiles(sf::Time dt, sf::Time totalTime, sf::Vector2f resolution);
    void updateShip(sf::Time dt, sf::Vector2f resolution);
    void updateFuel(sf::Time totalTime);

    void draw(sf::RenderWindow &window);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    void hit(sf::Vector2f hitPosition, sf::Time totalTime);
    bool isActive() const;
    void setActive();

private:
    sf::Vector2f position_;
    std::string name_;
    bool active_;
    float speed_;

    sf::Sprite shipSprite_;
    sf::Sprite engineSprite_;
    sf::Sprite explosionSprite_;

    Animation* engineAnim_;
    Animation* explosionAnim_;

    sf::Vector2f playerHitPosition_;

    int fuelLevel_;
    sf::Time fuelUseTime_;
    bool outOfFuel_;


    bool upPressed_;
    bool downPressed_;
    bool leftPressed_;
    bool rightPressed_;

    std::vector<std::shared_ptr<GameObject>> bombs_;
    std::vector<std::shared_ptr<GameObject>> missiles_;

    bool newBomb_;
    sf::Time lastBombTime_;
    sf::Time newBombTime_;

    bool newMissile_;
    sf::Time lastMissileTime_;
    sf::Time newMissileTime_;
};
