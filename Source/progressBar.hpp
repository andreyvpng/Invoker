#ifndef PROGRESS_BAR
#define PROGRESS_BAR

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class progressBar
{
private:
	int width;
	int height;
	float value;
	bool gameOver;
public:
	sf::RectangleShape bar;
	void setSize(int width_, int height_)
	{
		gameOver = false;
		width = width_;
		height = height_;
	}
	void setColor(sf::Color color)
	{
		bar.setFillColor(color);
	}
	void setPositon(float x, float y)
	{
		bar.setPosition(x, y);
	}
	void setPercentage(float value_)
	{
		value = value_;
		bar.setSize(sf::Vector2f(width * value / 100.0f, height));
	}
	void draw(sf::RenderWindow& App)
	{
		App.draw(bar);
	}
};

#endif // PROGRESS_BAR