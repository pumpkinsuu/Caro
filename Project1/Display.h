#pragma once
#include "Define.h"

#include "TextBox.h"
#include "Button.h"

#include "Board.h"
#include "Bot.h"


#define ICON "data/icon/icon.png"

#define ICON_BACK "data/icon/back.png"
#define ICON_RESET "data/icon/reset.png"
#define ICON_UNDO "data/icon/undo.png"
#define ICON_NEW "data/icon/new.png"
#define ICON_LOAD "data/icon/load.png"
#define ICON_SAVE "data/icon/save.png"

#define BACKGROUND "data/texture/caro.jpg"

// Color
#define COLOR_X sf::Color(255, 36, 0)
#define COLOR_O sf::Color(154, 205, 50)
#define COLOR_BLUE sf::Color(130, 183, 225)

#define COLOR_HL_X sf::Color(255, 36, 0, 100)
#define COLOR_HL_O sf::Color(154, 205, 50, 100)
#define COLOR_HL   sf::Color(205, 205, 250, 150)

#define COLOR_M sf::Color(78, 54, 41)
#define COLOR_HL_M sf::Color(78, 54, 41, 200)

#define COLOR_BOARD sf::Color(46, 46, 46, 200)

// Font
#define FONT_M "data/font/font_main.ttf" 
#define FONT_T "data/font/font_text.ttf" 
#define FONT_T_S "data/font/font_text_small.ttf"


// Main
#define SIZE_M 90 
#define LINE_SPACE 100

//Board
#define SIZE_BOX 30
#define SIZE_BOX_OL 3
#define SIZE_CARO 30


class Display
{
	sf::RenderWindow& window;

	sf::Clock clock;
	sf::Time time;

	sf::Font font_m;
	sf::Font font_t;
	sf::Font font_t_s;
	
	sf::Image icon;

	sf::Texture texture_m;
	sf::Texture texture_r;
	sf::Texture texture_u;
	sf::Texture texture_l;
	sf::Texture texture_n;
	sf::Texture texture_s;

	sf::Texture texture_bg;

	sf::Sprite background;

public:

	Display(sf::RenderWindow& _window);

	void Intro(int i);
	void Menu(int i);
	void Info(int i);

	void Play(int i, const Board& board, const Bot& bot);

	void File(int i, const string& name);

private:

	void Caro(const Board& board);

	void Title();
};

