#include "Common.h"


sf::Vector2i Common::index(sf::RenderWindow& window, sf::Rect <int> rect, int col, int row)
{
	sf::Vector2i cur(sf::Mouse::getPosition(window));

	if (cur.x < rect.left || cur.x > rect.left + rect.width * col ||
		cur.y < rect.top  || cur.y > rect.top + rect.height * row)
		return sf::Vector2i(-1, -1);

	cur.x = (cur.x - rect.left) / rect.width;
	cur.y = (cur.y - rect.top) / rect.height;

	return cur;
}
