#pragma once
#include "Library.h"
class Background
{
public:

	Background();
	~Background();

	void update(float deltaTime);
	void draw(RenderWindow& window);
private:
	RenderWindow* window;

	Sprite background1;
	Sprite background2;

	Texture  background_1;
	Texture  background_2;


	float deltaTime;

	vector<Sprite> backgrounds;
	Vector2f position;

};