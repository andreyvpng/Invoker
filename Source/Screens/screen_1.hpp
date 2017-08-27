#ifndef SCREEN_1
#define SCREEN_1

#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"
#include "../Invoker/spheres.hpp"
#include "../Invoker/skills.hpp"
#include "../Invoker/survive.hpp"
#include "../progressBar.hpp"
#include "../sugar.hpp"
#include "../score.hpp"

class screen_1 : public cScreen
{
private:
	
public:
	screen_1(void);
	sf::Texture sprite_list;
	sf::Texture backgroud_texture;
	sf::Sprite backgroud_sprite;
	progressBar bar;
	Spheres spheres;
	Skills skills;
	Survive survive;
	float valueOfBar;
	bool isFirstLaunch;
	sf::Font font;
	sf::Text text;	
	virtual int Run(sf::RenderWindow &App);
};

screen_1::screen_1(void)
{
	/*
		Texture
	*/
	sprite_list.loadFromFile("Materials/sprite_list.png");

	/*
		Background
	*/
	backgroud_texture.loadFromFile("Materials/bg_game.png");
	backgroud_sprite.setTexture(backgroud_texture);

	/*
		Progress Bar
	*/
	bar.setColor(sf::Color::Green);
	bar.setSize(100, 5);
	bar.setPositon(345, 400);

	/*
		Score
	*/
	font.loadFromFile("Materials/Constantine_Bold.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition({ 60.0f, 60.0f });
	
	survive.generate();
	valueOfBar = 100;
	isFirstLaunch = true;
}

int screen_1::Run(sf::RenderWindow &App)
{
	sugar::centering(survive.sprite, App);
	
	sf::Event Event;
	sf::Clock clock;
	bool Running = true;

	if(isFirstLaunch)
	{
		valueOfBar = 100;
		bar.setPercentage(valueOfBar);			
	}

	isFirstLaunch = false;
	
	while (Running)
	{
		float timeOfGame = clock.restart().asMicroseconds();
		
		if (valueOfBar <= 0)
		{
			last_score = score;
			score = 0;
			isFirstLaunch = true;
			return 2;
		}

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
					return (0);
					break;
				case sf::Keyboard::Q:
					spheres.push('q');
					break;
				case sf::Keyboard::W:
					spheres.push('w');
					break;
				case sf::Keyboard::E:
					spheres.push('e');
					break;
				case sf::Keyboard::R:
					skills.cast(spheres.get());
					break;
				case sf::Keyboard::D:
					if(survive.checkForCorrect( skills.getD() ))
						valueOfBar = 100;
					break;
				case sf::Keyboard::F:
					if(survive.checkForCorrect( skills.getF() ))
						valueOfBar = 100;
					break;
				default:
					break;
				}
			}
		}
		
		valueOfBar -= 0.000001 * (score + 1) * timeOfGame;
		bar.setPercentage(valueOfBar);
		
		text.setString("Score: " + std::to_string(score));

		App.clear(sf::Color::Black);
		
		App.draw(backgroud_sprite);
		App.draw(text);
		skills.draw(App);
		spheres.draw(App);
		survive.draw(App);
		bar.draw(App);

		App.display();
	}

	return -1;
}

#endif // SCREEN_1