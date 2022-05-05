#pragma once
#include "Platform/Platform.hpp"
#include "Util\sClock.h"
using namespace sf;
class Game
{
public:
	void Init(RenderWindow& window);
	void Update(float deltaT);
	void Draw(RenderWindow& window);

private:
	CircleShape ball;
	int maxX, maxY;
	float radius = 10;
	float speedx = 80;
	float speedy = 100;
};