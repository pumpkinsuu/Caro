#include "Board.h"


Board::Board()
	 : type(0), turn(1), X(0), O(0), score{ 0, 0 }, 
	   cur(COL / 2, ROW / 2)
{
	for (int i = 0; i < COL; ++i)
		for (int j = 0; j < ROW; ++j)
			box[i][j] = 0;
}


void Board::reset()
{
	turn = 1;
	X = 0;
	O = 0;

	for (int i = 0; i < COL; ++i)
		for (int j = 0; j < ROW; ++j)
			box[i][j] = 0;

	stack.clear();
	win_stack.clear();
}

bool Board::load(const string& save_name)
{
	string file = ".\\data\\save\\";
	file += (type) ? "1 player\\" : "2 player\\";
	file += save_name;
	file += ".txt";

	std::ifstream in(file);
	if (!in.good())
	{
		std::cout << "Load Fail! \n";
		return 0;
	}

	reset();

	in >> type >> turn >> score[0] >> score[1];

	int x, y, val;

	while (in >> x >> y >> val)
		set(x, y, val);

	win();

	return 1;
}

bool Board::save(const string& save_name)
{
	string file = ".\\data\\save\\";
	file += (type) ? "1 player\\" : "2 player\\";
	file += save_name;
	file += ".txt";

	std::ofstream out(file);
	if (!out.is_open())
	{
		std::cout << "Save Fail! \n";
		return 0;
	}

	out << type << ' ' << turn << ' ' << score[0] << ' ' << score[1];

	for (auto i : stack)
		out << ' ' << i.x << ' ' << i.y << ' ' << i.z;

	return 1;
}


bool Board::getCur(int x, int y)
{
	if (inRange(x, y))
	{
		cur.x = x;
		cur.y = y;

		return 1;
	}

	return 0;
}


void Board::undo()
{
	if (stack.empty())
		return;

	box[stack.back().x][stack.back().y] = 0;
	stack.pop_back();

	turn = 1 - turn;
	(turn) ? --X : --O;


	if (!win_stack.empty())
	{
		win_stack.clear();

		(turn) ? --score[1] : --score[0];
	}
}


bool Board::check()
{
	if (!win_stack.empty() || box[cur.x][cur.y])
		return 0;

	
	set(cur.x, cur.y, (turn) ? 1 : -1);
	turn = 1 - turn;


	if (win())
	{
		if (stack.back().z == 1)
			++score[1];
		else
			++score[0];
	}

	return 1;
}



void Board::set(int x, int y, int val)
{
	box[x][y] = val;

	if (val == 1)
		++X;
	else if (val == -1)
		++O;

	sf::Vector3i tmp(x, y, val);
	stack.push_back(tmp);
}


bool Board::inRange(int x, int y)
{
	return (x >= 0 && x < COL &&
			y >= 0 && y < ROW);
}


bool Board::win()
{
	if (stack.empty() || stack.size() == COL * ROW) 
		return 0;

	if ((test(1, 0) || test(0, 1) || test(1, 1) || test(1, -1)))
	{
		sf::Vector2i tmp(stack.back().x, stack.back().y);
		win_stack.push_back(tmp);
	}

	return (!win_stack.empty());
}


bool Board::test(int kI, int kJ)
{	
	if (count(-kI, -kJ) + count(kI, kJ) == 2 || int(win_stack.size()) < 4)
	{
		win_stack.clear();

		return 0;
	}

	return 1;
}

bool Board::count(int kI, int kJ)
{
	int i = stack.back().x + kI, j = stack.back().y + kJ, val = stack.back().z;

	while (inRange(i, j) && box[i][j] == val)
	{
		sf::Vector2i tmp(i, j);
		win_stack.push_back(tmp);

		i += kI;
		j += kJ;
	}

	return (inRange(i, j) && box[i][j] == -val);
}