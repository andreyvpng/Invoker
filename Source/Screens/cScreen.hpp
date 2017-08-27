#ifndef CSREEN_
#define CSREEN_

#include <SFML/Graphics.hpp>

class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};

#endif // CSREEN_