#include "Pawn.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include <vector>
int main()
{
	srand(time_t(static_cast<unsigned>(0)));
	RenderWindow window(VideoMode(1920, 1080), "My Game", Style::Close | Style::Titlebar);
	vector < Bullet > bullets;
	vector < Enemy > enemies;
	Background background;

	Texture spaceship;
	spaceship.loadFromFile("textures/Spaceship/mship1.png");
	Player rocket(spaceship, 100);
	
	Texture shot;
	shot.loadFromFile("textures/Bullet/buttet.png");

	Texture enemy[3];
	enemy[0].loadFromFile("textures/Enemy/e1.png");
	enemy[1].loadFromFile("textures/Enemy/e2.png");
	enemy[2].loadFromFile("textures/Enemy/e3.png");

	float speed = 150.f;
	float showtime = 0.0f;
	Clock clock;
	float deltaTime = 0;
	float sumtime = 0;
	float bullettime = 0;
	int level = 1;
	int type;
	int enemykill = 0;
	
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
			bullets.push_back(Bullet(&shot, rocket.spacecraft.getPosition(), rocket.spacecraft.getRotation()));
			bullettime = 0.f;
		}
		if (sumtime >= 2.0f)
		{
			switch (level)
			{
			case 1:
				type = 1;
				break;

			case 2:
				type = 2;
				break;

			case 3:
				type = 3;
				break;
			default :
				type = 3;
				break;
			}
			enemies.push_back(Enemy(&enemy[rand() % type], 10 , level));
			sumtime = 0.f;
		}
		
		// ↓ Update
		background.update(deltaTime);

		rocket.update(deltaTime);
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].update(deltaTime, rocket.spacecraft.getPosition());
			if (enemies[i].getHp() <= 0)
			{
				enemykill++;
				if (enemykill >= 10)
				{
					enemykill = 0;
					level++;
					rocket.setHp(rocket.getMaxhp());
					cout << level << endl;
				}
				enemies.erase(enemies.begin() + i);
				break;
			}
			for (size_t j = 0; j < bullets.size(); j++)
			{
				if (enemies[i].getGlobalBounds().intersects(bullets[j].getGlobalBounds()))
				{
					enemies[i].setHp(2);
					bullets.erase(bullets.begin() + j);
					break;
				}
			}
			if (enemies[i].getGlobalBounds().intersects(rocket.spacecraft.getGlobalBounds()))
			{
				rocket.setHp(-enemies[i].getdamage());
				enemies.erase(enemies.begin() + i);
				break;
			}
		}
		for (Bullet& Fbullet : bullets)
		{
			Fbullet.update(deltaTime);
		}
		window.clear();
		
		// ↓ Draw
		background.draw(window);

		for (Bullet& Fbullet: bullets)
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