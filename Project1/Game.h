#include "Menu.h"
#include "Play.h"
#include "File.h"

class Game
{
	sf::RenderWindow window;

	Board board;
	Bot bot;

	Audio audio;

	Display draw;

	int stateNext;
	State* state;

	State* menu;
	State* file;
	State* play;

public:

	Game();
	~Game() {}

	void run();
	void change();
};