#include "Background.h"

Background::Background()
{
	background_1.loadFromFile("textures/Bg/bg1.jpg");

	background_2.loadFromFile("textures/Bg/bg2.jpg");

	background1.setTexture(background_1);
	background2.setTexture(background_2);


	background1.setScale(1.35f, 1.35f);

	deltaTime - deltaTime;

	backgrounds.push_back(background1);
	backgrounds.push_back(background2);

}

Background::~Background()
{
}

void Background::update(float deltaTime)
{
	//background scrolling
	for (size_t i = 0; i < backgrounds.size(); i++)
	{
		if (i > 0) backgrounds[i].setPosition(0.f, backgrounds[i - 1].getPosition().y - backgrounds[i].getGlobalBounds().height);
		position = backgrounds[i].getPosition();
		backgrounds[i].setPosition(0.f,position.y += (deltaTime * 100.f));
		if (position.y > 1040.f)
		{
			backgrounds.push_back(background2);
			backgrounds.erase(backgrounds.begin() + i);
			break;
		}
	}
}

void Background::draw(RenderWindow& window)
{
	for (size_t i = 0; i < backgrounds.size(); i++)
	{
		window.draw(backgrounds[i]);
	}
}
