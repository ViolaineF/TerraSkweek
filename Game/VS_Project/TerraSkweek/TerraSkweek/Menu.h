#include "Grid.h"

class Menu
{
protected:
	Grid lvl01{ "2corrupted" };

private:
	vector<GLuint>	UI;


public:
	Grid lvl01{ "2corrupted" };
	void LoadAllTextures();
	int LoadGLTextures(string name);

	Menu();
	~Menu();
};

