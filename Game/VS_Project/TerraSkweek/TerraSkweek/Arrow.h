#include "Weapon.h"

class Arrow : public Weapon
{

protected:
	bool activated;
	char direction;
	//vector<GLuint>	arrow;
	
public:
	void Draw();
	void activation();
	Arrow();
	Arrow(float, float, bool, char);
	void LoadAllTextures();
	~Arrow();
};