#include "Background.h"
#include "GameScene.h"
#include <memory>

const float SPEED = 0.1f;

Background::Background()
{
	sprite_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite2_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_.setPosition(sf::Vector2f(0, 0));
	sprite2_.setPosition(sf::Vector2f(800, 0));
}
void Background::draw()
{
	GAME.getRenderWindow().draw(sprite_);
	GAME.getRenderWindow().draw(sprite2_);
}
void Background::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	sf::Vector2f pos2 = sprite2_.getPosition();

	sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	sprite2_.setPosition(sf::Vector2f(pos2.x - SPEED * msElapsed, pos2.y));

	if (pos2.x < 0)
	{
		sprite_.setTexture(GAME.getTexture("Resources/background.png"));
		sprite2_.setTexture(GAME.getTexture("Resources/background.png"));
		sprite_.setPosition(sf::Vector2f(0, 0));
		sprite2_.setPosition(sf::Vector2f(800, 0));
		GAME.getRenderWindow().draw(sprite_);
		GAME.getRenderWindow().draw(sprite2_);
	}

}