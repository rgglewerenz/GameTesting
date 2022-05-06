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

	if (ball.getPosition().x + (radius * 2) > maxX)
	{
		speedx *= -1;
		pos_vec.x = (maxX - (radius * 2)) + (speedx * deltaT);
	}
	else if (ball.getPosition().x < 0)
	{
		speedx *= -1;
		pos_vec.x = (speedx * deltaT);
	}

	if (ball.getPosition().y + (radius * 2) > maxY)
	{
		speedy *= -1;
		pos_vec.y = (maxY - (radius * 2)) + (speedy * deltaT);
	}
	else if (ball.getPosition().y < 0)
	{

		speedy *= -1;
		pos_vec.y = (speedy * deltaT);
	}
	ball.setPosition(pos_vec);
}

void Game::NewScale(float x, float y)
{
	ball.setScale(Vector2f(x, y));
	ball.setRadius(radius * (1 / sqrt(pow(x, 2) + pow(y, 2))));
}