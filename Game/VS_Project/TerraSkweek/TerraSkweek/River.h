#include "Weapon.h"

class River : public Weapon
{

protected:
	bool activated;
	int frameActuelle;
	char direction;
	char biome;
	
public:
	void Draw();
	void activation();
	River();
	River(int, int, bool, char, char);
	void LoadAllTextures();
	~River();
};