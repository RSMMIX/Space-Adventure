#pragma once
#include "Library.h"

class Meteorite
{
public:
    Meteorite(Texture* meteorite_texture);
    void update(float deltaTime);
	void draw(RenderWindow& window);
	float getdamage();
    
    Sprite metorite_sprite;

private:
	float speed;
	float metoriteDamage;
};

