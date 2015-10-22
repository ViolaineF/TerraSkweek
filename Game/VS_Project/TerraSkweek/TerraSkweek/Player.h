#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"


class Player : public Entity
{
private : 
	vector<GLuint>	idle;
	vector<GLuint>	left;
	vector<GLuint>	up;
	vector<GLuint>	down;
	vector<GLuint>	fire;

public:
	void LoadAllTextures();
	int LoadGLTextures(string, string);
	void Draw();
	Player();
	~Player();
};

#endif