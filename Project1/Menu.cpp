#include "Menu.h"

Menu::Menu(sf::RenderWindow* window)
{
    this->window = window;

	bg_texture.loadFromFile("textures/menu/bgmenu.jpg");
    bg_sprite.setTexture(bg_texture);

	play_texture.loadFromFile("textures/Button/button1.png");
    play_button.setTexture(play_texture);
	play_button.setOrigin(Vector2f(play_button.getLocalBounds().width / 2, play_button.getLocalBounds().height / 2));
	play_button.setPosition(Vector2f(960, 350));

	score_texture.loadFromFile("textures/Button/button2.png");
	score_button.setTexture(score_texture);
	score_button.setOrigin(Vector2f(score_button.getLocalBounds().width / 2, score_button.getLocalBounds().height / 2));
	score_button.setPosition(Vector2f(960, 550));

	tutorial_texture.loadFromFile("textures/Button/button3.png");
	tutorial_button.setTexture(tutorial_texture);
	tutorial_button.setOrigin(Vector2f(tutorial_button.getLocalBounds().width / 2, tutorial_button.getLocalBounds().height / 2));
	tutorial_button.setPosition(Vector2f(960, 750));

	quit_texture.loadFromFile("textures/Button/button4.png");
	quit_button.setTexture(quit_texture);
	quit_button.setOrigin(Vector2f(quit_button.getLocalBounds().width / 2, quit_button.getLocalBounds().height / 2));
	quit_button.setPosition(Vector2f(960, 950));

	player_texture.loadFromFile("textures/menu/playmenu.jpg");
	player_sprite.setTexture(player_texture);

	back_texture.loadFromFile("textures/Button/back.png");
	back_button.setTexture(back_texture);
	back_button.setPosition(Vector2f(250, 750));

	go_texture.loadFromFile("textures/Button/play.png");
	go_button.setTexture(go_texture);
	go_button.setPosition(Vector2f(1170, 750));

	font.loadFromFile("fonts/Blern regular.ttf");
	name_input.setFont(font);
	name_input.setCharacterSize(60);
	name_input.setOrigin(Vector2f(0,name_input.getLocalBounds().height / 2 ));
	name_input.setPosition(Vector2f(800, 425));

	//howtoplay
	how_texture.loadFromFile("textures/menu/howtoplay.jpg");
	how_sprite.setTexture(how_texture);

	// back how to play
	howback_texture.loadFromFile("textures/Button/back.png");
	howback_button.setTexture(howback_texture);
	howback_button.setPosition(Vector2f(20, 900));
}

void Menu::updateMenuState(int action)
{
    this->action = action;
}

int Menu::getMenuState()
{
    return action;
}

void Menu::updateMenu()
{
        //Play
		if (play_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			play_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				updateMenuState(1);
			}
		}
		else
		{
			play_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}

		//Tutorial
		if (tutorial_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			tutorial_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				updateMenuState(4);
			}
		}
		else
		{
			tutorial_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}

		//Score
		if (score_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			score_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//this->updateMenuState(3);
			}
		}
		else
		{
			score_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}

		//Quit
		if (quit_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			quit_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
			    updateMenuState(5);
			}
		}
		else
		{
			quit_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}
}

void Menu::updateNameInput(sf::Event& event)
{
	ev = event;
	if (player_name == "" && !(ev.type == sf::Event::TextEntered))
	{
		name_input.setString("Type your name");
		type_bounce = 0;
		valid_name = 0;
	}
	else
	{
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode != 32 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !this->type_bounce)
			{
				type_bounce = 1;
				if (event.text.unicode == 8 && player_name.length() > 0)
				{
					player_name.erase(player_name.length() - 1);
				}
				else if (event.text.unicode < 128 && player_name.length() < 15 && event.text.unicode != 8)
				{
					player_name += static_cast<char>(event.text.unicode);
				}
				name_input.setString(player_name);
			}
		}
		else
			type_bounce = 0;
		valid_name = 1;
	}
}

void Menu::updateName()
{
	if (go_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			go_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				updateMenuState(2);
			}
		}
		else
		{
			go_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}

	if (back_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			back_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				updateMenuState(0);
			}
		}
		else
		{
			back_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}
}

void Menu::updateHow()
{
	if (howback_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			howback_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				updateMenuState(0);
			}
		}
		else
		{
			howback_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}
}

void Menu::renderName()
{
	window->clear();

	window->draw(player_sprite);
	window->draw(back_button);
	window->draw(go_button);
	window->draw(name_input);

	window->display();
}

void Menu::renderMenu()
{
	window->clear();

    window->draw(bg_sprite);
    window->draw(play_button);
    window->draw(score_button);
    window->draw(tutorial_button);
    window->draw(quit_button);
    
    window->display();
}

void Menu::renderHow()
{
	window->clear();

	window->draw(how_sprite);
	window->draw(howback_button);

	window->display();
}
