#pragma once

#include "Board.h"


class Bot
{
	Board& board;

	vector <int> MangDiemTanCong;
	vector <int> MangDiemPhongNgu;

public:

	bool turn;
	int lvl;

	Bot(Board& _board);

	void move();

	bool load(const string& save_name);
	bool save(const string& save_name);

private:

	void easy();
	
	bool TestAround(int x, int y);


	void hard();

	int DiemTC_DuyetDoc(int CurrDong, int CurrCot);
	int DiemTC_DuyetNgang(int CurrDong, int CurrCot);
	int DiemTC_DuyetCheoNguoc(int CurrDong, int CurrCot);
	int DiemTC_DuyetCheoXuoi(int CurrDong, int CurrCot);
	int DiemPN_DuyetDoc(int CurrDong, int CurrCot);
	int DiemPN_DuyetNgang(int CurrDong, int CurrCot);
	int DiemPN_DuyetCheoNguoc(int CurrDong, int CurrCot);
	int DiemPN_DuyetCheoXuoi(int CurrDong, int CurrCot);
};
