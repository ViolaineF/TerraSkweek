#ifndef SLIMEFOREST_H
#define SLIMEFOREST_H

#include "Enemy.h"

class Slime_Forest : public Enemy
{
public:
	Slime_Forest(Position);
	void LoadAllTextures();
	~Slime_Forest();
};

#endif
