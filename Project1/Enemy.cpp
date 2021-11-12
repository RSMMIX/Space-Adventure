#include "Enemy.h"

Enemy::Enemy(Texture* spaceship, int Hp, int level ,int randomtype)
{
	this->Maxhp = Hp;
	this->Hp = Hp;
	this->randomtype = randomtype;
	this->type_4_time = 0.0f;
	Level = Level;
	
	spacecraft.setTexture(spaceship);
	spacecraft.setSize(Vector2f(80.0f, 80.0f));
	spacecraft.setOrigin(40.0f, 40.0f);
	random = rand() % 4;
	
	denemy.setFillColor(Color(255, 0, 0));
	denemyMax.setFillColor(Color(198, 0, 0));

	enemydamage = 10 + (level * 3);
	
	if (randomtype == 0)
	{
		//บน
		position.x = rand() % 1920;
		position.y = -100;
	}

	if (randomtype == 1)
	{
		//ซ้าย
		position.x = -100;
		position.y = rand() % 1080;
	}

	if (randomtype == 2)
	{
		//ขวา
		position.x = 2020;
		position.y = rand() % 1080;
	}
	if (randomtype == 3)
	{
		position.x = rand() % 700;
		type_4_y = 0.0f;
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
	if (randomtype == 3)
	{
		type_4_x = sinf(type_4_time += deltaTime) * 300.0f;
		spacecraft.setPosition((type_4_x) + (this->position.x + (4.5 - randomtype) * 500.f), type_4_y -= deltaTime * speed * -100.0f);
	}
	else
	{
		spacecraft.move(Vector2f(position.x - spacecraft.getPosition().x, position.y - spacecraft.getPosition().y)* deltaTime * speed);
	}

	//หลอดเลือดศัตรู
	float Hpbar = this->Hp / this->Maxhp;
	denemy.setSize(Vector2f(Hpbar * 100.0f, 10.0f));
	denemy.setPosition(Vector2f(spacecraft.getPosition().x - 20 , spacecraft.getPosition().y + 40));
	denemy.setScale(Vector2f(0.5, 0.4));
	denemyMax.setSize(Vector2f(100.0f, 10.0f));
	denemyMax.setPosition(Vector2f(spacecraft.getPosition().x - 20, spacecraft.getPosition().y + 40));
	denemyMax.setScale(Vector2f(0.5, 0.4));

}

void Enemy::draw(RenderWindow& window)
{
	window.draw(spacecraft);
	if (this->Hp / this->Maxhp < 1.0f) 
	{
		window.draw(denemyMax);
		window.draw(denemy);
	}
}

float Enemy::getdamage()
{
	return enemydamage;
}

int Enemy::getlevel()
{
	return Level;
}

