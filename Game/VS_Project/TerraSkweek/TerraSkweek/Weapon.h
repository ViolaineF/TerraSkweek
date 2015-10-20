#ifndef WEAPON_H
#define WEAPON_H


#include <string>
#include <vector>
#include "GL\glut.h"
#include "SOIL\SOIL.h"
#include "AudioFile.h"


struct position
{
	int x, y;
	bool z;
};

bool operator==(const position &a, const position &b);
bool operator!=(const position &a, const position &b);

class Weapon
{
private:
	position m_posSprite;
	//Texture m_sprites;
	int m_damage;
	int m_speed;
	int m_type;
	AudioFile s_fire;
	AudioFile s_impact;
	std::vector<GLuint>	textures;

public:
	Weapon();
	void DrawSprite(position);
	void DrawFire();
	int LoadGLTextures(string);
	~Weapon();
};


#endif
