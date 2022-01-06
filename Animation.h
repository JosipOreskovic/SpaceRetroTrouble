#pragma once

#include "AssetManager.h"

class Animation
{
public:
	Animation() = default;
	Animation(std::string name, std::string textureFileName, sf::Time duration, bool loop, sf::Vector2f position, sf::Vector2f textureStartPosition,
	          sf::Vector2i spriteSize, int framesNum);
	bool update(sf::Time dt, sf::Vector2f position);
	sf::Sprite& getSprite();
	void resetElapsedTime();
private:
	sf::Sprite sprite_;
	sf::Vector2i spriteSize_;
	sf::Vector2f position_;
	sf::Vector2f textureStartPosition_;
	std::string textureFileName_;
	std::string name_;
	sf::Time elapsedTime_;
	int framesNum_;
	sf::Time duration_;
	sf::Time animStartTime_;
	bool loop_;

};

