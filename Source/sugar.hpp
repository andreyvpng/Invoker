#ifndef SUGAR_
#define SUGAR_

#include <SFMl/Graphics.hpp>

namespace sugar
{
	template <class T>
	void setSizeInPix(T& object, float width, float height)
	{
		object.setScale(width / object.getLocalBounds().width,
						height / object.getLocalBounds().height);
	}
	template <class T>
	void centeringX(T& object, sf::RenderWindow const& window)
	{
		sf::FloatRect spriteRect = object.getLocalBounds();
		object.setOrigin(spriteRect.left + spriteRect.width / 2.0f,
						 spriteRect.top + spriteRect.height);
		object.setPosition(sf::Vector2f(window.getSize().x / 2.0f, object.getPosition().y));
	}
	template <class T>
	void centeringY(T& object, sf::RenderWindow const& window)
	{
		sf::FloatRect spriteRect = object.getLocalBounds();
		object.setOrigin(spriteRect.left + spriteRect.width,
						 spriteRect.top + spriteRect.height / 2.0f);
		object.setPosition(sf::Vector2f(object.getPosition().x, window.getSize().y / 2.0f));
	}
	template <class T>
	void centering(T& object, sf::RenderWindow const& window)
	{
		sf::FloatRect spriteRect = object.getLocalBounds();
		object.setOrigin(spriteRect.left + spriteRect.width / 2.0f,
						 spriteRect.top + spriteRect.height / 2.0f);
		object.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));
	}
}

#endif // SUGAR_