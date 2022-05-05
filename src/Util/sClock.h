#pragma once
#include "Platform/Platform.hpp"
class sClock
{
public:
	float DeltaT()
	{
		return time.restart().asSeconds();
	}

private:
	sf::Clock time;
};