/*
	(C) Andrey Varfolomeev. See licence.txt in the root of the distribution for more information.
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screens/cScreen.hpp"
#include "Screens/screen_0.hpp"
#include "Screens/screen_1.hpp"

int main(int argc, char** argv)
{
	std::vector<cScreen*> Screens;
	int screen = 0;

	sf::RenderWindow App(sf::VideoMode(800, 600), "QWE");

	App.setMouseCursorVisible(false);

	screen_0 s0;
	Screens.push_back(&s0);
	screen_1 s1;
	Screens.push_back(&s1);

	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}