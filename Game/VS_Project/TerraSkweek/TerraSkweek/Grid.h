#include "Player.h"
#include "Enemy.h"

class Grid
{
private:
	int m_screen;
	int m_selected;
	int m_score;
	int m_timer;

public:
	void SaveGame();
	void LoadGame();
	void NewGame();
	void DisplayMap();
	void HUD();
	void Slide(int);
	void Pause();
	void EndGame();
	Grid();
	~Grid();
};

