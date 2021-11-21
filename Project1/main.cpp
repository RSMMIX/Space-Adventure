#include "Library.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include "Item.h"
#include "Meteorite.h"
#include "Menu.h"
#include <vector>

ScoreData scoreData[6];

int main()
{
	srand(time_t(static_cast<unsigned>(NULL)));
	RenderWindow window(VideoMode(1920, 1080), "Adventure Shooting Dragons In Space", Style::Fullscreen | Style::Titlebar);
	readScoreFile();
	Menu menu(&window);
	vector<Bullet> bullets;
	vector<Enemy> enemies;
	vector<Item> items;
	vector<Meteorite> meteorites;
	Background background;

	Texture spaceship;
	spaceship.loadFromFile("textures/Spaceship/mship1.png");
	Player* rocket = new Player(spaceship, 100);

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

	Texture itemstexture[5];
	itemstexture[0].loadFromFile("textures/Item/t1.png"); //ซ้อมยาน
	itemstexture[1].loadFromFile("textures/Item/t2.png"); //โล่
	itemstexture[2].loadFromFile("textures/Item/t3.png"); //เพิมกระสุน
	itemstexture[3].loadFromFile("textures/Item/t4.png"); //เพิ่มความเร็วยาน
	itemstexture[4].loadFromFile("textures/Item/t5.png");

	Texture shieldFx;
	shieldFx.loadFromFile("textures/Fx/Fx2.png");

	Font font;
	font.loadFromFile("fonts/Blern regular.ttf");

	//Player Name //set***
	string player_name;
	Text name_text;
	name_text.setFont(font);
	name_text.setCharacterSize(30);
	name_text.setPosition(Vector2f(70.0f, 38.0f));
	name_text.setFillColor(Color::White);
	//กรอบข้อความชื่อ
	Texture framena_texture;
	Sprite framena_button;
	framena_texture.loadFromFile("textures/Button/button.png");
	framena_button.setTexture(framena_texture);
	framena_button.setPosition(Vector2f(35, 20));
	framena_button.setScale(Vector2f(1.f, 0.7f));

	//ฟอนต์score
	Text scoretext;
	//score
	scoretext.setFont(font);
	scoretext.setCharacterSize(30);
	scoretext.setPosition(Vector2f(1700.0f, 37.0f));
	scoretext.setFillColor(Color::White);
	int score = 0;

	//กรอบข้อความ
	Texture frame_texture;
	Sprite frame_button;
	frame_texture.loadFromFile("textures/Button/button.png");
	frame_button.setTexture(frame_texture);
	frame_button.setPosition(Vector2f(1660, 20));
	frame_button.setScale(Vector2f(1.0f, 0.7f));

	//textlevel
	Text Lvl;
	Lvl.setFont(font);
	Lvl.setCharacterSize(15);
	Lvl.setPosition(Vector2f(20.0f, 105.0f));
	Lvl.setFillColor(Color::White);

	//Hp
	Text Hp;
	Hp.setFont(font);
	Hp.setCharacterSize(15);
	Hp.setPosition(Vector2f(20.0f, 85.0f));
	Hp.setFillColor(Color::White);

	Text scorebullet;
	//scorebullet
	scorebullet.setFont(font);
	scorebullet.setCharacterSize(15);
	scorebullet.setPosition(Vector2f(55.0f, 125.0f));
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
	int Maxbulletammo = 100; //จำนวนกรสุน
	int bulletammo = Maxbulletammo;

	bool upgrade = false;
	int upgradetime = 0;

	float speed = 0.f;
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
		switch (action)
		{
		case 0://Menu
			menu.updateMenu();
			menu.renderMenu();
			break;

		case 1://Name
			menu.updateName();
			menu.updateNameInput(ev);
			menu.renderName();
			name_text.setOrigin(Vector2f(name_text.getGlobalBounds().width, name_text.getGlobalBounds().height) / 2.f);
			name_text.setPosition(Vector2f(165.0f, 48.0f));
			name_text.setString(menu.getName());
			break;

		case 7://face pauseport
			menu.updatePause();
			menu.renderPause();
			
			break;
		case 3:
			menu.updateleaderboards();
			menu.renderleaderboards();
			break;
		case 4://How to play
			menu.updateHow();
			menu.renderHow();
			break;

		case 5:
			window.close();
			break;
		case 6://Game over
			menu.updateGameOver();
			menu.renderGameOver();

			break;
	   
		case 2://Play 
			sumtime += deltaTime;
			showtime += deltaTime;
			bullettime += deltaTime;

			menu.checktriggerPause();

			if (Keyboard::isKeyPressed(Keyboard::Space) && bullettime >= 0.1f && bulletammo > 0)
			{
				if (upgrade == true && upgradetime > 0)
				{
					bullets.push_back(Bullet(&shot, rocket->spacecraft.getPosition(), rocket->spacecraft.getRotation() - 5));
					bullets.push_back(Bullet(&shot, rocket->spacecraft.getPosition(), rocket->spacecraft.getRotation()));
					bullets.push_back(Bullet(&shot, rocket->spacecraft.getPosition(), rocket->spacecraft.getRotation() + 5));
				}
				else
				{
					bullets.push_back(Bullet(&shot, rocket->spacecraft.getPosition(), rocket->spacecraft.getRotation()));
				}

				if (upgrade == true && upgradetime > 0)
				{
					bulletammo -= 3;
				}
				else
				{
					bulletammo--;
				}
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
					maxMeteorite = 2;
					break;

				case 3:
					type = 2;
					requireToKill = 9;
					maxMeteorite = 3;
					break;

				case 4:
					type = 3;
					requireToKill = 11;
					maxMeteorite = 3;
					break;

				case 5:
					type = 3;
					requireToKill = 15;
					maxMeteorite = 4;
					break;

				case 6:
					type = 4;
					requireToKill = 19;
					maxMeteorite = 4;
					break;

				case 7:
					type = 5;
					requireToKill = 21;
					maxMeteorite = 5;
					break;

				case 8:
					type = 6;
					requireToKill = 25;
					maxMeteorite = 5;
					break;

				case 9:
					type = 7;
					requireToKill = 31;
					maxMeteorite = 6;
					break;

				case 10:
					type = 7;
					requireToKill = 41;
					maxMeteorite = 6;
					break;

				default:
					type = 7;
					break;
				}
				//สุ่มให้เกิดทิศทางไหน
				enemies.push_back(Enemy(&enemy[rand() % type], 10, level, rand() % 3 + 1));
				sumtime = 0.f;
			}
			//Spawn Meteorite
			if (meteorites.size() < maxMeteorite)
			{
				meteorites.push_back(Meteorite(&meteorite));
			}

			// ↓ Update

			//หลอด lv ผู้เล่น
			float LvBar = (float)enemykill / requireToKill;
			Lvbulb.setSize(Vector2f(LvBar * 200.0f, 10.0f));
			Lvbulb.setPosition(Vector2f(60.0f, 112.0f));
			Lvbulb.setScale(Vector2f(2.0, 0.50));
			LvbulbMax.setSize(Vector2f(200.0f, 10.0f));
			LvbulbMax.setPosition(Vector2f(60.0f, 112.0f));
			LvbulbMax.setScale(Vector2f(2.0, 0.50));

			//ทำคะแนน
			background.update(deltaTime);
			scoretext.setString(" SCORE  " + to_string(score));

			//ทำตัวเลขกระสุน
			scorebullet.setString(" AMMO  " + to_string(bulletammo));

			//ทำตัวเลือด
			Hp.setString("Hp");

			//Level
			Lvl.setString("Lvl " + to_string(level));
			rocket->update(deltaTime);
			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies[i].update(deltaTime, rocket->spacecraft.getPosition());
				if (enemies[i].getHp() <= 0)
				{
					//เลเวลเมื่อคิวได้
					enemykill++;
					if (enemykill >= requireToKill)
					{
						enemykill = 0;
						level++;
						rocket->setHp(20);
						bulletammo = Maxbulletammo;
					}
					// กำหนดคะแนนแต่ละเลเวล
					switch (level)
					{
					case 1:
						score += 30;
						break;

					case 2:
						score += 40;
						Maxbulletammo += 20;
						break;

					case 3:
						score += 65;
						Maxbulletammo += 20;
						break;

					case 4:
						score += 75;
						Maxbulletammo += 20;
						break;

					case 5:
						score += 85;
						Maxbulletammo += 20;
						break;

					case 6:
						score += 95;
						Maxbulletammo += 20;
						break;

					case 7:
						score += 115;
						Maxbulletammo += 20;
						break;

					case 8:
						score += 125;
						Maxbulletammo += 20;
						break;
					case 9:
						score += 150;
						Maxbulletammo += 20;
						break;
					case 10:
						score += 180;
						Maxbulletammo += 20;
						break;

					default:
					score: 10;
						break;
					}

					//Spawn Item
					int rand_item = rand() % 300;
					if (rand_item >= 0 && rand_item < 50) //สุ่ม 4แบบ
					{
						int r = rand() % 5; // สุ่มแล้วเก็บเข้าตัวแปรเพราะใช้หลายครั้ง
						items.push_back(Item(&itemstexture[r], enemies[i].getPosition(), r));
					}

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
				if (enemies[i].getGlobalBounds().intersects(rocket->spacecraft.getGlobalBounds()))
				{
					if (!isShield)
						rocket->setHp(-enemies[i].getdamage());
					enemies.erase(enemies.begin() + i);
					break;
				}

			}

			for (Bullet& Fbullet : bullets)
			{
				Fbullet.update(deltaTime);
			}
			//Update Meteorite
			for (size_t i = 0; i < meteorites.size(); i++)
			{
				meteorites[i].update(deltaTime);
				if (meteorites[i].getGlobalBounds().intersects(rocket->spacecraft.getGlobalBounds()))
				{
					if (!isShield)
						rocket->setHp(-meteorites[i].getdamage());
					meteorites.erase(meteorites.begin() + i);
					break;
				}
				if (meteorites[i].getPosition().y > window.getSize().y)
				{
					meteorites.erase(meteorites.begin() + i);
					break;
				}
			}

			//Update Item
			for (size_t i = 0; i < items.size(); i++)
			{
				items[i].updateItem(deltaTime);
				if (items[i].getGlobalBounds().intersects(rocket->spacecraft.getGlobalBounds()))
				{
					switch (items[i].getItem())
					{
					case 0:
						rocket->setHp(20);//set เลือด
						break;
					case 1:
						isShield = 1;
						break;
					case 2:
						bulletammo += 50;
						break;
					case 3:
						isSpeed = 1;
						break;
					case 4:
						upgrade = true;
						upgradetime = 1200;
						break;
					default:
						break;
					}
					items.erase(items.begin() + i);
					break;
				}
				if (items[i].getItemTime() > 10.f)
				{
					items.erase(items.begin() + i);
					break;
				}
			}
			upgradetime--;
			//Update Stop Spawn Time
			if (stopSpawn)
			{
				if (stopSpawnDelay < 3.5f)
					stopSpawnDelay += deltaTime;
				else
				{
					stopSpawn = 0;
					stopSpawnDelay = 0.f;
				}
			}
			//ทำโล่
			if (isShield)
			{
				rocket->setTexture(shieldFx);

				if (shieldDuration < shieldDurationMax)
					shieldDuration += deltaTime;
				else
				{
					isShield = 0;
					rocket->setTexture(spaceship);
					shieldDuration = 0.f;
				}
			}

			//Speed Up
			if (isSpeed)
			{
				rocket->setSpeed(600.f);
				if (speedupDuration < speedupDurationMax)
					speedupDuration += deltaTime;
				else
				{
					isSpeed = 0;
					speedupDuration = 0.f;
				}
			}
			else
				rocket->setSpeed(300.f); 

			window.clear();

			// ↓ Draw
			background.draw(window);

			for (Bullet& Fbullet : bullets)
			{
				Fbullet.draw(window);
			}

			for (Enemy& Fenemy : enemies)
			{
				Fenemy.draw(window);
			}

			for (Meteorite& Fmeteorites : meteorites)
			{
				Fmeteorites.draw(window);
			}

			for (Item& Fitems : items)
			{
				Fitems.renderItem(window);
			}

			if (rocket->getHp() <= 0)
			{
				// save
				addScore(menu.getName(), score);

				// reset
				score = 0;
				enemies.clear();
				meteorites.clear();
				bullets.clear();
				items.clear();
				background.reset();
				
				
				delete rocket;
				Player* rocket = new Player(spaceship, 100);
				
				level = 1;
				requireToKill = 5;
				enemykill = 0;
				maxMeteorite = 0;
				Maxbulletammo = 100; //จำนวนกรสุน
				bulletammo = Maxbulletammo;

				//delete 
				menu.updateMenuState(6);
			}

			rocket->draw(window);

			window.draw(framena_button);
			window.draw(frame_button);
			window.draw(scoretext);
			window.draw(scorebullet);
			window.draw(Hp);
			window.draw(Lvl);

			window.draw(LvbulbMax);
			window.draw(Lvbulb);

			window.draw(name_text);

			window.display();
			break;

		}

	}
	return 0;
}