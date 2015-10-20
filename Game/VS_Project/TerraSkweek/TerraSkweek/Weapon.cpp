#include "Weapon.h"



bool operator==(const position &a, const position &b)
{

	return (a.x == b.x && a.y==b.y && a.z==b.z);
}
bool operator!=(const position &a, const position &b)
{
	return !(a==b);
}

Weapon::Weapon()
{
}

void Weapon::DrawSprite(position)
{
}

void Weapon::DrawFire()
{
}


Weapon::~Weapon()
{
}
