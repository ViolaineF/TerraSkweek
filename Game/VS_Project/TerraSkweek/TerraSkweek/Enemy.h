#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
protected :
	bool afraid;
	int m_damage;
	int currentFrame;
	vector<GLuint>	run;

public:
	Enemy();
	int LoadGLTextures(string, string);
	void Move(Position);
	void Draw();
	~Enemy();
};

#endif


