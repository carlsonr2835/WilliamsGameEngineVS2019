#pragma once
#include "Engine/GameEngine.h"

class Score : public GameObject
{
public:
	//creates the score instance
	Score(sf::Vector2f pos);

	//functions overriden from gameobject:
	void draw();
	void update(sf::Time& elsapsed);

private:
	sf::Text text_;
};

typedef std::shared_ptr<Score> ScorePtr;