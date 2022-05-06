#pragma once
#include "Platform/Platform.hpp"
class Printer
{
public:
	//Input the text, the font, and the size of the text
	Printer(std::string _text, sf::Font font, int size)
	{
		text = sf::Text(_text, font, size);
		__x = 0;
		__y = 0;
		text.setPosition(sf::Vector2f(__x, __y));
	}

	//Input the text, the font, and the size of the text, and the xy chords of the text
	Printer(std::string _text, sf::Font _font, int _size, int x, int y)
	{
		font = _font;
		text = sf::Text(_text, _font, _size);
		size = _size;
		__x = x;
		__y = y;
		text.setPosition(sf::Vector2f(__x, __y));
	}

	//Input the text, the font, and the size of the text, and the xy chords of the text, and the color
	Printer(std::string _text, sf::Font _font, int _size, int x, int y, const sf::Color& color)
	{
		font = _font;
		text = sf::Text(_text, _font, _size);
		size = _size;
		__x = x;
		__y = y;
		text.setPosition(sf::Vector2f(__x, __y));
		text.setFillColor(color);
	}

	//Input the text, the font file loc, and the size of the text
	Printer(std::string _text, std::string fileLoc, int _size)
	{
		font.loadFromFile(fileLoc);
		size = _size;
		text = sf::Text(_text, font, size);
		__x = 0;
		__y = 0;
		text.setPosition(sf::Vector2f(__x, __y));
	}

	//Input the text, the font file loc, and the size of the text, and the xy chords of the text
	Printer(std::string _text, std::string fileLoc, int _size, int x, int y)
	{
		font.loadFromFile(fileLoc);
		size = _size;
		text = sf::Text(_text, font, size);
		__x = x;
		__y = y;
		text.setPosition(sf::Vector2f(__x, __y));
	}

	//Input the text, the font file loc, and the size of the text, and the xy chords of the text, and the text color
	Printer(std::string _text, std::string fileLoc, int _size, int x, int y, const sf::Color& color)
	{
		font.loadFromFile(fileLoc);
		size = _size;
		text = sf::Text(_text, font, size);
		__x = x;
		__y = y;
		text.setPosition(sf::Vector2f(__x, __y));
		text.setFillColor(color);
	}

	//Empty constructor
	Printer()
	{
		__x = 0;
		__y = 0;
		size = 0;
	}

	//Prints the text to the renderwindow given
	void Print(sf::RenderWindow& window);
	//Sets the color of the window
	void setColor(const sf::Color& color);
	//Sets the xy pos with a vector
	void setPosition(const sf::Vector2f& vec_pos);
	//Sets the xy pos manually
	void setPosition(int x, int y);
	//Sets the scale of the text in case of resizing
	void setScale(float x, float y);
	//Sets the rotation of the text in degrees
	void setRotation(float angleDeg);
	//Sets the Text with a sf::Text obj
	void setText(const sf::Text& text_);
	//Sets the current text to the string given
	void setText(std::string text);
	//Sets the current text to the string given
	void setText(std::string text, const sf::Color& color);
	//Sets the text to the text given, and the fileloc of the font to use
	void setText(std::string text, std::string fileLoc);
	//Sets the text to the text given, and the fileloc of the font to use, and the color to use
	void setText(std::string text, std::string fileLoc, const sf::Color& color);
	//Sets the size of the text
	void setSize(int size);
	//returns the position of the text on the screen as a Vector2f
	sf::Vector2f getPosition();
	//returns the size of the text
	int getSize();
	//returns the xy scaling of the text as a Vector2f
	sf::Vector2f getScale();

private:
	sf::Font font;
	sf::Text text;
	int size;
	int __x;
	int __y;
};
