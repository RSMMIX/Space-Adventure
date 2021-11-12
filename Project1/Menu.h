#pragma once
#include "Library.h"
class Menu
{
    private:
        sf::RenderWindow* window;
        sf::Event ev;
        //Background
        sf::Texture bg_texture;
        sf::Sprite bg_sprite;

        //Play Button
        sf::Texture play_texture;
        sf::Sprite play_button;

        //Scoreboard Button
        sf::Texture score_texture;
        sf::Sprite score_button;

        //Tutorial Button
        sf::Texture tutorial_texture;
        sf::Sprite tutorial_button;

        //Quit Button
        sf::Texture quit_texture;
        sf::Sprite quit_button;

        int action;

    public:
        Menu(sf::RenderWindow* window);
        
        void updateMenuState(int action);

        int getMenuState();

        void updateMenu();

        void renderMenu();

};

