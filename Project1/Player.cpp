#include "Player.h"

Player::Player(Texture &spaceship , float Hp)
{
	spacecraft.setTexture(spaceship);
	spacecraft.setPosition(Vector2f(960, 840));
	spacecraft.setOrigin(800.f, 800.f);
	spacecraft.setScale(Vector2f(0.05, 0.05));
	spacecraft.rotate(0);
	momentum = 200.0f;
	speed = 200.0f;
	this->Maxhp = Hp;
	this->Hp = Hp;
	//หลอดเลือด
	Hpbulb.setFillColor(Color(255, 0, 0));
	HpbulbMax.setFillColor(Color(198, 0, 0));
}
Player::~Player()
{

}

//เช็คห้ามเลยครอบหน้าจอ
void Player::update(float deltaTime)
{
	direction = Vector2f(0.0f , 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (spacecraft.getPosition().y > 40)
		{
			direction = Vector2f(0, -1);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (spacecraft.getPosition().x > 40)
		{
			direction = Vector2f(-1, 0);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (spacecraft.getPosition().y < 1040)
		{
			direction = Vector2f(0, 1);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (spacecraft.getPosition().x < 1880)
		{
			direction = Vector2f(1, 0);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		spacecraft.rotate(deltaTime * -momentum);
	}

	if (Keyboard::isKeyPressed(Keyboard::E))
	{
		spacecraft.rotate(deltaTime * momentum);
	}

	spacecraft.move(direction * speed * deltaTime);

	//หลอดเลือดผู้เล่น
	float Hpbar = this->Hp / this->Maxhp;
	Hpbulb.setSize(Vector2f(Hpbar * 200.0f, 10.0f));
	Hpbulb.setPosition(Vector2f(50.0f , 25.0f));
	Hpbulb.setScale(Vector2f(2.0, 0.50));
	//หลอดเลือดแต่ซ้อนกันเป็น 2 มิติ
	HpbulbMax.setSize(Vector2f(200.0f, 10.0f));
	HpbulbMax.setPosition(Vector2f(50.0f , 25.0f));
	HpbulbMax.setScale(Vector2f(2.0, 0.50));
}

void Player::draw(RenderWindow& window)
{
	window.draw(spacecraft);
	window.draw(HpbulbMax);
	window.draw(Hpbulb);
}

void Player::setHp(float Hp)
{
	this->Hp += Hp;
	if (this->Hp > this->Maxhp)
	{
		this->Hp = Maxhp;
	}
	//ทำน้อยกว่าเลือดน้อยกว่า 0 ตรงนี้
	if (this->Hp < 0)
	{
		this->Hp = 0;
	}
}

float Player::getMaxhp()
{
	return Maxhp;
}

void Player::setTexture(Texture& texture)
{
	this->spacecraft.setTexture(texture);
}

void Player::setSpeed(int value)
{
	this->speed = value;
}

