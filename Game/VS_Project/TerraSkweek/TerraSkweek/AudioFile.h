#ifndef AUDIOFILE_H
#define AUDIOFILE_H
#include <string>
#include "SFML/Audio.hpp"

using namespace std; 

class AudioFile
{
private:
	bool m_sound;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;

public:
	AudioFile(string, Sound);
	void Play();
	void Stop();
	~AudioFile();
};

#endif