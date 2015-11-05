#include "Button.h"
#include "Grid.h"

class Menu
{
protected:
//	bool inGame;

private:
	vector<GLuint> UI;
	int screenID;
	bool click;
	Button b_newGame{ "new_game", 5.93 };
	Button b_loadGame{ "load_game", 6.66 };
	Button b_jungle{ "new_game", 1};
	Button b_corruption{ "corruption", 1 };
	Button b_crimson{ "crimson", 1 };
	Button b_hallow{ "hallow", 1 };

public:
	void LoadAllTextures();
	int LoadGLTextures(string, string);
	void Display();
	void PrintImg(float, float, float, float, vector<GLuint>, int);
	void Clicking();
	void Pause();
	Menu();
	~Menu();
};

