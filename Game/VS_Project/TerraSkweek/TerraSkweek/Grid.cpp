#include "Grid.h"

//-------------- CALL EXTERN VALUES
extern bool inGame;
extern int screenID;
extern const int TextWidth;
extern Player player;
extern float light;
string m_biome;
extern const Position playerInitPos;
extern const Position playerMenuPos;

int mapMenu[20][20] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

int mapLv1[20][20] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

int mapLv2[20][20] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

int mapLv3[20][20] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

int mapLv4[20][20] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

Grid::Grid(string biome)
{
	m_biome = biome;
	m_score = 0;
	m_rows = 20;
	m_lignes = 20;
	m_spawnerIndex = 0;
	vecSpawner.resize(0);

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			map[i][j] = mapMenu[i][j];
		}
	}

	bgm_menu.PlayAudio();

}

void Grid::SetMap(int x, int y, int a)
{
	map[x][y] = a;

	if (a == 4)
		vecCaseAnimated.push_back(new SimpleConversion(x*TextWidth, y*TextWidth, "conversion"));

}

void Grid::ClearMap()
{
	cout << "map cleared";
	vecCaseAnimated.clear();
	vecSpawner.clear();
	vecEnemies.clear();
	vecTNT.clear();
	vecArrow.clear();
	vecWeapons.clear();
}

void Grid::ChangeMap(int choice)
{
	cout << "lvl = " << choice << endl;
	
	switch (choice)
	{
	case 0:// Menu
		bgm_menu.PlayAudio();

		m_biome = "0menu";
		m_maxMobs = 0;
		LoadAllTextures();

		player.Teleport(playerMenuPos);

		m_rows = 20;
		m_lignes = 20;

		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_lignes; j++) {
				map[i][j] = mapMenu[i][j];
			}
		}


		break;

	case 1:// Forest
		bgm_menu.StopAudio();

		m_biome = "1forest";

		m_maxMobs = 10;

		LoadAllTextures();

		player.Teleport(playerInitPos);

		m_rows = 20 ;
		m_lignes = 20;
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_lignes; j++) {
				map[i][j] = mapLv1[i][j];
			}
		}

		LoadObjectsOnMap();

		break;

	case 2:// corruption		
		bgm_menu.StopAudio();

		m_biome = "2corruption";

		m_maxMobs = 15;

		vecTNT.push_back(new TNT(3, 3, 1));
		vecArrow.push_back(new Arrow(7, 7, 1, 'l'));
		vecArrow.push_back(new Arrow(7, 6, 1, 'r'));
		vecArrow.push_back(new Arrow(8, 5, 1, 'd'));
		vecArrow.push_back(new Arrow(8, 4, 1, 'd'));

		LoadAllTextures();

		player.Teleport(playerInitPos);

		m_rows = 20;
		m_lignes = 20;
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_lignes; j++) {
				map[i][j] = mapLv2[i][j];
			}
		}

		LoadObjectsOnMap();

		break;

	case 3:// Crimson
		bgm_menu.StopAudio();

		m_biome = "3crimson";
		
		m_maxMobs = 20;

		LoadAllTextures();

		player.Teleport(playerInitPos);

		m_rows = 20;
		m_lignes = 20;
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_lignes; j++) {
				map[i][j] = mapLv3[i][j];
			}
		}

		LoadObjectsOnMap();

		break;

	case 4:// Hallow
		bgm_menu.StopAudio();

		m_biome = "4hallow";
		LoadAllTextures();

		m_maxMobs = 25;

		player.Teleport(playerInitPos);

		m_rows = 20;
		m_lignes = 20;
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_lignes; j++) {
				map[i][j] = mapLv4[i][j];
			}
		}

		LoadObjectsOnMap();

		break;
	}

	cout <<"avant load texture "<< m_biome << endl;

}

void Grid::LoadObjectsOnMap()
{

	//------------------------LOAD SEMI-CONVERTED CASE 
	//------------------------LOAD CRACKED FLOOR
	//------------------------LOAD MOB SPAWNER
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			if (map[i][j] != 1) { // Avoid spwaning in a wall
				int chance = rand() % 100 + 1; // Give an int between 1 and 100;

				if (chance >= 1 && chance <= 5) { //5% chance ---------------------------------SEMI CONVERTED FLOOR
					map[i][j] = 3;
					vecCaseAnimated.push_back(new SemiConverted(i*TextWidth, j*TextWidth, "semiConverted"));
				}

				if (chance > 5 && chance <= 10) { // 5% chance ---------------------------------CRACKED FLOOR
					map[i][j] = 5;
					vecCaseAnimated.push_back(new CrackedFloor(i*TextWidth, j*TextWidth, "cracking"));
				}

				if (chance > 10 && chance <= 11) { // 1% chance ---------------------------------MOB SPAWNER
					vecSpawner.push_back(new MobSpawner(i*TextWidth, j*TextWidth, "mobSpawner"));
				}
			}
		}
	}


	//------------------------ LOAD UP CASE 
	vecUpCase.push_back(new UpCase(5 * TextWidth, 5 * TextWidth, "upcase"));
	vecUpCase.push_back(new UpCase(5 * TextWidth, 6 * TextWidth, "upcase"));
	vecUpCase.push_back(new UpCase(6 * TextWidth, 5 * TextWidth, "upcase"));
	vecUpCase.push_back(new UpCase(6 * TextWidth, 6 * TextWidth, "upcase"));

	//---------- LOAD JUMP CASE ACCORDINGLY 
	vecCaseAnimated.push_back(new SpecialCase({ 4.5f * TextWidth, 5.0f * TextWidth , 0 }, "elevator.png"));
	vecCaseAnimated.push_back(new SpecialCase({ 4.5f * TextWidth, 6.0f * TextWidth , 0 }, "elevator.png"));

	//-----------------LOAD ARROWS
	vecArrow.push_back(new Arrow(400, 400, 0, 'l'));
	vecArrow.push_back(new Arrow(400, 475, 0, 'r'));
	vecArrow.push_back(new Arrow(550, 400, 0, 'u'));
	vecArrow.push_back(new Arrow(625, 400, 0, 'd'));

}

void Grid::LoadAllTextures()
{
	string directory = "Art/" + m_biome + "/";
	
	textures.resize(0);

	//--------------BASE TEXTURES
	LoadGLTextures( directory + "ground.png"); // 0
	LoadGLTextures( "Art/wall01.png"); // 1
	LoadGLTextures( "Art/converted.png"); // 2
	LoadGLTextures( "Art/semi_converted.png"); // 3
	LoadGLTextures( "Art/fall.png"); // 4


	//-------------------LOAD TEXTURES

	for (TNT* d : vecTNT)
	{
		d->LoadAllTextures();
	}

	for (Arrow* e : vecArrow)
	{
		e->LoadAllTextures();
	}

}

int Grid::LoadGLTextures(string name)
{
	//-------------BASE TEXTURES

		GLuint essai = SOIL_load_OGL_texture
			(
				name.c_str(),
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

		textures.push_back(essai); // Add to the texture vector

		if (textures.at(textures.size() - 1) == 0)
			return false;

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return true;       // Return Success
	
}

int Grid::Map(int x, int y)
{
	return map[x][y];
}

void Grid::SaveGame(string save)
{
	//--------------------------Ouvrir le fichier en écriture | supprimer ce qui est dedans avant d'ecrire
	ofstream fichier("Saves" + save, ios::out | ios::trunc);

	if (fichier)//-------------------Si le fichier existe, écrire
	{
		//---------------------------- WRITE THE DIMENSION OF THE MAP 
		fichier << m_rows << '#' << m_lignes << '#';

		//---------------------------- WRITE THE MAP
		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_lignes; j++) {
				fichier << map[i][j] << '#';
			}
		}

		//--------------------------- WRITE SCORE
		fichier << m_score << '#'; 


		fichier.close(); //--------------------Fermer fichier
	}
	//------------------Sinon erreur
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void Grid::LoadGame(string save)
{
	m_rows = 0;
	m_lignes = 0;

	//--------------------------Ouvrir le fichier en lecture
	ifstream fichier("Saves/" + save, ios::in);

	if (fichier)//-------------------Si le fichier existe, lire
	{	string extract;
		int i = 0;
		int j = 0;

		//------------------WHILE THERE IS DATA
		while (getline(fichier, extract, '#')) {

			//cout << extract << "#";
			int extractInt = 0;
			extractInt = stol(extract); // convert string into int
			//cout << extractInt << '#';

			//--------------- EXTRACT ROWS AND LIGNES
			if (m_rows == 0) { // if m_rows has not been extracted yet
				m_rows = extractInt;
				//cout << m_rows << endl;
			}
			else if (m_lignes == 0) { // if m_lignes has not been extracted yet
				m_lignes = extractInt;
				//cout << m_lignes << endl;
			}
			else if (i < m_rows) {
				//--------------- LOOP FOR THE MAP
				if (j < m_lignes){
						map[i][j] = extractInt;
						//cout << map[i][j];
						j++;
				}
				if (j == m_lignes) {
					j = 0;
					i++;
				}
			}
			else
			{ //-------------------- GET SCORE
				m_score = extractInt;
				//cout << endl << m_score << endl;
			}

			//------------------EXTRACT NEW DATA
			//getline(fichier, extract, '#');


		}//----------------------FIN WHILE DATA

		fichier.close(); //--------------------Fermer fichier


	}

	//------------------Sinon erreur
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;



}

void Grid::NewGame(string save)
{

}


//------------------------------------- PRINT IMAGES TO SCREEN
void Grid::PrintImg(float i, float j, float width, float height, int textureIt)
{
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, textures[textureIt]);
	glBegin(GL_QUADS);

	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i - height / 2, j - width / 2);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i + height / 2, j - width / 2);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i + height / 2, j + width / 2);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i - height/2, j + width/2);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//------------------------------------- DRAW MAP
void Grid::DisplayMap()
{
	//cout << player.GetPos().x << " , " << player.GetPos().y << " , " << player.GetPos().z << endl;
	
	m_tiles = 0;
	int m_rowsText = 20 * TextWidth;
	int m_lignesText = 20 * TextWidth;

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			switch (map[i][j])
			{
			case 0:// Floor
				PrintImg(i*TextWidth, j*TextWidth, TextWidth+1, TextWidth+1, 0);
				m_tiles++;
				break;
			case 1:// Wall
				PrintImg(i * TextWidth, j * TextWidth, TextWidth+1, TextWidth+1, 1);
				break;

			case 2:// Converted Floor
				PrintImg(i * TextWidth, j * TextWidth, TextWidth + 1, TextWidth + 1, 2);
				break;	

			case 3: // Semi-Converted animation
				PrintImg(i * TextWidth, j * TextWidth, TextWidth + 1, TextWidth + 1, 0); // Corrupted floor
				break;

			case 4 : // Conversion animation
				PrintImg(i * TextWidth, j * TextWidth, TextWidth + 1, TextWidth + 1, 0); // Corrupted floor
				break;

			case 5: // Cracked floor
				PrintImg(i * TextWidth, j * TextWidth, TextWidth + 1, TextWidth + 1, 0); // Corrupted floor
				break;

			case 6: // Fall
				PrintImg(i * TextWidth, j * TextWidth, TextWidth + 1, TextWidth + 1, 4); // Corrupted floor
				break;
			}
		}
	}// End drawing
	if (m_tiles == 0)
	{
		inGame = false;
		screenID = 5;
	}


	if (player.GetLife() <= 0)
	{
		inGame = false;
		screenID = 6;
	}

}

void Grid::DrawSpecialCases()
{
	for (unsigned int i = 0; i < vecCaseAnimated.size(); i++) {

		if (vecCaseAnimated[i]->Draw()) {// If the animation is complete ...

			if (typeid(*vecCaseAnimated[i]) == typeid(SimpleConversion)) {
				SetMap(vecCaseAnimated[i]->GetPos().x/TextWidth, vecCaseAnimated[i]->GetPos().y/TextWidth, 2); // ... Convert floor
				m_score = m_score + 1;	// SCORE + converted tile
			}

			if (typeid(*vecCaseAnimated[i]) == typeid(CrackedFloor)) {
				SetMap(vecCaseAnimated[i]->GetPos().x/TextWidth, vecCaseAnimated[i]->GetPos().y/TextWidth, 6); // ... Convert floor
				m_score = m_score + 1;	// SCORE + converted tile
			}

			//if (typeid(*vecCaseAnimated[i]) == typeid(SemiConverted)) {
			//	SetMap(vecCaseAnimated[i]->GetPos().x, vecCaseAnimated[i]->GetPos().y, 2); // ... Convert floor
			//}			

			vecCaseAnimated.erase(vecCaseAnimated.begin() + i);// Destroy it
			i--;
		}
		else if (vecCaseAnimated[i]->GetPos() == player.GetPos()) {

			if (typeid(*vecCaseAnimated[i]) == typeid(CrackedFloor) && light>1) { //------------- PLAYER IS ON CRACKED FLOOR
				vecCaseAnimated[i]->SetAnimated(true);
				//------------------PLAY SOUND
				sfx_gap.PlayAudio();
			}

			else if (typeid(*vecCaseAnimated[i]) == typeid(SemiConverted) && light >1) { //--------------- PLAYER IS ON SEMI CONVERTED CASE
				vecCaseAnimated[i]->SetAnimated(true);
			}


			else if (vecCaseAnimated[i]->GetType() == 'p') {  //---------------- PLAYER IS ON POWDER BAG
				player.SetPowderBag(true); // Change player powder bag boolean
				vecCaseAnimated.erase(vecCaseAnimated.begin() + i); // Destroy powder bag sprite
				i--;
				//------------------PLAY SOUND

			}

			else if (vecCaseAnimated[i]->GetType() == 'f') { //---------------- PLAYER IS ON FREEZE POWER
				for (unsigned int i = 0; i < vecEnemies.size(); i++){
					vecEnemies[i]->SetFreeze(true);
				}
				vecCaseAnimated.erase(vecCaseAnimated.begin() + i); 
				i--;
				//------------------PLAY SOUND

			}

			else if (vecCaseAnimated[i]->GetType() == 'i') { //---------------- PLAYER IS ON INVINCIBLE POWER
				player.SetInvincible(true); 
				vecCaseAnimated.erase(vecCaseAnimated.begin() + i);
				i--;
				//------------------PLAY SOUND

			}

			else if (vecCaseAnimated[i]->GetType() == 'e') { //---------------- PLAYER IS ON ELEVATOR CASE
				player.Teleport({player.GetPos().x + 0.1f, player.GetPos().y, 1});
				//------------------PLAY SOUND

			}

		}
		
	}

	for (unsigned int i = 0; i < vecSpawner.size(); i++) {
		vecSpawner[i]->Draw();
	}

	for (unsigned int i = 0; i < vecUpCase.size(); i++) {
		vecUpCase[i]->Draw();
		if (vecUpCase[i]->GetPos() == player.GetPos()) { //--------------- PLAYER IS ON UP CASE NON CONVERTED
			vecUpCase[i]->SetAnimated(true);
			//------------------PLAY SOUND
		}
	}

		///////////////////////////////////////////////////////////////////////////
	
	for (unsigned int i = 0; i < vecArrow.size(); i++) 
	{
		vecArrow[i]->Draw();

		if (vecArrow[i]->GetPos() == player.GetPos())
		{
			vecArrow[i]->activation(true); // Player's movement forced in the direction of the Arrow

			Position Player_pos = player.GetPos();

			if (vecArrow[i]->GetDir() == 'r')
			{
				Player_pos.x = Player_pos.x + 100;
				player.Teleport(Player_pos);
			}

			if (vecArrow[i]->GetDir() == 'l')
			{
				Player_pos.x = Player_pos.x - 100;
				player.Teleport(Player_pos);
			}
			if (vecArrow[i]->GetDir() == 'u')
			{
				Player_pos.y = Player_pos.y - 100;
				player.Teleport(Player_pos);
			}
			if (vecArrow[i]->GetDir() == 'd')
			{
				Player_pos.y = Player_pos.y + 100;
				player.Teleport(Player_pos);
			}

		}
	}


}

void Grid::DrawUpCase()
{
	bool playerOnUpCase = false; 

	for (unsigned int i = 0; i < vecUpCase.size(); i++) {
		if (typeid(*vecUpCase[i]) == typeid(UpCase)) {
			vecUpCase[i]->Draw();

			//if (player.GetPos() == vecUpCase[i]->GetPos()) { // If the player is on a case, then bool is true;
			//	playerOnUpCase = true;
			//}

			if (player.GetPos().x >= vecUpCase[i]->GetPos().x - (TextWidth / 2) - 2 && player.GetPos().x <= vecUpCase[i]->GetPos().x+(TextWidth/2)+2
				&& player.GetPos().y >= vecUpCase[i]->GetPos().y - (TextWidth / 2) - 2 && player.GetPos().y <= vecUpCase[i]->GetPos().y + (TextWidth / 2) + 2
				&& player.GetPos().z == vecUpCase[i]->GetPos().z) { // If the player is on a case, then bool is true;
				playerOnUpCase = true;
			}
		}
	}

	//--------------CHECK IF PLAYER IS STILL ON AT LEAST 1 UPCASE
	if (!playerOnUpCase) {
			player.Teleport({player.GetPos().x,player.GetPos().y, 0 }); // Put the player down
	}

}

void Grid::DrawEnemies()
{
	//--------------- DELETE ALL DEAD ENEMIES
	for (unsigned int i = 0; i < vecEnemies.size(); i++) {
		if (vecEnemies[i]->IsDead()) { // If the Enemy has played its death animation entirely
			
			// SCORE + frags
			m_score = m_score + 100;

			//------------------PLAY SOUND
			sfx_e_death.PlayAudio();

			//------------------DROPS LOOT ON DEATH

			if (typeid(*vecEnemies[i]) == typeid(Slime_Forest)) { // Slime forest Enemy - drops stats
				
				// --------------- CHANCES OF DROP
				int tier1 = 5; // 10% for the first weapon
				int tier2 = 15; // second weapon
				int tier3 = 20; // third weapon
				int tier4 = 20; // Powder Bag
				int tier5 = 20; // Freeze power
				int tier6 = 20; // Invincible power

				int dropType = rand() % 100 + 1; // Give an int between 1 and 100;

				if (dropType >= 1 && dropType <= tier1) { // 10% chance to drop weapon 1
					vecWeapons.push_back(new Weapon(vecEnemies[i]->GetPos(), true, 1));// Create new weapon sprite
				}
				else if (dropType > tier1 && dropType <= tier1+tier2) { 
					vecWeapons.push_back(new Weapon(vecEnemies[i]->GetPos(), true, 2));
				}
				else if (dropType > tier1+tier2 && dropType <= (tier1 + tier2+tier3)) { 
					vecWeapons.push_back(new Weapon(vecEnemies[i]->GetPos(), true, 3));
				}
				else if (dropType > (tier1 + tier2 + tier3) && dropType <= (tier1 + tier2 + tier3 +tier4)) { 
					vecCaseAnimated.push_back(new SpecialCase(vecEnemies[i]->GetPos(), "powderBag.png"));
				}
				else if (dropType >  (tier1 + tier2 + tier3 + tier4) && dropType <= (tier1 + tier2 + tier3 + tier4+tier5)) {
					vecCaseAnimated.push_back(new SpecialCase(vecEnemies[i]->GetPos(), "freezePower.png"));
				}
				else if (dropType > (tier1 + tier2 + tier3 + tier4 + tier5) && dropType <= (tier1 + tier2 + tier3 + tier4 + tier5+tier6)) { 
					vecCaseAnimated.push_back(new SpecialCase(vecEnemies[i]->GetPos(), "invinciblePower.png"));
				}
							
			}
			
			vecEnemies.erase(vecEnemies.begin() + i);// Destroy enemy
			i--;
		}
	}

	//--------------- DRAW THE REMAINING ONES
	for (unsigned int i = 0; i < vecEnemies.size(); i++) {
		vecEnemies[i]->Draw(); // if the player has freeezed the enemies, they are draw accordingly
	}
}


void Grid::MoveAllEnemies()
{
	//for (unsigned int i = 0; i < vecTNT.size(); i++)
	//{
	//	if (vecTNT[i]->GetPos() == player.GetPos()) {
	//		vecTNT[i]->activation(); // TNT is activated
	//	}
	//}

	//for (unsigned int i = 0; i < vecArrow.size(); i++)
	//{
	//	if (vecArrow[i]->GetPos() == player.GetPos()) {
	//		vecArrow[i]->activation(); // arrow force is activated
	//	}
	//}

	for (unsigned int i = 0; i < vecEnemies.size(); i++) {

		if (vecEnemies[i]->IsFreezed()) { // if the enemies are freezed, return to skip the enemy movement
			return;
		}

		// Save previous position if it collides with a wall
		Position prevPos = { vecEnemies[i]->GetPos().x , vecEnemies[i]->GetPos().y , vecEnemies[i]->GetPos().z };

		//--------------------- MOVING ENEMIES
		if (vecEnemies[i]->Move(player.GetPos(), light)) { // If the enemy is moving, then move it and check, else check nothing
														  
		    //---------- CHECK COLLISION WITH PLAYER - 1 player
			if (vecEnemies[i]->GetPos() == player.GetPos() && player.IsInvincible() == false) {
				player.SetLife(player.GetLife() - vecEnemies[i]->GetDamage()); // Player's life is minus by the enemy's contact damage
				player.Teleport(playerInitPos); // Teleport the player at his starting point
				sfx_hit.PlayAudio();
			}

			//----------- CHECK WALL COLLISION
			//int pXleft = round(vecEnemies[i]->GetPos().x - 0.4);
			//int pXright = round(vecEnemies[i]->GetPos().x + 0.4);
			//int pYup = round(vecEnemies[i]->GetPos().y - 0.4);
			//int pYdown = round(vecEnemies[i]->GetPos().y + 0.4);

			int margin = 20;

			int pXleft = round((vecEnemies[i]->GetPos().x - margin) / TextWidth);
			int pXright = round((vecEnemies[i]->GetPos().x + margin) / TextWidth);
			int pYup = round((vecEnemies[i]->GetPos().y - margin) / TextWidth);
			int pYdown = round((vecEnemies[i]->GetPos().y + margin) / TextWidth);

			switch (vecEnemies[i]->GetDir()) // Check wall depends on direction
			{ 
			case 'u':
				if ((map[pXleft][pYup] == 1) || (map[pXright][pYup] == 1)) { // Check upward
					vecEnemies[i]->Teleport(prevPos);
				}
				break;

			case 'd':
				if ((map[pXleft][pYdown] == 1) || (map[pXright][pYdown] == 1)) { // Check downward
					vecEnemies[i]->Teleport(prevPos);
				}
				break;

			case 'r':
				if ((map[pXright][pYdown] == 1) || (map[pXright][pYup] == 1)) { // Check the right side
					vecEnemies[i]->Teleport(prevPos);
				}
				break;

			case 'l':
				if ((map[pXleft][pYup] == 1) || (map[pXleft][pYdown] == 1)) { // Check the left side
					vecEnemies[i]->Teleport(prevPos);
				}
				break;
			}

		}

	}

}

void Grid::SpawnMob()
{	
	if (vecEnemies.size() > m_maxMobs) { // If too many mobs, don't spawn any
		return;
	}

	if (m_spawnerIndex >= vecSpawner.size()-1) {
		m_spawnerIndex = 0;
	}
	else {
		m_spawnerIndex++;
	}

	vecSpawner[m_spawnerIndex]->SetAnimated(true); // Animate the spawner
	
	//------------------------LOAD CORRESPONDING BIOME'S ENEMIES 
	int enemyGrade = rand() % 100 + 1; // Give an int between 1 and 100;;

	char biomeChar = m_biome[0];

	switch (biomeChar)
	{
	case '1': // Forest
		if (enemyGrade >= 1 && enemyGrade <= 60) { // 60%
			vecEnemies.push_back(new Slime_Forest(vecSpawner[m_spawnerIndex]->GetPos())); // Add an enemy
		}
		else  { // 40%
			vecEnemies.push_back(new DemonEye_Forest(vecSpawner[m_spawnerIndex]->GetPos()));
		}
		break;

	case '2': // Corruption
		if (enemyGrade >= 1 && enemyGrade <= 60) { // 60%
			vecEnemies.push_back(new Slime_Forest(vecSpawner[m_spawnerIndex]->GetPos())); // Add an enemy
		}
		else { // 40%
			vecEnemies.push_back(new DemonEye_Forest(vecSpawner[m_spawnerIndex]->GetPos()));
		}
		break;

	case '3': // Crimson
		if (enemyGrade >= 1 && enemyGrade <= 60) { // 60%
			vecEnemies.push_back(new Slime_Forest(vecSpawner[m_spawnerIndex]->GetPos())); // Add an enemy
		}
		else  { // 40%
			vecEnemies.push_back(new DemonEye_Forest(vecSpawner[m_spawnerIndex]->GetPos()));
		}
		break;

	case '4': // Hallow
		if (enemyGrade >= 1 && enemyGrade <= 60) { // 60%
			vecEnemies.push_back(new Slime_Forest(vecSpawner[m_spawnerIndex]->GetPos())); // Add an enemy
		}
		else{ // 40%
			vecEnemies.push_back(new DemonEye_Forest(vecSpawner[m_spawnerIndex]->GetPos()));
		}
		break;
	}


	//------------------PLAY SOUND
	//sfx_gap.PlayAudio();

}

void Grid::SetEnemiesSpeed(float a)
{
	for (unsigned int i = 0; i < vecEnemies.size(); i++) {		
		vecEnemies[i]->SetSpeed(a);
	}
}

void Grid::NewFire(int type, char dir, Position pos)
{	
	switch (type)
	{
	case 1 : // Simple fire
		vecWeapons.push_back(new Weapon(type, dir, pos));
		//------------------PLAY SOUND
		sfx_e_fire.PlayAudio();
		break;

	case 2: // Cross fire
		vecWeapons.push_back(new Weapon(type, 'u', pos));
		vecWeapons.push_back(new Weapon(type, 'd', pos));
		vecWeapons.push_back(new Weapon(type, 'r', pos));
		vecWeapons.push_back(new Weapon(type, 'l', pos));
		//------------------PLAY SOUND
		sfx_e_fire.PlayAudio();
		break;

	case 3: // Diag fire
		vecWeapons.push_back(new Weapon(type, '1', pos));
		vecWeapons.push_back(new Weapon(type, '2', pos));
		vecWeapons.push_back(new Weapon(type, '3', pos));
		vecWeapons.push_back(new Weapon(type, '4', pos));
		//------------------PLAY SOUND
		sfx_e_fire.PlayAudio();
		break;
	}

}

void Grid::MoveAllFires()
{
	for (unsigned int i = 0; i < vecWeapons.size(); i++) {
		if (vecWeapons[i]->MoveFire()) // Move the fire sprite, if it's not moving then don't check the following
		{
			//---------- CHECK COLLISION WITH ENEMIES
			for (unsigned int j = 0; j < vecEnemies.size(); j++) {
				if (vecWeapons[i]->GetPos() == vecEnemies[j]->GetPos()) {
					vecEnemies[j]->SetLife(vecEnemies[j]->GetLife() - vecWeapons[i]->GetDamage()); // Minus Enemy's life by the fire's damage
					vecWeapons[i]->SetImpact(1); // Stop the sprite ...
					return; // No need to check walls
				}
			}

			//----------- CHECK WALL COLLISION
			int pXleft = round(vecWeapons[i]->GetPos().x / TextWidth - 0.5);
			int pXright = round(vecWeapons[i]->GetPos().x / TextWidth + 0.5);
			int pYup = round(vecWeapons[i]->GetPos().y / TextWidth - 0.5);
			int pYdown = round(vecWeapons[i]->GetPos().y / TextWidth + 0.5);

			switch (vecWeapons[i]->GetDir())
			{
			case 'u':
				if ((map[pXleft][pYup] == 1) || (map[pXright][pYup] == 1)) { // Check upward
					vecWeapons[i]->SetImpact(1);
				}
				break;

			case 'd':
				if ((map[pXleft][pYdown] == 1) || (map[pXright][pYdown] == 1)) { // Check downward
					vecWeapons[i]->SetImpact(1);
				}
				break;

			case 'r':
				if ((map[pXright][pYdown] == 1) || (map[pXright][pYup] == 1)) { // Check the right side
					vecWeapons[i]->SetImpact(1);
				}
				break;

			case 'l':
				if ((map[pXleft][pYup] == 1) || (map[pXleft][pYdown] == 1)) { // Check the left side
					vecWeapons[i]->SetImpact(1);
				}
				break;
			}

		}
		else if (player.GetPos() == vecWeapons[i]->GetPos()) { // Player get the dropped weapon
			player.SetWeapon(vecWeapons[i]->GetType());
			vecWeapons.erase(vecWeapons.begin() + i);
			i--;
			sfx_loot.PlayAudio();
		}

	}
}

void Grid::DrawAllFires()
{
	//----------------------- DELETE ALL FIRE THAT HAS IMPACTED SOMEWHERE
	for (unsigned int i = 0; i < vecWeapons.size(); i++) {
		if (vecWeapons[i]->IsDestroyed()) { // The impact animation has ended
			vecWeapons.erase(vecWeapons.begin() + i);
			i--;
			sfx_bullet_hit.PlayAudio();
		}
	}

	//------------------------ DRAW THE REMAINING ONES
	for (unsigned int i = 0; i < vecWeapons.size(); i++) {
		vecWeapons[i]->DrawFire();
	}
}

void Grid::Redim(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)m_rows, (double)m_lignes, 0.0);
}

int Grid::HUD_Score()
{
	return m_score;
}

void Grid::EndGame()
{
}


Grid::~Grid()
{

}