#ifndef MOBSPAWNER_H
#define MOBSPAWNER_H

#include "SpecialCase.h"

class MobSpawner : public SpecialCase
{
public:
	bool Draw();
	MobSpawner(float, float, string);
	~MobSpawner();
};

#endif