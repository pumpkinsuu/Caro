#include "Game.h"

Game::Game()
	: window(sf::VideoMode(WIDTH, HEIGHT), "CARO", sf::Style::Close),
	  draw(window),
	  bot(board),
	  stateNext(CONTINUE), 
	  state(new Menu(window, stateNext, audio, draw)),
	  menu(state),
	  file(new File(window, stateNext, board, bot, audio, draw)),
	  play(new Play(window, stateNext, board, bot, audio, draw))
{
	audio.music();
}

void Game::run()
{
	while (window.isOpen())
	{
		state->run();

		state->display();
		
		if (stateNext != CONTINUE) 
			change();	
	}
}

void Game::change()
{
	switch (stateNext)
	{
	case TWO_PLAYER: case ONE_PLAYER:
		if (stateNext == ONE_PLAYER)
			board.type = 1;
		else
			board.type = 0;

		state = play;
	
		break;
	case LOAD:
		state = file;
		
		break;
	case SAVE:
		state = file;
		
		break;
	case RETURN:
		state = play;

		break;
	case MENU:
		state = menu;

		break;
	case QUIT:

		state = nullptr;

		delete menu;
		delete file;
		delete play;

		window.close();

		break;
	}
}