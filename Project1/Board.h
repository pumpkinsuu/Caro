#pragma once

#include "Define.h"

class Board
{
	sf::Vector2i cur;

public:

	int box[COL][ROW];

	vector <sf::Vector3i> stack;
	vector <sf::Vector2i> win_stack;

	bool type;
	bool turn;
	int X;
	int O;
	int score[2];

	Board();
	~Board() {}

	void reset();

	bool load(const string& save_name);
	bool save(const string& save_name);

	
	bool getCur(int x, int y);

	void undo();

	bool check();

private:

	void set(int x, int y, int val);

	bool inRange(int x, int y);
	bool win();
	bool test(int kX, int kY);
	bool count(int kX, int kY);
};
