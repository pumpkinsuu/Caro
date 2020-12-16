#include "Display.h"

Display::Display(sf::RenderWindow& _window)
	: window(_window)
{
	window.setVerticalSyncEnabled(true);

	icon.loadFromFile(ICON);

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	texture_bg.loadFromFile(BACKGROUND, sf::IntRect(100, 100, WIDTH, HEIGHT));
	texture_bg.setSmooth(1);

	background.setTexture(texture_bg);
	

	font_m.loadFromFile(FONT_M);
	font_t.loadFromFile(FONT_T);
	font_t_s.loadFromFile(FONT_T_S);

	texture_m.loadFromFile(ICON_BACK);
	texture_m.setSmooth(1);

	texture_r.loadFromFile(ICON_RESET);
	texture_r.setSmooth(1);

	texture_u.loadFromFile(ICON_UNDO);
	texture_u.setSmooth(1);

	texture_n.loadFromFile(ICON_NEW);
	texture_n.setSmooth(1);

	texture_l.loadFromFile(ICON_LOAD);
	texture_l.setSmooth(1);

	texture_s.loadFromFile(ICON_SAVE);
	texture_s.setSmooth(1);
}


void Display::Intro(int i)
{
	window.clear(sf::Color::Transparent);

	window.draw(background);

	Title();


	TextBox text;

	text.setFont(font_m);
	text.setColor(COLOR_M);
	text.setStyle(sf::Text::Style::Bold);
	

	//
	if (i == 0)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("PLAY");
	
	text.setPos(WIDTH / 2, HEIGHT / 2);

	window.draw(text);

	//
	if (i == 1)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("INFO");

	text.setPos(WIDTH / 2, HEIGHT / 2 + LINE_SPACE);

	window.draw(text);

	//
	if (i == 2)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("QUIT");

	text.setPos(WIDTH / 2, HEIGHT / 2 + LINE_SPACE * 2);

	window.draw(text);


	window.display();
}

void Display::Menu(int i)
{
	window.clear(sf::Color::Transparent);

	window.draw(background);

	Title();


	TextBox text;

	text.setFont(font_m);
	text.setColor(COLOR_M);
	text.setStyle(sf::Text::Style::Bold);


	//
	if (i == 0)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("2 PLAYER");

	text.setPos(WIDTH / 2, HEIGHT / 2);

	window.draw(text);

	//
	if (i == 1)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("1 PLAYER");

	text.setPos(WIDTH / 2, HEIGHT / 2 + LINE_SPACE);

	window.draw(text);

	//
	if (i == 2)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("BACK");

	text.setPos(WIDTH / 2, HEIGHT / 2 + LINE_SPACE * 2);

	window.draw(text);


	window.display();
}

void Display::Info(int i)
{
	window.clear(sf::Color::Transparent);

	window.draw(background);

	TextBox text;
	
	//
	text.setFont(font_t_s);
	text.setSize(SIZE_M / 2);
	text.setColor(COLOR_M);
	
	text.setText(L"ĐỒ ÁN CARO");
	text.setPos(WIDTH / 2, HEIGHT / 10);
	window.draw(text);

	text.setText(L"Nhóm 7:");
	text.setPos(WIDTH / 2, HEIGHT / 10 + SIZE_M * 3 / 4);
	window.draw(text);

	text.setText(L"Nguyễn Minh Đức");
	text.setPos(WIDTH / 2, HEIGHT / 10 + SIZE_M * 3 / 2);
	window.draw(text);

	text.setText(L"Phạm Quốc Dũng");
	text.setPos(WIDTH / 2, HEIGHT / 10 + SIZE_M * 9 / 4);
	window.draw(text);

	text.setText(L"Đặng Thành Duy");
	text.setPos(WIDTH / 2, HEIGHT / 10 + SIZE_M * 3);
	window.draw(text);

	//
	text.setFont(font_m);
	text.setColor(COLOR_M);
	text.setStyle(sf::Text::Style::Bold);

	if (i == 2)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("BACK");

	text.setPos(WIDTH / 2, HEIGHT / 2 + LINE_SPACE * 2);

	window.draw(text);


	window.display();
}


void Display::Play(int i, const Board& board, const Bot& bot)
{
	Caro(board);

	time = clock.getElapsedTime();

	if (time.asSeconds() > 1.0f)
		clock.restart();

	TextBox text;

	text.setFont(font_t);
	text.setSize(SIZE_M);
	text.setStyle(sf::Text::Style::Bold);

	text.setColorOL(COLOR_M);
	text.setSizeOL(2);


	//	text
	text.setColor(COLOR_X);

	if (board.turn == 1 && time.asSeconds() < 0.5f && board.win_stack.empty())
		text.scale(1.25);
	
	text.setText("X");

	text.setPos(WIDTH * 1 / 13, HEIGHT * 8 / 13);

	window.draw(text);

	text.unScale();

	//
	string s;

	s = 'x';
	s += to_string(board.score[1]);

	text.setText(s);

	text.setPos(WIDTH * 1 / 13, HEIGHT * 10 / 13);

	window.draw(text);

	//
	s = "Move: ";
	s += to_string(board.X);

	text.setSize(SIZE_M / 2);

	text.setText(s);

	text.setPos(WIDTH * 1 / 13, HEIGHT * 12 / 13);

	window.draw(text);

	text.setSize(SIZE_M);

	//------------------------------------------------//

	//
	text.setColor(COLOR_O);

	if (board.turn == 0 && time.asSeconds() < 0.5f && board.win_stack.empty())
		text.scale(1.25);

	text.setText("O");

	text.setPos(WIDTH * 12 / 13, HEIGHT * 8 / 13);

	window.draw(text);

	text.unScale();

	//
	s = 'x';
	s += to_string(board.score[0]);

	text.setText(s);

	text.setPos(WIDTH * 12 / 13, HEIGHT * 10 / 13);

	window.draw(text);

	//
	s = "Move: ";
	s += to_string(board.O);

	text.setSize(SIZE_M / 2);

	text.setText(s);

	text.setPos(WIDTH * 12 / 13, HEIGHT * 12 / 13);

	window.draw(text);

	//------------------------------------------------//

	if (board.type == 1)
	{
		text.setFont(font_t_s);
		text.setSize(SIZE_M / 3);
		text.boxSize(SIZE_M * 5 / 4, SIZE_M * 3 / 5);
		text.boxSizeOL(3);

		text.boxColor(sf::Color::Transparent);
		text.boxColorOL(COLOR_M);

		//
		if (i == 6)
			text.scale(1.25);

		if (bot.turn)
		{
			text.setText("AI: X");
			text.setColor(COLOR_X);
		}	
		else
		{
			text.setText("AI: O");
			text.setColor(COLOR_O);
			
		}
			
		text.setPos(WIDTH * 5 / 14, HEIGHT * 29 / 30);

		window.draw(text);

		text.unScale();


		//
		if (i == 7)
			text.scale(1.25);

		if (bot.lvl == 0)
			text.boxColor(COLOR_HL);

		text.setText("Easy");

		text.setPos(WIDTH * 7 / 14, HEIGHT * 29 / 30);

		window.draw(text);

		text.unScale();
		text.boxColor(sf::Color::Transparent);

		//
		if (i == 8)
			text.scale(1.25);

		if (bot.lvl == 1)
			text.boxColor(COLOR_HL);

		text.setText("Hard");

		text.setPos(WIDTH * 9 / 14, HEIGHT * 29 / 30);

		window.draw(text);
	}

	//------------------------------------------------//


	//	button
	Button button;

	button.setTexture(texture_m);
	button.setColor(COLOR_HL_M);

	button.setPos(WIDTH * 1 / 13, HEIGHT * 1 / 10);

	if (i == 0)
		button.scale(1.2f);

	window.draw(button);
	
	button.unScale();

	//
	button.setTexture(texture_r);

	button.setPos(WIDTH * 1 / 13, HEIGHT * 1 / 10 + LINE_SPACE);

	if (i == 1)
		button.scale(1.2f);

	window.draw(button);

	button.unScale();

	//
	button.setTexture(texture_u);

	button.setPos(WIDTH * 1 / 13, HEIGHT * 1 / 10 + LINE_SPACE * 2);

	if (i == 2)
		button.scale(1.2f);

	window.draw(button);

	button.unScale();

	//------------------------------------------------//
	
	button.setTexture(texture_n);

	button.setPos(WIDTH * 12 / 13, HEIGHT * 1 / 10);
	
	if (i == 3)
		button.scale(1.2f);

	window.draw(button);

	button.unScale();

	//
	button.setTexture(texture_l);

	button.setPos(WIDTH * 12 / 13, HEIGHT * 1 / 10 + LINE_SPACE);

	if (i == 4)
		button.scale(1.2f);

	window.draw(button);

	button.unScale();

	//
	button.setTexture(texture_s);

	button.setPos(WIDTH * 12 / 13, HEIGHT * 1 / 10 + LINE_SPACE * 2);

	if (i == 5)
		button.scale(1.2f);

	window.draw(button);

	button.unScale();

	window.display();
}


void Display::File(int i, const string& name)
{
	window.clear(sf::Color::Transparent);

	window.draw(background);

	TextBox text;

	text.setFont(font_m);
	text.setSize(SIZE_M);
	text.setColor(COLOR_M);
	text.setStyle(sf::Text::Style::Bold);

	//
	text.setText("FILE NAME:");

	text.setPos(WIDTH / 2, HEIGHT / 4 - LINE_SPACE / 2);

	window.draw(text);


	//
	text.setFont(font_t_s);
	text.setSize(SIZE_M);
	
	text.boxSize(SIZE_M * 8, LINE_SPACE * 3 / 2);
	text.boxColorOL(COLOR_M);
	text.boxSizeOL(7);

	time = clock.getElapsedTime();

	if (time.asSeconds() > 1.0f)
		clock.restart();
	
	string tmp = name;

	if (time.asSeconds() < 0.5f && tmp.length() < 10)
		tmp += '|';


	text.setText(tmp);

	text.setPos(WIDTH / 2, HEIGHT / 4 + LINE_SPACE);

	window.draw(text);


	//
	text.setFont(font_m);
	text.setSize(SIZE_M);
	text.setColor(COLOR_M);
	
	text.boxColorOL(sf::Color::Transparent);

	if (i == 0)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("ENTER");

	text.setPos(WIDTH / 2, HEIGHT / 2 + LINE_SPACE);

	window.draw(text);

	//
	if (i == 1)
		text.setSize(SIZE_M * 5 / 4);
	else
		text.setSize(SIZE_M);

	text.setText("RETURN");

	text.setPos(WIDTH / 2, HEIGHT / 2 + LINE_SPACE * 2);

	window.draw(text);


	window.display();
}


void Display::Caro(const Board& board)
{
	window.clear(sf::Color::Transparent);

	window.draw(background);


	TextBox text;

	text.setFont(font_t);
	text.setSize(SIZE_CARO);
	text.setStyle(sf::Text::Style::Bold);


	//	board
	text.boxSize((SIZE_BOX + SIZE_BOX_OL) * COL + SIZE_BOX_OL, (SIZE_BOX + SIZE_BOX_OL) * ROW + SIZE_BOX_OL);
	text.boxSizeOL(SIZE_BOX_OL);
	text.boxColorOL(COLOR_BOARD);

	text.setPos(WIDTH / 2, HEIGHT / 2);

	window.draw(text);


	//	caro
	text.setSizeOL(1);
	text.setColorOL(COLOR_M);
	text.boxSize(SIZE_BOX, SIZE_BOX);
	text.boxColorOL(COLOR_M);

	for (int i = 0; i < COL; ++i)
		for (int j = 0; j < ROW; ++j)
		{
			if (board.box[i][j] == 1)
			{
				text.setColor(COLOR_X);
				text.setColorOL(COLOR_M);
				text.setText("X");
			}
			else if (board.box[i][j] == -1)
			{
				text.setColor(COLOR_O);
				text.setColorOL(COLOR_M);
				text.setText("O");
			}
			else
			{
				text.setColor(sf::Color::Transparent);
				text.setColorOL(sf::Color::Transparent);
			}

			text.setPos(WIDTH / 2 - COL / 2 * (SIZE_BOX + SIZE_BOX_OL) + i * (SIZE_BOX + SIZE_BOX_OL),
					    HEIGHT / 2 - ROW / 2 * (SIZE_BOX + SIZE_BOX_OL) + j * (SIZE_BOX + SIZE_BOX_OL));

			window.draw(text);
		}


	// last check
	if (!board.stack.empty())
	{
		if (board.stack.back().z == 1)
		{
			text.setColor(COLOR_X);
			text.setColorOL(COLOR_M);
			text.boxColor(COLOR_HL_X);
			text.setText("X");
		}
		else if (board.stack.back().z == -1)
		{
			text.setColor(COLOR_O);
			text.setColorOL(COLOR_M);
			text.boxColor(COLOR_HL_O);
			text.setText("O");
		}

		text.setPos(WIDTH / 2 - COL / 2 * (SIZE_BOX + SIZE_BOX_OL) + board.stack.back().x * (SIZE_BOX + SIZE_BOX_OL),
					HEIGHT / 2 - ROW / 2 * (SIZE_BOX + SIZE_BOX_OL) + board.stack.back().y * (SIZE_BOX + SIZE_BOX_OL));

		window.draw(text);
	}


	time = clock.getElapsedTime();

	if (time.asSeconds() > 1.0f)
		clock.restart();

	//	win
	if (!board.win_stack.empty() && time.asSeconds() < 0.5f)
	{
		if (board.stack.back().z == 1)
			text.boxColor(COLOR_HL_X);
		else
			text.boxColor(COLOR_HL_O);

		for (auto i : board.win_stack)
		{
			text.setPos(WIDTH / 2 - COL / 2 * (SIZE_BOX + SIZE_BOX_OL) + i.x * (SIZE_BOX + SIZE_BOX_OL),
						HEIGHT / 2 - ROW / 2 * (SIZE_BOX + SIZE_BOX_OL) + i.y * (SIZE_BOX + SIZE_BOX_OL));

			text.scale(1.25f);

			window.draw(text);

			text.unScale();
		}


		//
		text.boxColor(sf::Color::Transparent);
		text.boxColorOL(sf::Color::Transparent);

		if (time.asSeconds() < 0.5f)
		{
			if (board.stack.back().z == 1)
				text.setText("X: WIN!");
			else
				text.setText("O: WIN!");

			text.setPos(WIDTH / 2, HEIGHT / 30);

			text.scale(1.25f);

			window.draw(text);

			text.unScale();
		}
	}


	//
	text.setColor(COLOR_BLUE);
	text.boxColor(sf::Color::Transparent);
	text.boxColorOL(sf::Color::Transparent);

	if (board.X + board.O == COL * ROW && time.asSeconds() < 0.5f)
	{
		text.setText("DRAW!");

		text.setPos(WIDTH / 2, HEIGHT / 30);

		text.scale(1.25f);

		window.draw(text);

		text.unScale();
	}
}


void Display::Title()
{
	time = clock.getElapsedTime();

	if (time.asSeconds() > 0.6f)
		clock.restart();

	//	title
	TextBox text;

	text.setFont(font_m);
	text.setSize(SIZE_M * 2);
	text.setStyle(sf::Text::Style::Bold);

	text.setColorOL(COLOR_M);
	text.setSizeOL(2);

	if (time.asSeconds() < 0.3f)
		text.setColor(COLOR_X);
	else
		text.setColor(COLOR_O);

	text.setText("C");

	text.setRotate(-30.0f);
	text.setPos(WIDTH / 2 - SIZE_M * 5 / 2, HEIGHT / 4);

	window.draw(text);

	if (time.asSeconds() < 0.3f)
		text.setColor(COLOR_O);
	else
		text.setColor(COLOR_X);

	text.setText("A");

	text.setRotate(-15.0f);
	text.setPos(WIDTH / 2 - SIZE_M, HEIGHT / 4 - SIZE_M / 2);

	window.draw(text);

	if (time.asSeconds() < 0.3f)
		text.setColor(COLOR_X);
	else
		text.setColor(COLOR_O);

	text.setText("R");

	text.setRotate(15.0f);
	text.setPos(WIDTH / 2 + SIZE_M, HEIGHT / 4 - SIZE_M / 2);

	window.draw(text);

	if (time.asSeconds() < 0.3f)
		text.setColor(COLOR_O);
	else
		text.setColor(COLOR_X);

	text.setText("O");

	text.setRotate(30.0f);
	text.setPos(WIDTH / 2 + SIZE_M * 5 / 2, HEIGHT / 4);

	window.draw(text);
}

