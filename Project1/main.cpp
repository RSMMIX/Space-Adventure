#include "Pawn.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include<vector>
int main()
{
	srand(time_t(static_cast<unsigned>(0)));
	RenderWindow window(VideoMode(1920, 1080), "My Game", Style::Close | Style::Titlebar);
	vector < Bullet > ammunition;
	vector < Enemy > enemies;
	
	Texture spaceship;
	spaceship.loadFromFile("textures/Spaceship/mship1.png");
	Player rocket(spaceship);
	
	Texture shot;
	shot.loadFromFile("textures/Bullet/buttet.png");

	Texture enemy;
	enemy.loadFromFile("textures/Enemy/enemies.png");
	
	Texture bg;
	bg.loadFromFile("textures/Bg/bg1.jpg");
	RectangleShape background;
	background.setSize(Vector2f(1920, 1080));
	background.setTexture(&bg);

	/*Sprite sprite(bg);
	sprite.setPosition(0, 0);
	Shader parallaxShader;
	parallaxShader.loadFromMemory
	("uniform float offset;"

		"void main() {"
		"    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
		"    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
		"    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;" // magic
		"    gl_FrontColor = gl_Color;"
		"}"
		,Shader::Vertex);
	float offset = 0.f;*/
	

	float speed = 150.f;

	Clock clock;
	float deltaTime = 0;
	float sumtime = 0;
	float bullettime = 0;
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sumtime += deltaTime;
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
	
		//parallaxShader.setUniform("offset", offset += clock.restart().asSeconds() / 10);
		if (Keyboard::isKeyPressed(Keyboard::Space) && bullettime >= 0.1f)
		{
			bullettime -= 0.1f;
			ammunition.push_back(Bullet(&shot, rocket.spacecraft.getPosition(), rocket.spacecraft.getRotation()));
		}
		if (sumtime >= 5.0f)
		{
			sumtime -= 5.0f;
			enemies.push_back(Enemy(&enemy));

		}
		

		// ↓ Update
		rocket.update(deltaTime);

		for (Bullet& Fbullet : ammunition)
		{
			Fbullet.update(deltaTime);
		}

		for (Enemy& Fenemy : enemies)
		{
			Fenemy.update(deltaTime,rocket.spacecraft.getPosition());
		}

		window.clear();
		window.draw(background);
		//window.draw(sprite, &parallaxShader);

		// ↓ Draw

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