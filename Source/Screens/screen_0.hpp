#ifndef _SCREEN_0_
#define _SCREEN_0_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"
#include "../menu.hpp"
#include "../score.hpp"

class screen_0 : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
	sf::Font font;
	sf::Text text;
public:
	screen_0(void);
	virtual int Run(sf::RenderWindow &App);
};

screen_0::screen_0(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
	
	/*
		Score
	*/
	font.loadFromFile("Materials/Constantine_Bold.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition({ 60.0f, 60.0f });
}

int screen_0::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	int alpha = 0;

	menu menu(2);

	std::string str[] = { "Start", "Exit" };

	for (int i = 0; i <= menu.getMax(); ++i)
	{
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(20);
		text.setString(str[i]);
		text.setPosition({ 60.f, 425.f + i * 60 });
		menu.labels.push_back(text);
	}
	menu.Up();

	Texture.loadFromFile("Materials/bg_menu.png");
	Sprite.setTexture(Texture);

	if(last_score != -1)
		text.setString("Last Score: " + std::to_string(last_score));

	if (playing)
	{
		alpha = alpha_max;
	}

	while (Running)
	{
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
				case sf::Keyboard::Up:
					menu.Up();
					break;
				case sf::Keyboard::Down:
					menu.Down();
					break;
				case sf::Keyboard::Return:
					if (menu.getCurrent() == 0)
					{
						playing = true;
						return (1);
					}
					else
					{
						return (-1);
					}
					break;
				default:
					break;
				}
			}
		}
		if (alpha < alpha_max)
		{
			alpha++;
		}
		Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		App.clear();
		App.draw(Sprite);
		if (alpha == alpha_max)
		{
			App.draw(menu.labels[0]);
			App.draw(menu.labels[1]);
			App.draw(text);
		}
		App.display();
	}

	// ����� �� ����������
	return (-1);
}

#endif