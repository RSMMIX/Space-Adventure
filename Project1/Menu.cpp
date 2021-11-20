#include "Menu.h"

Menu::Menu(sf::RenderWindow* window) //แก้ตัวอักษร ตัวอักษรไม่แสดงผลหน้าเกม แก้เพียบ
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
	back_button.setPosition(Vector2f(250, 760));

	go_texture.loadFromFile("textures/Button/play1.png");
	go_button.setTexture(go_texture);
	go_button.setPosition(Vector2f(1170, 760));

	//name
	font.loadFromFile("fonts/Blern regular.ttf");
	name_input.setFont(font);
	name_input.setCharacterSize(60);
	name_input.setOrigin(Vector2f(name_input.getGlobalBounds().width, name_input.getGlobalBounds().height) / 2.f);
	name_input.setPosition(Vector2f(830, 425));

	//name creator name
	name_creator.setFont(font);
	name_creator.setCharacterSize(30);
	name_creator.setOrigin(Vector2f(name_creator.getGlobalBounds().width, name_creator.getGlobalBounds().height) / 2.f);
	name_creator.setPosition(Vector2f(1450, 15));

	//howtoplay
	how_texture.loadFromFile("textures/menu/howtoplay.jpg");
	how_sprite.setTexture(how_texture);

	// back how to play
	howback_texture.loadFromFile("textures/Button/back.png");
	howback_button.setTexture(howback_texture);
	howback_button.setPosition(Vector2f(20, 900));

	//gameover
	over_texture.loadFromFile("textures/menu/gameover.jpg");
	over_sprite.setTexture(over_texture);

	//back game over
	backov_texture.loadFromFile("textures/Button/back.png");
	backov_button.setTexture(backov_texture);
	backov_button.setOrigin(Vector2f(play_button.getLocalBounds().width / 2, play_button.getLocalBounds().height / 2));
	backov_button.setPosition(Vector2f(960, 840));

	//bg paus
	bgpaus_texture.loadFromFile("textures/menu/pause.jpg");
	bgpaus_sprite.setTexture(bgpaus_texture);

	//button playpase
	backpase_texture.loadFromFile("textures/Button/button4.png");
	backpase_button.setTexture(backpase_texture);
	backpase_button.setPosition(Vector2f(1060, 500));

	//button playpase
	playpase_texture.loadFromFile("textures/Button/resume.png");
	playpase_button.setTexture(playpase_texture);
	playpase_button.setPosition(Vector2f(360, 500));

	//bgleaderboards
	leader_texture.loadFromFile("textures/menu/leaderboards.jpg");
	leader_sprite.setTexture(leader_texture);
	for(int i=0;i<5;i++)
	{
		text_num[i].setFont(font);
		text_num[i].setCharacterSize(70);
		text_num[i].setString(to_string(i+1));
		text_num[i].setOrigin(Vector2f(text_num[i].getLocalBounds().width / 2,text_num[i].getLocalBounds().height / 2));
		text_num[i].setPosition(Vector2f(550.f,330.f + 120.f*i));

		text_name[i].setFont(font);
		text_name[i].setCharacterSize(70);
		text_name[i].setString("");
		text_name[i].setOrigin(Vector2f(text_num[i].getLocalBounds().width / 2,text_num[i].getLocalBounds().height / 2));
		text_name[i].setPosition(Vector2f(600.f,330.f + 120.f*i));
		
		text_score[i].setFont(font);
		text_score[i].setCharacterSize(70);
		text_score[i].setString("");
		text_score[i].setOrigin(Vector2f(text_num[i].getLocalBounds().width / 2,text_num[i].getLocalBounds().height / 2));
		text_score[i].setPosition(Vector2f(1280.f,330.f + 120.f*i));
	}

	//button backleaderboards 
	backlea_texture.loadFromFile("textures/Button/back.png");
	backlea_button.setTexture(backlea_texture);
	backlea_button.setOrigin(Vector2f(backlea_button.getLocalBounds().width / 2, backlea_button.getLocalBounds().height / 2));
	backlea_button.setPosition(Vector2f(960, 980));

	escape_bounce = 0;



}

string Menu::getName()
{
	return player_name;
}

void Menu::updateMenuState(int action)
{
    this->action = action;
}

int Menu::getMenuState()
{
    return action;
}

void Menu::checktriggerPause()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		if (!escape_bounce)
		{
			escape_bounce = 1;
			updateMenuState(7);
			
		}
	}
	else
	{
		escape_bounce = 0;
	}
}


void Menu::updateMenu()
{
		name_creator.setString(" 64010726 RATTANAPORN SOMCHAINUEK ");
        //Play
		if (play_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			play_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				while (Mouse::isButtonPressed(sf::Mouse::Left));
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
				while (Mouse::isButtonPressed(sf::Mouse::Left));
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

				while (Mouse::isButtonPressed(sf::Mouse::Left));
				readScoreFile();
				updateMenuState(3);
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
				while (Mouse::isButtonPressed(sf::Mouse::Left));
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
		name_input.setOrigin(Vector2f(name_input.getGlobalBounds().width / 2, name_input.getGlobalBounds().height / 2));
		name_input.setPosition(Vector2f(1020, 450));
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
				else if (event.text.unicode < 128 && player_name.length() < 8 && event.text.unicode != 8)
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player_name != "")
		{
			while (Mouse::isButtonPressed(sf::Mouse::Left));
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
			while (Mouse::isButtonPressed(sf::Mouse::Left));
			updateMenuState(0);
		}
	}
	else
	{
		back_button.setScale(sf::Vector2f(1.0f, 1.0f));
	}
}

void Menu::updateleaderboards()
{
	for(int i=0;i<5;i++)
	{
		text_name[i].setString(scoreData[i].name);

		text_score[i].setString(to_string(scoreData[i].score));
	}
	if (backlea_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
	{
		backlea_button.setScale(sf::Vector2f(1.1f, 1.1f));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			while (Mouse::isButtonPressed(sf::Mouse::Left));
			updateMenuState(0);
		}
	}
	else
	{
		backov_button.setScale(sf::Vector2f(1.0f, 1.0f));
	}
}


void Menu::renderleaderboards()
{
	window->clear();

	window->draw(leader_sprite);
	window->draw(backlea_button);

	for(int i=0;i<5;i++)
	{
		window->draw(text_num[i]);
		window->draw(text_name[i]);
		window->draw(text_score[i]);
	}

	window->display();
}

void Menu::updateHow()
{
	if (howback_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			howback_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				while (Mouse::isButtonPressed(sf::Mouse::Left));
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
	window->draw(name_creator);
    
    window->display();
}

void Menu::updatePause()
{
		if (playpase_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			playpase_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				while (Mouse::isButtonPressed(sf::Mouse::Left));
				updateMenuState(2);
			}
		}

		else
		{
			playpase_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}

		if (backpase_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			backpase_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				while (Mouse::isButtonPressed(sf::Mouse::Left));
				updateMenuState(5);
			}
		}
		else
		{
			backpase_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}
}

void Menu::renderPause()
{
	window->clear();

	window->draw(bgpaus_sprite);
	window->draw(playpase_button);
	window->draw(backpase_button);

	window->display();
}

void Menu::updateGameOver()
{
	if (backov_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
	{
		backov_button.setScale(sf::Vector2f(1.1f, 1.1f));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			while (Mouse::isButtonPressed(sf::Mouse::Left));
			updateMenuState(0);
		}
	}
	else
	{
		backov_button.setScale(sf::Vector2f(1.0f, 1.0f));
	}
}

void Menu::renderGameOver()
{
	window->clear();

	window->draw(over_sprite);
	window->draw(backov_button);

	window->display();
}

void Menu::renderHow()
{
	window->clear();

	window->draw(how_sprite);
	window->draw(howback_button);

	window->display();
}
