#include "Meteorite.h"
Meteorite::Meteorite(Texture* meteorite_texture)
{
    metorite_sprite.setTexture(*meteorite_texture);
    metorite_sprite.setPosition(sf::Vector2f(rand() % 1920,0.f));
    metorite_sprite.setScale(Vector2f(0.6f ,0.7f));
    speed = 300.f;
	metoriteDamage = 50;
}

void Meteorite::update(float deltaTime)
{
    metorite_sprite.move(sf::Vector2f(0.f,speed*deltaTime));
}

void Meteorite::draw(RenderWindow& window)
{
    window.draw(metorite_sprite);
}

float Meteorite::getdamage()
{
    return metoriteDamage;
}
