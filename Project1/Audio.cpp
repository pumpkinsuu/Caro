#include "Audio.h"

Audio::Audio()
{
	buffer_click.loadFromFile(SOUND_CLICK);
	buffer_music.loadFromFile(SOUND_MUSIC);
}

void Audio::click()
{
	sound.setBuffer(buffer_click);
	sound.play();
}

void Audio::music()
{
	song.setBuffer(buffer_music);
	song.setLoop(1);
	song.setVolume(10);
	song.play();
}