#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
protected :
	bool afraid;
	vector<GLuint>	run;

public:
	Enemy();
	int LoadGLTextures(/*string,*/ string);
	void Draw();
	~Enemy();
};

#endif


