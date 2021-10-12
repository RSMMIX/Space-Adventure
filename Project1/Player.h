#pragma once
#include "Pawn.h"

class Player
{
public:
	Player(Texture &spaceship);
	~Player();

	Sprite spacecraft;

	void update(float deltaTime);
	void draw(RenderWindow &window);
	

private:
	Vector2f direction;
	float speed, momentum;
};
