#include "Enemy.h"

Enemy::Enemy(Texture* spaceship, int Hp, int level)
{
	this->Maxhp = Hp;
	this->Hp = Hp;
	Level = Level;
	

	spacecraft.setTexture(spaceship);
	spacecraft.setSize(Vector2f(80.0f, 80.0f));
	spacecraft.setOrigin(40.0f, 40.0f);
	random = rand() % 4;
	
	denemy.setFillColor(Color(255 , 0 , 0));

	enemydamage = 10 + (level * 3);
	
	if (random == 0)
	{
		//บน
		position.x = rand() % 1920;
		position.y = -100;
	}

	if (random == 1)
	{
		//ซ้าย
		position.x = -100;
		position.y = rand() % 1080;
	}

	if (random == 2)
	{
		//ล่าง
		position.x = rand() % 1920;
		position.y = 1180;
	}

	if (random == 3)
	{
		//ขวา
		position.x = 2020;
		position.y = rand() % 1080;
	}

	spacecraft.setPosition(position);
	direction = rotateVector(Vector2f(0, -1), spacecraft.getRotation());
	//momentum = 200.0f;
	speed = 0.5f;
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime, Vector2f position)
{
	spacecraft.move(Vector2f(position.x - spacecraft.getPosition().x, position.y - spacecraft.getPosition().y)* deltaTime * speed);
	float Hpbar = this->Hp / this->Maxhp;
	denemy.setSize(Vector2f(Hpbar * 80.0f, 10.0f));
	denemy.setPosition(Vector2f(spacecraft.getPosition().x - 40 , spacecraft.getPosition().y + 40));
	
}

void Enemy::draw(RenderWindow& window)
{
	window.draw(spacecraft);
	window.draw(denemy);
}

float Enemy::getdamage()
{
	return enemydamage;
}
