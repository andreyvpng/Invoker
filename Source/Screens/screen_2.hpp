#ifndef SCREEN_2
#define SCREEN_2

#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"
#include "../sugar.hpp"
#include "../score.hpp"

class screen_2 : public cScreen
{
private:

public:
	screen_2(void);
	
	virtual int Run(sf::RenderWindow &App);
};

screen_2::screen_2(void) {}

int screen_2::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;

	sf::Clock clock;

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Font font;
	font.loadFromFile("Materials/Constantine_Bold.ttf");

	sf::Text GameOver;
	GameOver.setFont(font);
	GameOver.setCharacterSize(20);
	GameOver.setString("Game Over");
	sugar::centering(GameOver, App);

	sf::Text textOfScore;
	textOfScore.setFont(font);
	textOfScore.setCharacterSize(20);
	textOfScore.setString("Score: " + std::to_string(last_score));
	sugar::centering(textOfScore, App);

	bool showScore = false;

	while (Running)
	{
		if (clock.getElapsedTime().asSeconds() >= 1.0f)
			showScore = true;
		if (clock.getElapsedTime().asSeconds() >= 2.0f)
			return 0;

		while (App.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Escape:
					return 0;
					break;
				default:
					break;
				}
			}
		}
		App.clear(sf::Color::Black);

		if(showScore)
			App.draw(textOfScore);
		else
			App.draw(GameOver);

		App.display();
	}

	return -1;
}

#endif // SCREEN_2