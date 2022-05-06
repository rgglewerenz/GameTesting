#include "Game.h"
void Game::Draw(RenderWindow& window)
{
	window.draw(ball);
}

void Game::Init(RenderWindow& window)
{
	ball = CircleShape(4);

	Vector2f pos_vec;
	pos_vec.x = window.getSize().x / 2;
	pos_vec.y = window.getSize().y / 2;
	ball.setPosition(pos_vec);
	ball.setRadius(radius);
	ball.setFillColor(Color::Magenta);

	maxX = window.getSize().x;
	maxY = window.getSize().y;
}

void Game::Update(float deltaT)
{
	Vector2f pos_vec;
	pos_vec.x = ball.getPosition().x + (speedx * deltaT);
	pos_vec.y = ball.getPosition().y + (speedy * deltaT);

	if (pos_vec.x + (radius * 2) > maxX)
	{
		speedx *= -1;
		pos_vec.x = (maxX - (radius * 2)) + (speedx * deltaT);
	}
	else if (pos_vec.x < 0)
	{
		speedx *= -1;
		pos_vec.x = (speedx * deltaT);
	}

	if (pos_vec.y + (radius * 2) > maxY)
	{
		speedy *= -1;
		pos_vec.y = (maxY - (radius * 2)) + (speedy * deltaT);
	}
	else if (pos_vec.y < 0)
	{

		speedy *= -1;
		pos_vec.y = (speedy * deltaT);
	}
	ball.setPosition(pos_vec);
}

void Game::NewScale(float x, float y)
{
	cout << 1 / x << endl;
	cout << 1 / y << endl;
	ball.setScale(Vector2f(x, y));
	float z = (sqrt(pow(1 / x, 2) + pow(1 / y, 2)) / sqrt(2));
	if (z > 1)
	{
		;
	}
	ball.setRadius(radius * sqrt(pow(1 / x, 2) + pow(1 / y, 2)));
	cout << radius << endl;
	//float a = 9 / z;
	ball.setPosition(Vector2f(200 - (radius * 2) - (13.5 / x), 200 - (radius * 2) - (1.5 / y)));
}