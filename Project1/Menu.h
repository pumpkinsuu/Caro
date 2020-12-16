#pragma once

#include "Common.h"

#include "Audio.h"
#include "Display.h"

#include "State.h"


class Menu : public State
{
	sf::RenderWindow& window;
	int& stateNext;

	int stateCur;

	Audio& audio;
	Display& draw;

	sf::Rect <int> box;

public:

	Menu(sf::RenderWindow& _window, int& _stateNext, Audio& _audio, Display& _draw);
	~Menu() {};
	
	void run();	
	void display();

private:

	int update();
	void change();
};