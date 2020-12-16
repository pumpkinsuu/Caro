#pragma once

#include "Define.h"

class TextBox : public sf::Drawable
{
	sf::Text text;

	sf::RectangleShape box;

public:

	TextBox();

	void setFont(const sf::Font& font);
	void setSize(int size);
	void setColor(const sf::Color& color);
	void setSizeOL(int size);
	void setColorOL(const sf::Color& color);
	void setStyle(sf::Text::Style style);
	void setText(const sf::String& string);
	
	void boxColor(const sf::Color& color);
	void boxSize(int x, int y);
	void boxColorOL(const sf::Color& color);
	void boxSizeOL(int size);

	void setRotate(float f);

	void setPos(int x, int y);

	void scale(float f);
	void unScale();

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};