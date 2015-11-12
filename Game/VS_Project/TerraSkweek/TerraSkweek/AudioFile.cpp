
#include "AudioFile.h"



AudioFile::AudioFile()
{
}

AudioFile::AudioFile(string file, bool sound)
{
	m_sound = sound;
	
	if (sound) {// if it's a sound
		buffer.loadFromFile("sfx/" + file);
	}
	else {// if it's a background music
		music.openFromFile("bgm/" + file);
	}
}

//void AudioFile::SetAudioFile(AudioFile a)
//{
//	m_sound = a.m_sound;
//	buffer = a.buffer;
//	sound = a.sound;
//	music = a.music;
//}


void AudioFile::PlayAudio()
{
	if (m_sound) { // if it's a sound

		sound.setVolume(22);
		sound.setBuffer(buffer);

		if (!sound.Stopped)
		{
			sound.play();
		}
	}
	else { // if it's a background music
		sound.setVolume(6);

		music.play();
		music.setLoop(true);
	}
}

void AudioFile::StopAudio()
{
	music.stop();
}

//bool AudioFile::operator=(const AudioFile & a)
//{
//	return false;
//}



