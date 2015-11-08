#ifndef SEMICONVERTED_H
#define SEMICONVERTED_H

#include "SpecialCase.h"

class SemiConverted : public SpecialCase
{
public:
	bool Draw();
	SemiConverted(float, float, string);
	~SemiConverted();
};

#endif