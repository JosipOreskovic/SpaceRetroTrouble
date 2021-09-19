#pragma once

#include "AssetManager.h"

using namespace sf;
using namespace std;

class Animation
{
public:
	Animation() = default;
	Animation(string name, string textureFileName, Time duration, bool loop, Vector2f position, Vector2f textureStartPosition,
		Vector2i spriteSize, int framesNum);
	bool update(Time dt, Vector2f position);
	Sprite& getSprite();
	void resetElapsedTime();
private:
	Sprite sprite_;
	Vector2i spriteSize_;
	Vector2f position_;
	Vector2f textureStartPosition_;
	string textureFileName_;
	string name_;
	Time elapsedTime_;
	int framesNum_;
	Time duration_;
	Time animStartTime_;
	bool loop_;

};

