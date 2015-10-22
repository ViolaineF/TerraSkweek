#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private :
	bool afraid;
	int m_damage;
	int currentFrame;
	vector<GLuint>	run;

public:
	Enemy();
	int LoadGLTextures(string, string);
	//void Move(Player);
	void Move(Position);
	void Draw();
	~Enemy();
};

#endif


