#pragma once
#include "Pawn.h"

class Enemy
{
public:
	Enemy(Texture* spaceship, int MaxHp , int Hp);
	~Enemy();

	RectangleShape spacecraft;

	void update(float deltaTime, Vector2f position);
	void draw(RenderWindow& window);
	
	FloatRect getGlobalBounds() 
	{ 
		return spacecraft.getGlobalBounds(); 
	}
	Vector2f getPosition() 
	{ 
		return spacecraft.getPosition(); 
	}
	void setHp(int damage) 
	{ 
		Hp -= damage; 
	}
	int getHp() 
	{ 
		return Hp; 
	}

private:
	int random;
	Vector2f position , direction;
	Sprite enemy;
	int Hp;
	int Maxhp;
	int Level;
	float speed;

};
