#pragma once

#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

#define WIDTH 800
#define HEIGHT 600

#define COL 15
#define ROW 15

enum STATE
{
	CONTINUE,

	ENTER,

	RETURN,

	BACK,

	QUIT,

	INFO,

	INTRO,

	MENU,

	START,

	NEW,

	LOAD,

	SAVE,

	RESET,

	PLAY,

	TWO_PLAYER,

	ONE_PLAYER,	
};