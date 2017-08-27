#ifndef SPHERES_
#define SPHERES_

#include <vector>
#include <SFML/Graphics.hpp>
#include "../sugar.hpp"

class Spheres
{
private:
	std::vector<char> spheres;
	sf::Texture texture;
public:
	sf::Sprite sprites[3];
	Spheres()
	{
		texture.loadFromFile("Materials/sprite_list.png");
	}
	void push(char const & c)
	{
		if (spheres.size() < 3)
		{
			spheres.insert(spheres.begin(), c);
		}
		else
		{
			spheres.erase(spheres.begin());
			spheres.push_back(c);
		}
	}
	std::vector<char> get()
	{
		return spheres;
	}
	void updateSprites()
	{
		for (int i = 0; i < spheres.size(); ++i)
		{
			sprites[i].setTexture(texture);
			sprites[i].setPosition(400 + 26 * i, 494);
			sugar::setSizeInPix(sprites[i], 20, 20);
			sprites[i].setTextureRect(getIntRect(spheres[i]));
		}
	}
	void print()
	{
		for (char c : get())
			std::cout << c << " ";
		std::cout << "\n";
	}
	static sf::IntRect getIntRect(char const & c)
	{
		if (c == 'q')
			return (sf::IntRect(0, 0, 128, 128));
		if (c == 'w')
			return (sf::IntRect(128, 0, 128, 128));
		if (c == 'e')
			return (sf::IntRect(256, 0, 128, 128));
	}
	void draw(sf::RenderWindow& App)
	{
		updateSprites();

		for (sf::Sprite sprite : sprites)
			App.draw(sprite);
	}
};

#endif // SPHERES_