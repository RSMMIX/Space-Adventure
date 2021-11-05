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

private:
	Sprite metorite_sprite;
	float speed;
	float metoriteDamage;
};

