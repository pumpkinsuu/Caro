#pragma once
#include "Define.h"

class Button : public sf::Drawable
{
	sf::Sprite button;

	sf::Rect <int> box;

public:

	Button() {}
	~Button() {}

	void setTexture(const sf::Texture& texture);
	void setColor(const sf::Color& color);
	void setPos(int x, int y);

	void scale(float factor);
	void unScale();

	sf::Vector2i pos();
	const sf::Rect <int>& rect();

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};