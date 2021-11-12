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
	score_button.setPosition(Vector2f(960, 500));

	tutorial_texture.loadFromFile("textures/Button/button3.png");
	tutorial_button.setTexture(tutorial_texture);
	tutorial_button.setOrigin(Vector2f(tutorial_button.getLocalBounds().width / 2, tutorial_button.getLocalBounds().height / 2));
	tutorial_button.setPosition(Vector2f(960, 650));

	quit_texture.loadFromFile("textures/Button/button4.png");
	quit_button.setTexture(quit_texture);
	quit_button.setOrigin(Vector2f(quit_button.getLocalBounds().width / 2, quit_button.getLocalBounds().height / 2));
	quit_button.setPosition(Vector2f(960, 800));
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
		if (this->play_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			this->play_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->updateMenuState(2);
			}
		}
		else
		{
			this->play_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}

		//Tutorial
		if (this->tutorial_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			this->tutorial_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//this->updateMenuState(4);
			}
		}
		else
		{
			this->tutorial_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}

		//Score
		if (this->score_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			this->score_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//this->updateMenuState(3);
			}
		}
		else
		{
			this->score_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}

		//Quit
		if (this->quit_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			this->quit_button.setScale(sf::Vector2f(1.1f, 1.1f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
			    this->updateMenuState(5);
			}
		}
		else
		{
			this->quit_button.setScale(sf::Vector2f(1.0f, 1.0f));
		}
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
