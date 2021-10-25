#include "Pawn.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include <vector>
int main()
{
	srand(time_t(static_cast<unsigned>(NULL)));
	RenderWindow window(VideoMode(1920, 1080), "My Game", Style::Close | Style::Titlebar);
	vector < Bullet > bullets;
	vector < Enemy > enemies;
	Background background;

	Texture spaceship;
	spaceship.loadFromFile("textures/Spaceship/mship1.png");
	Player rocket(spaceship, 100);
	
	Texture shot;
	shot.loadFromFile("textures/Bullet/buttet.png");

	Texture enemy[5];
	enemy[0].loadFromFile("textures/Enemy/1.png");
	enemy[1].loadFromFile("textures/Enemy/2.png");
	enemy[2].loadFromFile("textures/Enemy/3.png");
	enemy[3].loadFromFile("textures/Enemy/4.png");
	enemy[4].loadFromFile("textures/Enemy/5.png");

	Font font;
	font.loadFromFile("fonts/Blern regular.ttf");
	Text scoretext;
	scoretext.setFont(font);
	scoretext.setCharacterSize(40);
	scoretext.setPosition(Vector2f(1700.0f , 20.0f));
	scoretext.setFillColor(Color::White);
	int score = 0;
	



	Clock clock;
	int level = 1;
	int type;
	int enemykill = 0;
	float speed = 150.f;
	float showtime = 0.0f;
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
			bullets.push_back(Bullet(&shot, rocket.spacecraft.getPosition(), rocket.spacecraft.getRotation()));
			bullettime = 0.f;
		}
		if (sumtime >= 2.0f)
		{
			//เลเวล
			switch (level)
			{
			case 1:
				type = 1;
				break;

			case 2:
				type = 1;
				break;

			case 3:
				type = 2;
				break;

			case 4:
				type = 2;
				break;

			case 5:
				type = 3;
				break;

			case 6:
				type = 3;
				break;

			case 7:
				type = 4;
				break;

			case 8:
				type = 4;
				break;

			case 9:
				type = 5;
				break;

			case 10:
				type = 5;
				break;

			default :
				type = 10;
				break;
			}
			                                                            //สุ่มให้เกิดทิศทางไหน
			enemies.push_back(Enemy(&enemy[rand() % type], 10 , level, rand() % 3 + 1));
			sumtime = 0.f;
		}
		
		// ↓ Update

		//ทำคะแนน
		cout << score << endl;
		background.update(deltaTime);
		scoretext.setString(" SCORE  " + to_string(score));

		rocket.update(deltaTime);
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].update(deltaTime, rocket.spacecraft.getPosition());
			if (enemies[i].getHp() <= 0)
			{
				//เลเวลเมื่อคิวได้
				enemykill++;
				if (enemykill >= 10)
				{
					enemykill = 0;
					level++;
					rocket.setHp(rocket.getMaxhp());
					cout << level << endl;
				}
				// กำหนดคะแนนแต่ละเลเวล
				switch (level)
				{
				case 1:
					score += 2;
					break;

				case 2:
					score += 2;
					break;

				case 3:
					score += 4;
					break;

				case 4:
					score += 4;
					break;

				case 5:
					score += 6;
					break;

				case 6:
					score += 6;
					break;

				case 7:
					score += 8;
					break;

				case 8:
					score += 8;
					break;
				case 9:
					score += 10;
					break;
				case 10:
					score += 10;
					break;

				default:
					score: 10;
					break;
				}
				enemies.erase(enemies.begin() + i);

				break;
			}
			for (size_t j = 0; j < bullets.size(); j++)
			{
				if (enemies[i].getGlobalBounds().intersects(bullets[j].getGlobalBounds()))
				{
					enemies[i].setHp(2); //ความเเรงกระสุน
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
		
		window.draw(scoretext);

		window.display();
		
	}
	return 0;
}