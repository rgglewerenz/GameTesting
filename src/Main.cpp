#include "Includes.h"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	View myView;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 1;
	;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!", sf::Style::Fullscreen, settings);

	sClock timer;
	Game test;
	test.Init(window);

	Sorter sort;
	sort.initItems(100, 1, window.getSize().x, window.getSize().y);
	sf::Event event;

	Printer printer("Hello", "content/Fonts/RetroFont.ttf", 50, 80, 80, Color::Green);

	bool focused = true;
	bool fullscreen = true;
	float temp;
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
				myView.setCenter(window.getSize().x / 2, window.getSize().y / 2);
				myView.setSize(window.getSize().x, window.getSize().y);
				test.NewScale(window.getSize().x, window.getSize().y);
				window.setView(myView);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape) && fullscreen)
			{
				window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!", sf::Style::Default | sf::Style::Resize, settings);
				myView.setCenter(window.getSize().x / 2, window.getSize().y / 2);
				myView.setSize(window.getSize().x, window.getSize().y);
				test.NewScale(window.getSize().x, window.getSize().y);
				window.setView(myView);
				fullscreen = !fullscreen;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape) && !fullscreen)
			{
				window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!", sf::Style::Fullscreen, settings);
				myView.setCenter(window.getSize().x / 2, window.getSize().y / 2);
				myView.setSize(window.getSize().x, window.getSize().y);
				test.NewScale(window.getSize().x, window.getSize().y);
				window.setView(myView);
				fullscreen = !fullscreen;
			}
			timer.DeltaT();
		}
		temp = timer.DeltaT();
		if (temp > 10 && focused)
		{
			;
		}

		window.clear();
		test.Draw(window);
		test.Update(temp);
		printer.Print(window);
		printer.setText("Hello " + to_string(1 / temp));
		window.display();
	}

	return 0;
}
