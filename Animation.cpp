#include "Animation.h"

Animation::Animation(string name, string textureFileName, Time duration, bool loop, Vector2f position,
	Vector2f textureStartPosition, Vector2i spriteSize, int framesNum)
{
	name_ = name;
	duration_ = duration;
	loop_ = loop;
	position_ = position;
	textureStartPosition_ = textureStartPosition;
	spriteSize_ = spriteSize;
	framesNum_ = framesNum;
	textureFileName_ = textureFileName;

	sprite_ = Sprite(AssetManager::GetTexture(textureFileName));
	//this->sprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));
}

bool Animation::update(Time dt, Vector2f position)
{
	elapsedTime_ += dt;

	int animFrame = static_cast<int>((elapsedTime_.asSeconds() / duration_.asSeconds()) * framesNum_) % framesNum_;
	
	sprite_.setTextureRect(sf::IntRect(animFrame * spriteSize_.x, 0, spriteSize_.x, spriteSize_.y));

	sprite_.setPosition(position);

	if (!loop_ && (animFrame == (framesNum_ - 1)))
	{
		return true;
	}

	return false;
}

Sprite& Animation::getSprite()
{
	return sprite_;
}

void Animation::resetElapsedTime()
{
	elapsedTime_ = seconds(0.0);
}
