#pragma once

#include "Define.h"


#define SOUND_CLICK "data/sound/click.wav"
#define SOUND_MUSIC "data/sound/App - My First.ogg"


class Audio
{
	sf::SoundBuffer buffer_click;
	sf::SoundBuffer buffer_music;
	
	sf::Sound sound;
	sf::Sound song;

public:

	Audio();

	void click();
	void music();
};
