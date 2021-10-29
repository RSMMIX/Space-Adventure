#include "Meteorite.h"
Meteorite::Meteorite(Texture* meteorite_texture)
{
    this->metorite_sprite.setTexture(*meteorite_texture);
    this->metorite_sprite.setPosition(sf::Vector2f(rand() % 1920,0.f));
    this->speed = 300.f;
	this->metoriteDamage = 50;
}

void Meteorite::update(float deltaTime)
{
    this->metorite_sprite.move(sf::Vector2f(speed*deltaTime,0.f));
}

void Meteorite::draw(RenderWindow& window)
{
    window.draw(this->metorite_sprite);
}

float Meteorite::getdamage()
{
    return this->metoriteDamage;
}
