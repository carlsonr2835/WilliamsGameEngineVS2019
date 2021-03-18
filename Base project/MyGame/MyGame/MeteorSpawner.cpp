#include "MeteorSpawner.h"

//milliseconds between spawns
const int SPAWN_DELAY = 1000;

void MeteorSpawner::update(sf::Time& elapsed)
{
	//determine how much time is passed and adjust out timer
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	//if timer elapsed reset and spawn a meteor
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		//spawn meteor off on right side of screen
		//assuming meteor isn't more than 100 pixels wide
		float meteorX = (float)(size.x + 100);

		//spawn it somewhere along height of window randomly
		float meteorY = (float)(rand() % size.y);

		//create meteor and add it to the scene
		MeteorPtr meteor = std::make_shared<Meteor>(sf::Vector2f(meteorX, meteorY));
		GAME.getCurrentScene().addGameObject(meteor);

	}
}