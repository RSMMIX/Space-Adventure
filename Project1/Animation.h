#pragma once
#include "Scene.h"
class Animation
{
public:
	Animation(Texture* texture, Vector2u imageCount , float switchTime);
	~Animation();

	void update(int row, float deltaTime);

public:
	IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;

	float totalTime;
	float switchTime;
};
