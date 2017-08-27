#ifndef MENU_
#define MENU_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>


class menu {
private:
	int current;
	int max;
public:
	std::vector<sf::Text> labels;
	menu(int max_)
	{
		max = (max_ - 1);
		current = 0;
	}
	void Up()
	{
		if (current > 0) 
			current--;
		fillCollorCurrent();
	}
	void Down()
	{
		if (current < max) 
			current++;
		fillCollorCurrent();
	}
	int getCurrent()
	{
		return current;
	}
	int getMax()
	{
		return max;
	}
	void fillCollorCurrent()
	{
		for (sf::Text& label : labels)
			label.setFillColor(sf::Color::White);

		labels[current].setFillColor(sf::Color::Red);
	}
	void draw(sf::RenderWindow& App)
	{
		for(sf::Text label: labels)
			App.draw(label);
	}
};

#endif // MENU_