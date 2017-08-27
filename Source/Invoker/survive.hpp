#ifndef _SURVIVE_
#define _SURVIVE_

#include <string>
#include <algorithm>	// sort
#include <cstdlib>		// srand
#include <ctime>		// time
#include <SFML/Graphics.hpp>
#include "../sugar.hpp"
#include "skills.hpp"

class Survive
{
private:
	std::string last_skill;
	std::string current_skill;
	int score;
	sf::Texture texture;
public:
	sf::Sprite sprite;
	Survive()
	{
		texture.loadFromFile("Materials/sprite_list.png");
		sprite.setTexture(texture);
	}
	std::string generate()
	{
		last_skill = current_skill;
		std::srand(std::time(nullptr));

		repeat:
		std::string ans = "";
		for (int i = 0; i < 3; ++i)
		{
			switch (std::rand() % 3)
			{
			case 0:
				ans += "q";
				break;
			case 1:
				ans += "w";
				break;
			case 2:
				ans += "e";
				break;
			}
		}
		sort(ans.begin(), ans.end());

		if (ans == last_skill)
			goto repeat;

		current_skill = ans;
		updateSprite();

		return ans;
	}
	void updateSprite()
	{
		sprite.setTextureRect(Skills::getIntRect(current_skill));
	}
	void draw(sf::RenderWindow& App)
	{
		App.draw(sprite);
	}
	bool checkForCorrect(std::string const & skill)
	{
		return skill == current_skill;
	}
};

#endif