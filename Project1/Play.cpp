#include "Play.h"


Play::Play(sf::RenderWindow& _window, int& _stateNext, Board& _board, Bot& _bot, Audio& _audio, Display& _draw)
	: window(_window), stateNext(_stateNext), 
	  board(_board), bot(_bot),
	  audio(_audio), draw(_draw)
{
	box[0].left = WIDTH / 13 - LINE_SPACE / 2;
	box[0].top = HEIGHT / 10 - LINE_SPACE / 2;
	box[0].width = LINE_SPACE;
	box[0].height = LINE_SPACE;

	box[1].left = WIDTH * 12 / 13 - LINE_SPACE / 2;
	box[1].top = HEIGHT / 10 - LINE_SPACE / 2;
	box[1].width = LINE_SPACE;
	box[1].height = LINE_SPACE;

	box[2].left = WIDTH / 2 - COL / 2 * (SIZE_BOX + SIZE_BOX_OL) - SIZE_BOX / 2;
	box[2].top = HEIGHT / 2 - ROW / 2 * (SIZE_BOX + SIZE_BOX_OL) - SIZE_BOX / 2;
	box[2].width = SIZE_BOX + SIZE_BOX_OL;
	box[2].height = SIZE_BOX + SIZE_BOX_OL;

	box[3].left = WIDTH * 5 / 14 - SIZE_M * 2 / 3;
	box[3].top = HEIGHT * 29 / 30 - SIZE_M / 5;
	box[3].width = WIDTH * 2 / 14;
	box[3].height = SIZE_M * 2 / 5;
}

void Play::run()
{
	

	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			stateNext = QUIT;
		else if (event.type == sf::Event::MouseButtonReleased)
			change();
	}

	if (board.type == 1)
		bot.move();
}

void Play::change()
{
	sf::Vector2i pos = update();

	if (pos.x == -1)
	{
		switch (pos.y)
		{
		case -1:
			return;
			break;
		case 0:
			board.reset();
			board.score[0] = board.score[1] = 0;
			bot.lvl = bot.turn = 0;

			stateNext = MENU;

			break;
		case 1:
			board.reset();
			board.score[0] = board.score[1] = 0;

			break;
		case 2:
			board.undo();

			if (board.type == 1 && board.turn == bot.turn)
				board.undo();

			break;
		case 3:
			board.reset();
			
			break;
		case 4:
			stateNext = LOAD;

			break;
		case 5:
			stateNext = SAVE;

			break;
		case 6:
			bot.turn = 1 - bot.turn;

			break;
		case 7:
			bot.lvl = 0;
			
			break;
		case 8:
			bot.lvl = 1;

			break;
		}

		audio.click();

		return;
	}

	if (!board.getCur(pos.x, pos.y))
		return;

	board.check();

	audio.click();
}

sf::Vector2i Play::update()
{
	sf::Vector2i pos = Common::index(window, box[0], 1, 3);
	pos.x = -1;

	if (pos.y == -1)
	{
		pos = Common::index(window, box[1], 1, 3);
		pos.x = -1;

		if (pos.y == -1)
			pos = Common::index(window, box[2], COL, ROW);
		else
			pos.y += 3;
	}

	if (pos.y == -1)
	{
		pos = Common::index(window, box[3], 3, 1);

		if (pos.y != -1)
		{
			pos.y = pos.x + 6;
			pos.x = -1;
		}

	}
	
	return pos;
}

void Play::display()
{
	sf::Vector2i pos = update();
	
	if (pos.x < 0)
		draw.Play(pos.y, board, bot);
	else
		draw.Play(-1, board, bot);
}
