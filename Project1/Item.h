#pragma once
#include "Library.h"

class Item
{
private:
	sf::Texture* item_texture;
	sf::Sprite item_sprite;

	int item_type;

	float timeDuration = 0.f;
	//ซ้อมยาน
	//โล่
	//ยิงกระสุนแบบอมตะ
	//เพิ่มความเร็วยาน

public:
	Item(sf::Texture* texture, sf::Vector2f init_position, int type);

	sf::FloatRect getGlobalBounds();
	int& getItem();
	void updateItem(float deltaTime);
	float& getItemTime();

	void renderItem(sf::RenderTarget& target);
};