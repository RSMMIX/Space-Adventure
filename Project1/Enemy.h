#pragma once
#include "Pawn.h"

class Enemy
{
public:
	Enemy(Texture* spaceship);
	~Enemy();


	RectangleShape spacecraft;

	void update(float deltaTime, Vector2f position);
	void draw(RenderWindow& window);

private:
	int random;
	Vector2f position , direction;
	Sprite enemy;
	int Hp;
	int Maxhp;
	int Level;
	float speed;

};
