#pragma once
#include "Library.h"

class Enemy
{
public:
	Enemy(Texture* spaceship, int Hp, int level , int randomtype);
	~Enemy();
	
	RectangleShape spacecraft;
	RectangleShape denemy;
	RectangleShape denemyMax;

	void update(float deltaTime, Vector2f position);
	void draw(RenderWindow& window);
	float getdamage();
	int getlevel();
	
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
	float speed;
	float enemydamage;
	float type_4_x;
	float type_4_y;
	float type_4_time;
	int Level;
	int randomtype;
};
