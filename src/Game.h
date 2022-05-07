#pragma once
#include "Platform/Platform.hpp"
#include "Util\sClock.h"
using namespace sf;
using namespace std;

class Game
{
public:
	void Init(RenderWindow& window);
	void Update(float deltaT);
	void Draw(RenderWindow& window);
	void NewScale(float x_, float y_);

private:
	CircleShape ball;
	int maxX, maxY;
	float radius = 0.05;
	float speedx = 10;
	float speedy = 10;
};