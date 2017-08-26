#ifndef _SCREEN_1_
#define _SCREEN_1_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"
#include "../Invoker/spheres.hpp"
#include "../Invoker/skills.hpp"
#include "../Invoker/survive.hpp"
#include "../progressBar.hpp"
#include "../sugar.hpp"

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
	text.setPosition({ 60.0f, 10.0f });
	
	survive.generate();
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
		survive.zeroScore();
	}
	
	isFirstLaunch = false;
	
	while (Running)
	{
		float timeOfGame = clock.restart().asMicroseconds();
		
		if (bar.isGameOver())
		{
			isFirstLaunch = true;
			return 0;
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
					if (survive.checkForCorrect( skills.cast( spheres.get() ) ))
					{
						survive.generate();
						valueOfBar = 100;
					}
					break;
				default:
					break;
				}
			}
		}
		
		valueOfBar -= 0.000004 * (survive.getScore() + 1) * timeOfGame;
		bar.setPercentage(valueOfBar);
		
		text.setString("Score: " + std::to_string(survive.getScore()));

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

#endif