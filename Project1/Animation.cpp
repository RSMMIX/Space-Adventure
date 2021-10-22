#include "Animation.h"

Animation::Animation(Texture* texture, Vector2u imageCount, float switchTime)
{
	imageCount = imageCount;
	switchTime = switchTime;
	totalTime = 0.0f;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.width = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (deltaTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}


