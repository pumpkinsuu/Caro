#include "TextBox.h"

TextBox::TextBox()
{
	box.setFillColor(sf::Color::Transparent);
}

void TextBox::setFont(const sf::Font& font)
{
	text.setFont(font);
}

void TextBox::setSize(int size)
{
	text.setCharacterSize(size);
}

void TextBox::setColor(const sf::Color& color)
{
	text.setFillColor(color);
}

void TextBox::setSizeOL(int size)
{
	text.setOutlineThickness(size * 1.0f);
}

void TextBox::setColorOL(const sf::Color& color)
{
	text.setOutlineColor(color);
}

void TextBox::setStyle(sf::Text::Style style)
{
	text.setStyle(style);
}

void TextBox::setText(const sf::String& string)
{
	text.setString(string);

	sf::FloatRect rect = text.getLocalBounds();

	text.setOrigin(rect.left + rect.width / 2.0f,
				   rect.top + rect.height / 2.0f);
}

void TextBox::boxColor(const sf::Color& color)
{
	box.setFillColor(color);
}

void TextBox::boxSize(int x, int y)
{
	box.setSize(sf::Vector2f(x * 1.0f, y * 1.0f));
}

void TextBox::boxColorOL(const sf::Color& color)
{
	box.setOutlineColor(color);
}

void TextBox::boxSizeOL(int size)
{
	box.setOutlineThickness(size * 1.0f);
}


void TextBox::setRotate(float f)
{
	text.setRotation(f);
}

void TextBox::setPos(int x, int y)
{
	text.setPosition(sf::Vector2f(x * 1.0f, y * 1.0f));

	sf::FloatRect rect = box.getLocalBounds();

	box.setOrigin(rect.left + rect.width / 2.0f,
				  rect.top + rect.height / 2.0f);

	box.setPosition(sf::Vector2f(x * 1.0f, y * 1.0f));
}


void TextBox::scale(float f)
{
	text.scale(sf::Vector2f(f * 1.0f, f * 1.0f));
}

void TextBox::unScale()
{
	sf::Vector2f f = text.getScale();
	f.x = 1 / f.x;
	f.y = 1 / f.y;

	text.scale(f);
}


void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box, states);
	target.draw(text, states);
}
