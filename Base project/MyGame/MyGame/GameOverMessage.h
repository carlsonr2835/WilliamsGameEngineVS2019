#pragma once

#include "Engine/GameEngine.h"

class GameOverMessage : public GameObject
{
public:
	//creaes gameovermessage instance
	GameOverMessage(int score);

	//functions overriden by game objects
	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Text text_;
};

typedef std::shared_ptr<GameOverMessage> GameOverMessagePtr;