#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"


class Player : public Entity
{
private : 
	//string m_name;
	vector<GLuint>	idle;
	vector<GLuint>	left;
	vector<GLuint>	up;
	vector<GLuint>	down;
	vector<GLuint>	fire;
	bool m_moving;
	float opacity;

public:
	void setOpacity(float);
	void LoadAllTextures();
	int LoadGLTextures(string, string);
	void Draw();
	void SetMoving(bool);
	bool IsMoving();

	Player();
	~Player();
};

#endif