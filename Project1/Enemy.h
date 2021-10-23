#pragma once
#include "Pawn.h"

class Enemy
{
public:
	Enemy(Texture* spaceship, int Hp, int level);
	~Enemy();

	RectangleShape spacecraft;
	RectangleShape denemy;

	void update(float deltaTime, Vector2f position);
	void draw(RenderWindow& window);
	float getdamage();
	
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
	float Hp;
	float Maxhp;
	int Level;
	float speed;
	float enemydamage;

};
