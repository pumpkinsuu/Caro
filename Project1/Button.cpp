#include "Button.h"


void Button::setTexture(const sf::Texture& texture)
{
	button.setTexture(texture);

	sf::FloatRect rect = button.getLocalBounds();

	button.setOrigin(rect.left + rect.width / 2.0f,
		rect.top + rect.height / 2.0f);

	box.width = int(rect.width);
	box.height = int(rect.height);
}

void Button::setColor(const sf::Color& color)
{
	button.setColor(color);
}

void Button::setPos(int x, int y)
{
	button.setPosition(x * 1.0f, y * 1.0f);

	box.left = int(button.getPosition().x) - box.width / 2;
	box.top = int(button.getPosition().y) - box.height / 2;
}


void Button::scale(float factor)
{
	button.scale(factor, factor);
}

void Button::unScale()
{
	sf::Vector2f f = button.getScale();
	f.x = 1 / f.x;
	f.y = 1 / f.y;

	button.scale(f);
}


sf::Vector2i Button::pos()
{
	return sf::Vector2i(button.getPosition());
}

const sf::Rect <int>& Button::rect()
{
	return box;
}


void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(button, states);
}