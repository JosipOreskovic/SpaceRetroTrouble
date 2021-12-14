//
// Created by josip on 07.08.2021.
//

#include "AssetManager.h"
#include "Animation.h"
#include "Bomb.h"
#include "Missile.h"

using namespace sf;
using namespace std;


class Player
{
public:
    Player();
   
	Sprite& getShipSprite();
    Vector2f getPosition() const;

    int getFuelLevel() const;
    void setFuelLevel(int fuel);

	vector<shared_ptr<GameObject>>& getMissiles();
    vector<shared_ptr<GameObject>>& getBombs();

	void setPosition(float x, float y);
    void reset();

    void input(Event& event, Time totalTime);

    bool update(Time dt, Time totalTime, Vector2f resolution);
    void updateBombs(Time dt, Time totalTime, Vector2f resolution);
    void updateMissiles(Time dt, Time totalTime, Vector2f resolution);
    void updateShip(Time dt, Vector2f resolution);
    void updateFuel(Time totalTime);

    void draw(RenderWindow &window);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    void hit(Vector2f hitPosition, Time totalTime);
    bool isActive() const;
    void setActive();

private:
    Vector2f position_;
    string name_;
    bool active_;
    float speed_;

    Sprite shipSprite_;
    Sprite engineSprite_;
    Sprite explosionSprite_;

    Animation* engineAnim_;
    Animation* explosionAnim_;

    Vector2f playerHitPosition_;

    int fuelLevel_;
    Time fuelUseTime_;
    bool outOfFuel_;


    bool upPressed_;
    bool downPressed_;
    bool leftPressed_;
    bool rightPressed_;

    vector<shared_ptr<GameObject>> bombs_;
    vector<shared_ptr<GameObject>> missiles_;

    bool newBomb_;
    Time lastBombTime_;
    Time newBombTime_;

    bool newMissile_;
    Time lastMissileTime_;
    Time newMissileTime_;
};
