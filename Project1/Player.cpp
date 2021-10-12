#include "Player.h"


Player::Player(Texture &spaceship)
{
	spacecraft.setTexture(spaceship);
	spacecraft.setPosition(Vector2f(960, 840));
	spacecraft.setOrigin(800.f, 800.f);
	spacecraft.setScale(Vector2f(0.05, 0.05));
	spacecraft.rotate(0);
	momentum = 200.0f;
	speed = 200.0f;
}

Player::~Player()
{
}

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
}

void Player::draw(RenderWindow& window)
{
	window.draw(spacecraft);
}

