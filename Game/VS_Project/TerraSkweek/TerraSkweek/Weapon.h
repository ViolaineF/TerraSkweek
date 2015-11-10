#ifndef WEAPON_H
#define WEAPON_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
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
protected:
	//Position m_posSprite;
	Position m_pos;
	char m_dir;
	int m_damage;
	float m_speed;
	int m_type;
	bool m_impact;
	bool m_destroy;
	int currentFrame;
	bool m_drop; 
	float m_spriteSize;


	vector<GLuint>	fireAnimation;
	vector<GLuint>	gun;
	vector<GLuint>	freeze;
	vector<GLuint>	invincible;
	vector<GLuint>	tnt;
	vector<GLuint>	arrow;
	
public:
	Weapon();
	Weapon(Position, bool, int);
	Weapon(int, char, Position);

	bool MoveFire();
	//void DrawSprite(Position);
	void DrawFire();

	Position GetPos();
	int GetDamage();
	char GetDir();
	int GetType();
	void SetType(int);

	void SetCurrentFrame(int);
	void SetImpact(bool);
	bool IsDestroyed();

	void LoadAllTextures();
	int LoadGLTextures(string, string);
	~Weapon();
};


#endif
