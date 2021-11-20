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
        Texture bgpaus_texture;
        Sprite bgpaus_sprite;
        //button playpase
        Texture playpase_texture;
        Sprite  playpase_button;
        //button backpase
        Texture backpase_texture;
        Sprite  backpase_button;

        //bgleaderboards
        Texture leader_texture;
        Sprite leader_sprite;
        Text text_num[5];
        Text text_name[5];
        Text text_score[5];

        //button backleaderboards
        Texture backlea_texture;
        Sprite  backlea_button;

        
        bool type_bounce;
        bool valid_name;

        bool escape_bounce;

    public:
        Menu(sf::RenderWindow* window);

        string getName();
        
        int getMenuState();

        void updateMenuState(int action);

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

        void renderGameOver();

        void checktriggerPause();

        void updateleaderboards();

        void renderleaderboards();

};

