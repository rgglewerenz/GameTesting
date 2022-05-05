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
	ball.setFillColor(Color::Red);

	maxX = window.getSize().x;
	maxY = window.getSize().y;
}

void Game::Update(float deltaT)
{
	Vector2f pos_vec;
	if (ball.getPosition().x + (speedx * deltaT) + (radius * 2) >= maxX || ball.getPosition().x + (speedx * deltaT) <= 0)
	{
		speedx *= -1;
	}
	if (ball.getPosition().y + (speedy * deltaT) + (radius * 2) >= maxY || ball.getPosition().y + (speedy * deltaT) <= 0)
	{
		speedy *= -1;
	}
	pos_vec.x = ball.getPosition().x + (speedx * deltaT);
	pos_vec.y = ball.getPosition().y + (speedy * deltaT);
	ball.setPosition(pos_vec);
}