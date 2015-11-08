#ifndef UPCASE_H
#define UPCASE_H

#include "SpecialCase.h"

class UpCase : public SpecialCase
{
private : 
	bool m_converted;
public:
	bool Draw();
	UpCase(float, float, string);
	~UpCase();
};

#endif