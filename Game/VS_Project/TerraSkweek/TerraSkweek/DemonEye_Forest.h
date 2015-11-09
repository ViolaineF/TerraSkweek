#ifndef DEMONEYEFOREST_H
#define DEMONEYEFOREST_H

#include "Enemy.h"

class DemonEye_Forest : public Enemy
{
public:
	void LoadAllTextures();
	DemonEye_Forest(Position);
	~DemonEye_Forest();
};

#endif
