﻿#include "Pawn.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include <vector>
int main()
{
	srand(time_t(static_cast<unsigned>(0)));
	RenderWindow window(VideoMode(1920, 1080), "My Game", Style::Close | Style::Titlebar);
	vector < Bullet > ammunition;
	vector < Enemy > enemies;
	Background background;

	Texture spaceship;
	spaceship.loadFromFile("textures/Spaceship/mship1.png");
	Player rocket(spaceship);
	
	Texture shot;
	shot.loadFromFile("textures/Bullet/buttet.png");

	Texture enemy;
	enemy.loadFromFile("textures/Enemy/enemies.png");
	
	float speed = 150.f;
	float showtime = 0.0f;
	Clock clock;
	float deltaTime = 0;
	float sumtime = 0;
	float bullettime = 0;
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sumtime += deltaTime;
		showtime += deltaTime;
		bullettime += deltaTime;
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
			{
				switch (ev.type)
				{
				case Event::Closed:
					window.close();
					break;
				}
			}
		}
	
		if (Keyboard::isKeyPressed(Keyboard::Space) && bullettime >= 0.1f)
		{
			bullettime -= 0.1f;
			ammunition.push_back(Bullet(&shot, rocket.spacecraft.getPosition(), rocket.spacecraft.getRotation()));
		}
		if (sumtime >= 5.0f && showtime >= 12.0f)
		{
			sumtime -= 5.0f;
			enemies.push_back(Enemy(&enemy));
		}
		

		// ↓ Update
		background.update(deltaTime);
		if (showtime >= 12.0f)
		{
			rocket.update(deltaTime);
		}

		for (Bullet& Fbullet : ammunition)
		{
			Fbullet.update(deltaTime);
		}

		for (Enemy& Fenemy : enemies)
		{
			Fenemy.update(deltaTime,rocket.spacecraft.getPosition());
		}

		window.clear();
		//window.draw(background);
		

		// ↓ Draw
		background.draw(window);

		for (Bullet& Fbullet: ammunition)
		{
			Fbullet.draw(window);
		}

		for (Enemy& Fenemy :enemies)
		{
			Fenemy.draw(window);
		}

		rocket.draw(window);

		window.display();
	}
	return 0;
}