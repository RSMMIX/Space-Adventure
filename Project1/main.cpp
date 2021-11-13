#include "Library.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include "Item.h"
#include "Meteorite.h"
#include "Menu.h"
#include <vector>
int main()
{
	srand(time_t(static_cast<unsigned>(NULL)));
	RenderWindow window(VideoMode(1920, 1080), "My Game", Style::Fullscreen | Style::Titlebar);
	Menu menu(&window);
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

	Texture enemy[7];
	enemy[0].loadFromFile("textures/Enemy/1.png");
	enemy[1].loadFromFile("textures/Enemy/2.png");
	enemy[2].loadFromFile("textures/Enemy/3.png");
	enemy[3].loadFromFile("textures/Enemy/4.png");
	enemy[4].loadFromFile("textures/Enemy/5.png");
	enemy[5].loadFromFile("textures/Enemy/7.png");
	enemy[6].loadFromFile("textures/Enemy/8.png");

	Texture meteorite;
	meteorite.loadFromFile("textures/Enemy/6.png");

	Texture itemstexture[4];
	itemstexture[0].loadFromFile("textures/Item/t1.png"); //ซ้อมยาน
	itemstexture[1].loadFromFile("textures/Item/t2.png"); //โล่
	itemstexture[2].loadFromFile("textures/Item/t3.png"); //ยิงกระสุนแบบอมตะ
	itemstexture[3].loadFromFile("textures/Item/t4.png"); //เพิ่มความเร็วยาน

	Texture shieldFx;
	shieldFx.loadFromFile("textures/Fx/Fx2.png");

	//Texture symbol;
	//symbol.loadFromFile("textures/Fx/Fx3.png");
	
	//ฟอนต์score
	Font font;
	font.loadFromFile("fonts/Blern regular.ttf");
	Text scoretext;
	//score
	scoretext.setFont(font);
	scoretext.setCharacterSize(30);
	scoretext.setPosition(Vector2f(1740.0f , 20.0f));
	scoretext.setFillColor(Color::White);
	int score = 0;

	//textlevel
	Text Lvl;
	Lvl.setFont(font);
	Lvl.setCharacterSize(15);
	Lvl.setPosition(Vector2f(20.0f, 40.0f));
	Lvl.setFillColor(Color::White);

	//Hp
	Text Hp;
	Hp.setFont(font);
	Hp.setCharacterSize(15);
	Hp.setPosition(Vector2f(20.0f, 20.0f));
	Hp.setFillColor(Color::White);
	

	Text scorebullet;
	//scorebullet
	scorebullet.setFont(font);
	scorebullet.setCharacterSize(15);
	scorebullet.setPosition(Vector2f(45.0f, 55.0f));
	scorebullet.setFillColor(Color::White);
	


	//หลอดเลเวล
	RectangleShape Lvbulb;
	RectangleShape LvbulbMax;
	Lvbulb.setFillColor(Color(0, 204, 204));
	LvbulbMax.setFillColor(Color(0, 102, 204));

	
	
	Clock clock;
	int level = 1;
	int requireToKill = 5;
	int type;
	int enemykill = 0;
	int maxMeteorite = 0;
	int Maxbulletammo =  100; //จำนวนกรสุน
	int bulletammo = Maxbulletammo;


	float speed = 150.f;
	float showtime = 0.0f;
	float deltaTime = 0;
	float sumtime = 0;
	float bullettime = 0;

	bool stopSpawn = 1;
	float stopSpawnDelay = 0.0f;
	
	//Invincible
	bool isShield = 0;
	float shieldDuration = 0.0f;
	float shieldDurationMax = 5.f;

	int extraLife = 0;

	//Speed Up
	bool isSpeed = 0; 
	float speedupDuration = 0.f;
	float speedupDurationMax = 10.f;

	int action = 0;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
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

		action = menu.getMenuState();
		switch(action)
		{
		case 0://Menu
			menu.updateMenu();
			menu.renderMenu();
			break;
		case 5:
			window.close();
			break;
		case 2://Play 
			sumtime += deltaTime;
			showtime += deltaTime;
			bullettime += deltaTime;
			
			if (Keyboard::isKeyPressed(Keyboard::Space) && bullettime >= 0.1f &&  bulletammo > 0)
			{
				bullets.push_back(Bullet(&shot, rocket.spacecraft.getPosition(), rocket.spacecraft.getRotation()));
				bulletammo--;
				bullettime = 0.0f;
			}
			if (sumtime >= 2.0f && !stopSpawn)
			{
				//เลเวล
				switch (level)
				{
				case 1:
					type = 1;
					requireToKill = 5;
					maxMeteorite = 0;
					break;

				case 2:
					type = 2;
					requireToKill = 7;
					maxMeteorite = 1;
					break;

				case 3:
					type = 2;
					requireToKill = 9;
					maxMeteorite = 4;
					break;

				case 4:
					type = 3;
					requireToKill = 11;
					maxMeteorite = 5;
					break;

				case 5:
					type = 3;
					requireToKill = 15;
					maxMeteorite = 6;
					break;

				case 6:
					type = 4;
					requireToKill = 19;
					maxMeteorite = 7;
					break;

				case 7:
					type = 5;
					requireToKill = 21;
					maxMeteorite = 8;
					break;

				case 8:
					type = 6;
					requireToKill = 25;
					maxMeteorite = 9;
					break;

				case 9:
					type = 7;
					requireToKill = 31;
					maxMeteorite = 10;
					break;

				case 10:
					type = 7;
					requireToKill = 41;
					maxMeteorite = 11;
					break;

				default :
					type = 7;
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
			Lvbulb.setPosition(Vector2f(50.0f , 45.0f));
			Lvbulb.setScale(Vector2f(2.0, 0.50));
			LvbulbMax.setSize(Vector2f(200.0f, 10.0f));
			LvbulbMax.setPosition(Vector2f(50.0f , 45.0f));
			LvbulbMax.setScale(Vector2f(2.0, 0.50));
			//ทำคะแนน
			cout << score << endl;
			background.update(deltaTime);
			scoretext.setString(" SCORE  " + to_string(score));

			//ทำตัวเลขกระสุน
			scorebullet.setString(" AMMO  " + to_string(bulletammo));

			//ทำตัวเลือด
			Hp.setString("Hp");

			//Level
			Lvl .setString("Lvl");
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
						//Maxbulletammo += 15; //เพิ่มกระสุนแต่ละเวล
						bulletammo = Maxbulletammo;
						cout << level << endl;
					}
					// กำหนดคะแนนแต่ละเลเวล
					switch (level)
					{
					case 1:
						score += 10;
						Maxbulletammo += 10;
						break;

					case 2:
						score += 10;
						Maxbulletammo += 15;
						break;

					case 3:
						score += 15;
						Maxbulletammo += 20;
						break;

					case 4:
						score += 15;
						Maxbulletammo += 25;
						break;

					case 5:
						score += 25;
						Maxbulletammo += 30;
						break;

					case 6:
						score += 25;
						Maxbulletammo += 35;
						break;

					case 7:
						score += 35;
						Maxbulletammo += 40;
						break;

					case 8:
						score += 35;
						Maxbulletammo += 45;
						break;
					case 9:
						score += 70;
						Maxbulletammo += 50;
						break;
					case 10:
						score += 70;
						Maxbulletammo += 55;
						break;

					default:
						score: 10;
						break;
					}
					//Spawn Item     
					int rand_item = rand() % 50;
					if(rand_item >= 0 && rand_item <= 50)          //สุ่ม 4แบบ
						items.push_back(Item(&itemstexture[rand() % 4], enemies[i].getPosition(), rand() % 4));
					enemies.erase(enemies.begin() + i);
					break;
				}

				for (size_t j = 0; j < bullets.size(); j++)
				{
					if (enemies[i].getGlobalBounds().intersects(bullets[j].getGlobalBounds()))
					{
						enemies[i].setHp(3); //ความเเรงกระสุนลดเลือดศัตรู
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
					if(!isShield)
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
			for(size_t i = 0; i < meteorites.size(); i++)
			{
				meteorites[i].update(deltaTime);
				if (meteorites[i].getGlobalBounds().intersects(rocket.spacecraft.getGlobalBounds()))
				{
					if(!isShield)
						rocket.setHp(-meteorites[i].getdamage());
					meteorites.erase(meteorites.begin() + i);
					break;
				}
			}

			//Update Item
			for(size_t i = 0; i < items.size(); i++)
			{
				items[i].updateItem(deltaTime);
				if (items[i].getGlobalBounds().intersects(rocket.spacecraft.getGlobalBounds()))
				{
					switch(items[i].getItem())
					{
					case 0:
						rocket.setHp(100);//set เลือด
						break;
					case 1:
						isShield = 1;
						break;
					case 2:
						extraLife++;
						break;
					case 3:
						isSpeed = 1;
						break;
					default:
						break;
					}
					items.erase(items.begin() + i);
					break;
				}
				if(items[i].getItemTime() > 10.f)
				{
					items.erase(items.begin() + i);
					break;
				}
			}
			
			//Update Stop Spawn Time
			if(stopSpawn)
			{
				if(stopSpawnDelay < 5.0f)
					stopSpawnDelay += deltaTime;
				else
				{
					stopSpawn = 0;
					stopSpawnDelay = 0.f;
				}
			}
			//ทำโล่
			if(isShield)
			{
				rocket.setTexture(shieldFx);

				if(shieldDuration < shieldDurationMax)
					shieldDuration += deltaTime;
				else
				{
					isShield = 0;
					rocket.setTexture(spaceship);
					shieldDuration = 0.f;
				}
			}
			
			//Speed Up
			if(isSpeed)
			{
				rocket.setSpeed(1000.f);
				if(speedupDuration < speedupDurationMax)
					speedupDuration += deltaTime;
				else
				{
					isSpeed = 0;
					speedupDuration = 0.f;
				}
			}
			else
				rocket.setSpeed(200.f);

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

			for (Meteorite& Fmeteorites : meteorites)
			{
				Fmeteorites.draw(window);
			}

			for (Item& Fitems: items)
			{
				Fitems.renderItem(window);
			}

			rocket.draw(window);


			window.draw(scoretext);
			window.draw(scorebullet);
			window.draw(Hp);
			window.draw(Lvl);

			window.draw(LvbulbMax);
			window.draw(Lvbulb);

			window.display();
			break;
			
		}
		
	}
	return 0;
}