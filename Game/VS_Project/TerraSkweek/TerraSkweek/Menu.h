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
	Button b_newGame{ 5.93 };
	Button b_loadGame{ 6.66 };
	Button b_continue{ 5.53 };
	Button b_quit{ 2.32 };

	Button b_jungle{ 1};
	Button b_corruption{ 1 };
	Button b_crimson{ 1 };
	Button b_hallow{ 1 };
	Position p_prev_pos;

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

