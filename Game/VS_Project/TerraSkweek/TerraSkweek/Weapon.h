#include "AudioFile.h"
#include "Texture.h"

struct position
{
	int x, y;
	bool z;
};

bool operator==(const position &a, const position &b);
bool operator!=(const position &a, const position &b);

class Weapon
{
private:
	position m_posSprite;
	Texture m_sprites;
	int m_damage;
	int m_speed;
	int m_type;
	AudioFile s_fire;
	AudioFile s_impact;

public:
	Weapon();
	void DrawSprite(position);
	void DrawFire();
	~Weapon();
};

