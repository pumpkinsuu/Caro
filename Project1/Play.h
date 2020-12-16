#pragma once

#include "Common.h"

#include "Audio.h"
#include "Display.h"

#include "Board.h"
#include "Bot.h"

#include "State.h"



class Play : public State
{
	sf::RenderWindow& window;
	int& stateNext;

	Board& board;

	Bot& bot;

	Audio& audio;
	Display& draw;

	sf::Rect <int> box[4];
	
public:

	Play(sf::RenderWindow& _window, int& _stateNext, Board& _board, Bot& _bot, Audio& _audio, Display& _draw);
	~Play() {}

	void run();	
	void display();

private:

	sf::Vector2i update();
	void change();
};
