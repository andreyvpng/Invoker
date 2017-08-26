#ifndef _CSREEN_
#define _CSREEN_

#include <SFML/Graphics.hpp>

class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};

#endif