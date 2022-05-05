#include "Includes.h"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(500.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!", sf::Style::Default, settings);

	sClock timer;
	Game test;
	test.Init(window);
	Sorter sort;
	sort.initItems(500, 1, window.getSize().x, window.getSize().y);
	sf::Event event;
	bool focused = true;
	float temp;
	float oldX = window.getSize().x;
	float oldY = window.getSize().y;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::GainedFocus)
				focused = true;
			else if (event.type == sf::Event::LostFocus)
				focused = false;
			else if (event.type == sf::Event::Resized)
			{
				cout << "Resized" << endl;
				test.NewScale(1 / (window.getSize().x / oldX), 1 / (window.getSize().y / oldY));
				cout << window.getSize().x / oldX << endl;
				cout << window.getSize().y / oldY << endl;
			}
			timer.DeltaT();
		}
		temp = timer.DeltaT();
		window.clear();
		if (window.hasFocus())
			test.Update(temp);
		if (focused)
			sort.UpdateSort();
		sort.DrawItems(window);
		test.Draw(window);
		window.display();
	}

	return 0;
}
