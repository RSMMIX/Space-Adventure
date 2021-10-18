#pragma once
#include "Pawn.h"
class Bullet
{
public:
	Bullet(Texture* spaceship,Vector2f position, float degree);
	~Bullet();

	RectangleShape spacecraft;

	void update(float deltaTime);
	void draw(RenderWindow& window);


private:
	Vector2f direction;
	float speed, momentum;
};
