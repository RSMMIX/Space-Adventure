#pragma once
#include "Library.h"

class Meteorite
{
public:
    Meteorite(Texture* meteorite_texture);
    void update(float deltaTime);
	void draw(RenderWindow& window);
	float getdamage();
    FloatRect getGlobalBounds() 
	{ 
		return metorite_sprite.getGlobalBounds(); 
	}
	Vector2f getPosition()
	{
		return metorite_sprite.getPosition();
	}

private:
	Sprite metorite_sprite;
	float speed;
	float metoriteDamage;
};

