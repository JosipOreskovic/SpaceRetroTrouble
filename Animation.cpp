#include "Animation.h"

Animation::Animation(std::string name, std::string textureFileName, sf::Time duration, bool loop, sf::Vector2f position,
	sf::Vector2f textureStartPosition, sf::Vector2i spriteSize, int framesNum)
{
	name_ = name;
	duration_ = duration;
	loop_ = loop;
	position_ = position;
	textureStartPosition_ = textureStartPosition;
	spriteSize_ = spriteSize;
	framesNum_ = framesNum;
	textureFileName_ = textureFileName;

	sprite_ = sf::Sprite(AssetManager::GetTexture(textureFileName));
}

bool Animation::update(sf::Time dt, sf::Vector2f position)
{
	elapsedTime_ += dt;

	int animFrame = static_cast<int>((elapsedTime_.asSeconds() / duration_.asSeconds()) * framesNum_) % framesNum_;
	
	sprite_.setTextureRect(sf::IntRect(animFrame * spriteSize_.x, 0.0f, spriteSize_.x, spriteSize_.y));

	sprite_.setPosition(position);
	sprite_.setOrigin(sprite_.getLocalBounds().width / 2.0f, sprite_.getLocalBounds().height / 2.0f);

	if (!loop_ && (animFrame == (framesNum_ - 1)))
	{
		return true;
	}

	return false;
}

sf::Sprite& Animation::getSprite()
{
	return sprite_;
}

void Animation::resetElapsedTime()
{
	elapsedTime_ = sf::seconds(0.0f);
}
