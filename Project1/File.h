#pragma once

#include "Common.h"

#include "Audio.h"
#include "Display.h"

#include "State.h"


class File : public State
{
	sf::RenderWindow& window;
	int& stateNext;

	int stateCur;

	Board& board;
	Bot& bot;

	Audio& audio;
	Display& draw;
	
	string name;

	sf::Rect <int> box;

public:

	File(sf::RenderWindow& _window, int& _stateNext, Board& _board, Bot& _bot, Audio& _audio, Display& _draw);
	~File() {};

	void run();
	void display();

private:

	int update();
	void change();
};