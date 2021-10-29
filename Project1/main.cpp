﻿#include "Library.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include "Item.h"
#include "Meteorite.h"
#include <vector>
int main()
{
	srand(time_t(static_cast<unsigned>(NULL)));
	RenderWindow window(VideoMode(1920, 1080), "My Game", Style::Close | Style::Titlebar);
	vector < Bullet > bullets;
	vector < Enemy > enemies;
	vector < Item > items;
	vector < Meteorite > meteorites;
	Background background;

	Texture spaceship;
	spaceship.loadFromFile("textures/Spaceship/mship1.png");
	Player rocket(spaceship, 100);
	
	Texture shot;
	shot.loadFromFile("textures/Bullet/buttet.png");

	Texture enemy[6];
	enemy[0].loadFromFile("textures/Enemy/1.png");
	enemy[1].loadFromFile("textures/Enemy/2.png");
	enemy[2].loadFromFile("textures/Enemy/3.png");
	enemy[3].loadFromFile("textures/Enemy/4.png");
	enemy[4].loadFromFile("textures/Enemy/5.png");


	Texture meteorite;
	meteorite.loadFromFile("textures/Enemy/6.png");
	vector<RectangleShape> meteorites;

	Texture itemstexture[4];
	itemstexture[0].loadFromFile("textures/Item/t1.png"); //ซ้อมยาน
	itemstexture[1].loadFromFile("textures/Item/t2.png"); //โล่
	itemstexture[2].loadFromFile("textures/Item/t3.png"); //เพิ่มชีวิตยาน(อะไรยาน?)
	itemstexture[3].loadFromFile("textures/Item/gold-coin.png"); //เหรียญ

	//ฟอนต์
	Font font;
	font.loadFromFile("fonts/Blern regular.ttf");
	Text scoretext;
	scoretext.setFont(font);
	scoretext.setCharacterSize(40);
	scoretext.setPosition(Vector2f(1700.0f , 20.0f));
	scoretext.setFillColor(Color::White);
	int score = 0;

	//หลอดเลเวล
	RectangleShape Lvbulb;
	RectangleShape LvbulbMax;
	Lvbulb.setFillColor(Color(0, 255, 101));
	LvbulbMax.setFillColor(Color(0, 101, 11));

	
	
	Clock clock;
	int level = 1;
	int requireToKill = 5;
	int type;
	int enemykill = 0;
	int maxMeteorite = 0;
	float speed = 150.f;
	float showtime = 0.0f;
	float deltaTime = 0;
	float sumtime = 0;
	float bullettime = 0;

	bool stopSpawn = 1;
	float stopSpawnDelay = 0.0f;
	
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
		if (sumtime >= 2.0f && !stopSpawn)
		{
			//เลเวล
			switch (level)
			{
			case 1:
				type = 1;
				requireToKill = 3;
				maxMeteorite = 0;
				break;

			case 2:
				type = 1;
				
				requireToKill = 5;
				maxMeteorite = 1;
				break;

			case 3:
				type = 2;
				requireToKill = 7;
				maxMeteorite = 1;
				break;

			case 4:
				type = 2;
				requireToKill = 9;
				maxMeteorite = 2;
				break;

			case 5:
				type = 3;
				requireToKill = 11;
				maxMeteorite = 2;
				break;

			case 6:
				type = 3;
				requireToKill = 13;
				maxMeteorite = 3;
				break;

			case 7:
				type = 4;
				requireToKill = 15;
				maxMeteorite = 4;
				break;

			case 8:
				type = 4;
				requireToKill = 17;
				maxMeteorite = 4;
				break;

			case 9:
				type = 5;
				requireToKill = 19;
				maxMeteorite = 5;
				break;

			case 10:
				type = 5;
				requireToKill = 25;
				maxMeteorite = 5;
				break;

			default :
				type = 10;
				break;
			}
			                                                            //สุ่มให้เกิดทิศทางไหน
			enemies.push_back(Enemy(&enemy[rand() % type], 10 , level, rand() % 3 + 1));
			sumtime = 0.f;
		}
		//Spawn Meteorite
		if(meteorites.size() < maxMeteorite)
		{
			meteorites.push_back(Meteorite(&meteorite));
		}
		
		// ↓ Update
		
		//หลอด lv ผู้เล่น
		float LvBar = (float)enemykill / requireToKill;
		Lvbulb.setSize(Vector2f(LvBar * 200.0f, 10.0f));
		Lvbulb.setPosition(Vector2f(70.0f , 30.0f));
		Lvbulb.setScale(Vector2f(2.0, 1.0));
		LvbulbMax.setSize(Vector2f(200.0f, 10.0f));
		LvbulbMax.setPosition(Vector2f(70.0f , 30.0f));
		LvbulbMax.setScale(Vector2f(2.0, 1.0));
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
				if (enemykill >= requireToKill)
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
					score += 10;
					break;

				case 2:
					score += 10;
					break;

				case 3:
					score += 15;
					break;

				case 4:
					score += 15;
					break;

				case 5:
					score += 25;
					break;

				case 6:
					score += 25;
					break;

				case 7:
					score += 35;
					break;

				case 8:
					score += 35;
					break;
				case 9:
					score += 70;
					break;
				case 10:
					score += 70;
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
					enemies[i].setHp(2); //ความเเรงกระสุนลดเลือดศัตรู
					bullets.erase(bullets.begin() + j);
					break;
				}
				if (bullets[j].spacecraft.getPosition().x < 0 || bullets[j].spacecraft.getPosition().x > 1920 || bullets[j].spacecraft.getPosition().y < 0 || bullets[j].spacecraft.getPosition().y > 1080)
				{
					bullets.erase(bullets.begin() + j);
				}
			}
			
			//ลดเลือดเราเวลาศัตรูชน	
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
		//Update Meteorite
		//It's supposed to be OK!
		for(size_t i = 0 ;i < meteorites.size(); i++)
		{
			if (meteorite[i].metorite_sprite.getGlobalBounds())
			{
				rocket.setHp(-meteorites[i].getdamage());
				meteorite.erase(meteorites.begin() + i);
				break;
			}
		}
		
		//Update Stop Spawn Time
		if(stopSpawn)
		{
			if(stopSpawnDelay < 10.f)
				stopSpawnDelay += deltaTime;
			else
			{
				stopSpawn = 0;
				stopSpawnDelay = 0.f;
			}
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
		window.draw(meteorites);

		rocket.draw(window);
		
		window.draw(scoretext);

		window.draw(LvbulbMax);
		window.draw(Lvbulb);

		window.display();
		
	}
	return 0;
}