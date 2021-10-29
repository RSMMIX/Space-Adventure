#pragma once
#include "Library.h"

class Item
{
private:
	sf::Texture* item_texture;
	sf::Sprite item_sprite;

	int item_type;
	// 0 ซ้อมยาน
	// 1 โล่
	// 2 เพิ่มชีวิตยาน(อะไรยาน?)
	// 3 เหรียญ
public:
	Item(sf::Texture* texture,sf::Vector2f init_position,int type);

	sf::FloatRect getGlobalBounds();
	int& getItem();

	void renderItem(sf::RenderTarget& target);
};

