#include "Grid.h"

class Menu
{
protected:
	//Grid lvl{ "2corrupted" };

private:
	vector<GLuint>	UI;
	vector<GLuint>	button;
	

public:
	void LoadAllTextures();
	int LoadGLTextures(string, string);
	void Display();
	Menu();
	~Menu();
};

