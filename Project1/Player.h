#pragma once
#include "Library.h"

class Player
{
public:
	Player(Texture &spaceship, float Hp);
	~Player();

	Sprite spacecraft;
	RectangleShape Hpbulb;
	RectangleShape HpbulbMax;

	void update(float deltaTime);
	void draw(RenderWindow &window);
	void setHp(float Hp);
	float getMaxhp();
	

private:
	Vector2f direction;
	float speed, momentum;
	float Hp;
	float Maxhp;
	int Level;
};
