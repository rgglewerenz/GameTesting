#include "Printer.h"
using namespace std;
using namespace sf;
void Printer::Print(sf::RenderWindow& window)
{
	window.draw(text);
}

void Printer::setColor(const Color& color)
{
	text.setFillColor(color);
}

void Printer::setPosition(const sf::Vector2f& vec_pos)
{
	__x = vec_pos.x;
	__y = vec_pos.y;
	text.setPosition(vec_pos);
}

void Printer::setPosition(int x, int y)
{
	__x = x;
	__y = y;
	text.setPosition(Vector2f(x, y));
}

void Printer::setScale(float x, float y)
{
	text.setScale(x, y);
	text.setCharacterSize(size * (1 / sqrt(pow(x, 2) + pow(y, 2))));
}

void Printer::setRotation(float angleDeg)
{
	text.setRotation(angleDeg);
}

void Printer::setText(const sf::Text& text_)
{
	text = text_;
}

void Printer::setText(std::string _text)
{
	text = Text(_text, font, size);
	text.setPosition(Vector2f(__x, __y));
}

void Printer::setText(std::string _text, const sf::Color& color)
{
	text = Text(_text, font, size);
	text.setPosition(Vector2f(__x, __y));
	text.setFillColor(color);
}

void Printer::setText(std::string _text, std::string fileLoc)
{
	font.loadFromFile(fileLoc);
	text = Text(_text, font, size);
	text.setPosition(Vector2f(__x, __y));
}

void Printer::setText(std::string _text, std::string fileLoc, const sf::Color& color)
{
	font.loadFromFile(fileLoc);
	text = Text(_text, font, size);
	text.setPosition(Vector2f(__x, __y));
	text.setFillColor(color);
}

void Printer::setSize(int _size)
{
	size = _size;
}

Vector2f Printer::getPosition()
{
	return Vector2f(__x, __y);
}

int Printer::getSize()
{
	return size;
}

Vector2f Printer::getScale()
{
	return text.getScale();
}