#ifndef _SKILLS_
#define _SKILLS_

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../sugar.hpp"

class Skills
{
private:
	std::vector<std::string> skills;
	sf::Texture texture;
public:
	sf::Sprite sprites[2];
	Skills()
	{
		texture.loadFromFile("Materials/sprite_list.png");
	}
	void push(std::string const& skill)
	{
		if (skills.size() < 2)
		{
			skills.insert(skills.begin(), skill);
		}
		else
		{
			skills.pop_back();
			skills.insert(skills.begin(), skill);
		}
	}
	std::vector<std::string> get()
	{
		return skills;
	}
	std::string cast(std::vector<char> const& spheres)
	{
		if (spheres.size() == 3) {
			std::string skill;
			for (char c : spheres)
				skill += c;
			sort(skill.begin(), skill.end());
			
			if(skills.size() == 0 || (skills.size() >= 1 && skills[0] != skill))
			{
				push(skill);
				return skill;
			}
		}
	}
	void updateSprites()
	{
		for (int i = 0; i < skills.size(); ++i)
		{
			sprites[i].setTexture(texture);
			sprites[i].setTextureRect(getIntRect(skills[i]));
			sprites[i].setPosition(409 + 32 * i, 527);
			sugar::setSizeInPix(sprites[i], 26, 26);
		}
	}
	void print()
	{
		for (int i = 0; i < skills.size(); ++i)
		{
			std::cout << i + 1 << " " << skills[i] << "\n";
		}
	}
	static sf::IntRect getIntRect(std::string const & str)
	{
		if (str == "www") return (sf::IntRect(0, 128, 128, 128));
		if (str == "qww") return (sf::IntRect(128, 128, 128, 128));
		if (str == "eww") return (sf::IntRect(256, 128, 128, 128));
		if (str == "qqw") return (sf::IntRect(384, 128, 128, 128));
		if (str == "eqw") return (sf::IntRect(512, 128, 128, 128));
		if (str == "eew") return (sf::IntRect(640, 128, 128, 128));
		if (str == "qqq") return (sf::IntRect(768, 128, 128, 128));
		if (str == "eqq") return (sf::IntRect(896, 128, 128, 128));
		if (str == "eeq") return (sf::IntRect(1024, 128, 128, 128));
		if (str == "eee") return (sf::IntRect(1152, 128, 128, 128));
	}
	void draw(sf::RenderWindow& App)
	{
		updateSprites();

		for(sf::Sprite sprite: sprites)
			App.draw(sprite);
	}
};

#endif