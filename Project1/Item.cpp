#include "Item.h"

Item::Item(Texture* texture, Vector2f init_position, int type)
{
	item_texture = texture;
	item_sprite.setTexture(*item_texture);
	item_sprite.setScale(sf::Vector2f(0.5f , 0.5f));
	item_sprite.setOrigin(sf::Vector2f(item_sprite.getLocalBounds().width / 2,item_sprite.getLocalBounds().height / 2));
	item_sprite.setPosition(init_position);
	item_type = type;
}

sf::FloatRect Item::getGlobalBounds()
{
	return item_sprite.getGlobalBounds();
}

int& Item::getItem()
{
	return item_type;
}

void Item::updateItem(float deltaTime)
{
	timeDuration += deltaTime;
}

float& Item::getItemTime()
{
	return timeDuration;
}

void Item::renderItem(sf::RenderTarget& target)
{
	target.draw(item_sprite);
}
