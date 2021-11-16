#pragma once
#include "Library.h"
class Menu
{
    private:
        RenderWindow* window;
        Event ev;
        Font font;
        //Background
        Texture bg_texture;
        Sprite bg_sprite;

        //Play Button
        Texture play_texture;
        Sprite play_button;

        //Scoreboard Button
        Texture score_texture;
        Sprite score_button;

        //Tutorial Button
        Texture tutorial_texture;
        Sprite tutorial_button;

        //Quit Button
        Texture quit_texture;
        Sprite quit_button;

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
        string player_name;
        Text name_input;
        Text name_creator;

        //how to play
        Texture how_texture;
        Sprite how_sprite;

        //back button
        Texture howback_texture;
        Sprite  howback_button;
        
        //gameover
        Texture over_texture;
        Sprite over_sprite;

        //backover
        Texture backov_texture;
        Sprite  backov_button;

        //bg paus
        Texture bgpa_texture;
        Sprite bgpa_sprite;
        //button playpase
        Texture playpa_texture;
        Sprite  playpa_button;
        //button backpase
        Texture blackpa_texture;
        Sprite  blackpa_button;

        bool type_bounce;
        bool valid_name;

        bool escape_bounce;

    public:
        Menu(sf::RenderWindow* window);

        string getName();
        
        void updateMenuState(int action);

        int getMenuState();

        void updateMenu();

        void updateNameInput(sf::Event& event);

        void updateName();

        void renderName();

        void updateHow();

        void renderHow();

        void renderMenu();

        void updatePause();

        void renderPause();

        void updateGameOver();

        void remderGameOver();

        void checktriggerPause();
};

