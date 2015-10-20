#ifndef AUDIOFILE_H
#define AUDIOFILE_H
#include <string>
#include "SFML/Audio.hpp"

using namespace std; 

class AudioFile
{
private:
	bool m_sound;// is it a sound or a background music ?
	sf::SoundBuffer buffer; // buffer for sound
	sf::Sound sound;
	sf::Music music; // buffer for music

public:
	AudioFile(string, bool);
	void PlayAudio();
	void StopAudio();
};

#endif