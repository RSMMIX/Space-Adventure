#pragma once
#include "Library.h"
class Menu
{
    private:
        RenderWindow* window;
        Event ev;
        Font font;
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

        //playname
        Texture player_texture;
        Sprite player_sprite;

        //back Button
        Texture back_texture;
        Sprite back_button;

        //play Button
        Texture go_texture;
        Sprite  go_button;

        int action;
        
        //Name Input
        std::string player_name;
        sf::Text name_input;

        //how to play
        sf::Texture how_texture;
        sf::Sprite how_sprite;

        //back button
        Texture howback_texture;
        Sprite  howback_button;

        bool type_bounce;
        bool valid_name;

    public:
        Menu(sf::RenderWindow* window);
        
        void updateMenuState(int action);

        int getMenuState();

        void updateMenu();

        void updateNameInput(sf::Event& event);

        void updateName();

        void renderName();

        void updateHow();

        void renderHow();

        void renderMenu();

};

