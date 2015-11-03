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
	Arrow(float, float, bool, char);
	void LoadAllTextures();
	~Arrow();
};