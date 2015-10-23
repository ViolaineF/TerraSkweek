#ifndef WEAPON_H
#define WEAPON_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string>
#include <vector>
#include "GL\glut.h"
#include "SOIL\SOIL.h"
#include "AudioFile.h"


struct Position
{
	float x, y;
	bool z;
};

bool operator==(const Position &a, const Position &b);
bool operator!=(const Position &a, const Position &b);

class Weapon
{
private:
	Position m_posSprite;
	Position m_pos;
	char m_dir;
	int m_damage;
	float m_speed;
	int m_type;
	AudioFile s_fire;
	AudioFile s_impact;
	std::vector<GLuint>	textures;

public:
	Weapon();
	Weapon(string, char, Position);
	void MoveFire();
	void DrawSprite(Position);
	void DrawFire();
	int LoadGLTextures(string);
	~Weapon();
};


#endif
