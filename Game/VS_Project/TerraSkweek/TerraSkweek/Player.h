#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"


class Player : public Entity
{
public:
	void Draw();
	Player();
	~Player();
};

#endif