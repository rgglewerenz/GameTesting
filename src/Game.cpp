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
	pos_vec.y = ball.getPosition().y + (speedy * deltaT) * ball.getScale().y;
	if (((pos_vec.x + (ball.getRadius() * 2))) > maxX)
	{
		speedx *= -1;
		pos_vec.x = (maxX - (radius * 2)) + (speedx * deltaT);
	}
	else if (pos_vec.x < 0)
	{
		speedx *= -1;
		pos_vec.x = (speedx * deltaT);
	}

	if (pos_vec.y + (ball.getRadius() * 2) > maxY)
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
	float scaleX = maxX / x;
	float scaleY = maxY / y;
	maxX = x;
	maxY = y;
	ball.setRadius(sqrt(pow(scaleX, 2) + pow(scaleY, 2)));
	//ball.setPosition(Vector2f(maxX - (radius * 2), maxY - (radius * 2)));
}
