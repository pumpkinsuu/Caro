#include "Menu.h"

Menu::Menu(sf::RenderWindow& _window, int& _stateNext, Audio& _audio, Display& _draw)
	: window(_window),	stateNext(_stateNext), stateCur(INTRO),
	  audio(_audio), draw(_draw)
{
	box.left = WIDTH / 2 - SIZE_M * 2;
	box.top = HEIGHT / 2 - LINE_SPACE / 2;
	box.width = SIZE_M * 4;
	box.height = LINE_SPACE;
}

void Menu::run()
{
	if (stateNext != CONTINUE)
		stateCur = stateNext;

	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			stateNext = QUIT;
		else if (event.type == sf::Event::MouseButtonReleased)
			change();
	}
}

void Menu::change()
{
	int i = update();

	if (i == -1)
		return;

	if (stateCur == INFO && i < 2)
		return;

	switch (i)
	{
	case 0:
		if (stateCur == INTRO)
		{
			stateCur = MENU;
			stateNext = CONTINUE;
		}	
		else
			stateNext = TWO_PLAYER;

		break;
	case 1:
		if (stateCur == INTRO)
		{
			stateCur = INFO;
			stateNext = CONTINUE;
		}
		else
			stateNext = ONE_PLAYER;

		break;
	case 2:
		if (stateCur == INTRO)
			stateNext = QUIT;
		else
		{
			stateCur = INTRO;
			stateNext = CONTINUE;
		}

		break;
	}

	audio.click();
}

int Menu::update()
{
	sf::Vector2i pos = Common::index(window, box, 1, 3);
	
	return pos.y;
}

void Menu::display()
{
	if (stateCur == INTRO)
		draw.Intro(update());
	else if (stateCur == INFO)
		draw.Info(update());
	else
		draw.Menu(update());
}
