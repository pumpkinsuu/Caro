#include "File.h"


File::File(sf::RenderWindow& _window, int& _stateNext, Board& _board, Bot& _bot, Audio& _audio, Display& _draw)
	: window(_window), stateNext(_stateNext), stateCur(LOAD),
	  board(_board), bot(_bot),
	  audio(_audio), draw(_draw)
{
	box.left = WIDTH / 2 - SIZE_M * 2;
	box.top = HEIGHT / 2 + LINE_SPACE / 2;
	box.width = SIZE_M * 4;
	box.height = LINE_SPACE;
}

void File::run()
{
	if (stateNext != CONTINUE)
		stateCur = stateNext;

	sf::Event event;

	while (window.pollEvent(event))
		if (event.type == sf::Event::Closed)
			window.close();
		else if (event.type == sf::Event::MouseButtonReleased)
			change();
		else if (event.key.code == sf::Keyboard::BackSpace && !name.empty())
			name.pop_back();
		else if (event.type == sf::Event::TextEntered) 
			if (event.text.unicode < 128 && name.length() < 11)
			{
				if (!name.empty())
					if (name.back() == '!')
						name.clear();

				if (((char)event.text.unicode >= 'a' &&
					(char)event.text.unicode <= 'z') ||
					((char)event.text.unicode >= 'A' &&
					(char)event.text.unicode <= 'Z') ||
					((char)event.text.unicode >= '0' &&
					(char)event.text.unicode <= '9') ||
					(char)event.text.unicode == ' ')
					name.push_back((char)event.text.unicode);
			}
				
}

void File::change()
{
	int i = update();

	if (i == -1)
		return;

	if (!name.empty() && i == 0)
	{
		if (stateCur == LOAD)
		{
			if (board.load(name))
			{
				if (board.type == 0 || bot.load(name))
					name = "LOADED!";
			}
			else
				name = "File not exist!";
		}
		else
		{
			if (board.save(name))
			{
				if (board.type == 0 || bot.save(name))
					name = "SAVED!";
			}
			else
				name = "SAVED FAILED!";
		}				

		stateNext = CONTINUE;
	}
	else if (i == 1)
	{
		name.clear();

		stateNext = RETURN;
	}
		

	audio.click();
}

int File::update()
{
	sf::Vector2i pos = Common::index(window, box, 1, 2);

	return pos.y;
}

void File::display()
{
	draw.File(update(), name);
}
