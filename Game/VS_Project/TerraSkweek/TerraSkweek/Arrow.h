#include "Weapon.h"

class Arrow : public Weapon
{

protected:
	bool activated;
	int frameActuelle;
	char direction;
	
public:
	void Draw();
	void activation();
	Arrow();
	Arrow(int, int, bool, char);
	void LoadAllTextures();
	~Arrow();
};