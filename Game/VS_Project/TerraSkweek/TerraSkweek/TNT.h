#include "Weapon.h"

class TNT : public Weapon
{

protected:
	bool activated;
	bool exploded;
	bool endTNT;
	int frameActuelle;

public:
	void Draw();
	bool checkExp();
	void activation();
	TNT();
	TNT(int, int, bool);
	void LoadAllTextures();
	~TNT();
};