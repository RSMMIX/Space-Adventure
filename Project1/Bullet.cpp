#include "Bullet.h"

Bullet::Bullet(Texture* spaceship, Vector2f position, float degree)
{
	spacecraft.setTexture(spaceship);
	spacecraft.setSize(Vector2f(10.0f, 10.0f));
	spacecraft.setOrigin(5.0f, 5.0f);
	spacecraft.setPosition(position);
	spacecraft.setRotation(degree);
	direction = rotateVector(Vector2f(0, -1), spacecraft.getRotation());
	momentum = 200.0f;
	speed = 400.0f;

	spacecraft.move(direction  * 25.f);
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	direction = rotateVector(Vector2f(0,-1), spacecraft.getRotation());
	spacecraft.move(direction * deltaTime * speed);
	spacecraft.getPosition();
}

void Bullet::draw(RenderWindow& window)
{
	window.draw(spacecraft);
}
