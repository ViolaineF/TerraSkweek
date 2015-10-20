#include "AudioFile.h"



AudioFile::AudioFile(string a, sf::Sound b)
{
	buffer.loadFromFile(a);
	sound.setBuffer(buffer);
}

AudioFile::AudioFile(string a)
{
	music.openFromFile(a);
	music.setLoop(true);

}

void AudioFile::PlaySfx()
{
	sound.setVolume(40);
	sound.play();
}

void AudioFile::PlayM()
{
	music.setVolume(40);
	sound.play();
}

void AudioFile::Stop()
{
}

