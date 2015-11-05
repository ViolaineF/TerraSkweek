#ifndef MOBSPAWNER_H
#define MOBSPAWNER_H

#include "SpecialCase.h"

class MobSpawner : public SpecialCase
{
public:
	bool Draw();
	MobSpawner(int, int, string);
	~MobSpawner();
};

#endif