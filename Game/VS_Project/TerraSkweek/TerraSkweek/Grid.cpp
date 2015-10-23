#include "Grid.h"

//-------------- CALL EXTERN VALUES

extern Player player;
extern float light;


Grid::Grid(string biome)
{
	m_biome = biome;

	m_score = 0;
	m_rows = 10;
	m_lignes = 10;

	int mapTemp[10][10] = {
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,1,0,0,0,0,1,
		1,0,0,0,1,0,0,0,0,1,
		1,1,0,0,1,0,0,1,1,1,
		1,0,1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,1,1,1,1,0,0,1,
		1,0,0,0,0,0,1,0,0,1,
		1,0,0,0,0,0,1,0,0,1,
		1,1,1,1,1,1,1,1,1,1,
	};

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			map[i][j] = mapTemp[i][j];
		}
	}


	//------------------------LOAD CORRESPONDING BIOME'S ENEMIES 
	char biomeChar = biome[0];

	if (biomeChar == '1') // Forest
	{
		vecEnemies.push_back(new Slime_Corruption());
	}
	else if (biomeChar == '2') // Corrupted
	{
		vecEnemies.push_back(new Slime_Forest());
		vecEnemies.push_back(new Slime_Forest());
		vecEnemies.push_back(new Slime_Forest());
	}
	else if(biomeChar == '3') // Crimson
	{
	}
	else // Hallow
	{

	}
	



}


Grid::~Grid()
{

}

void Grid::SetMap(int x, int y, int a)
{
	map[x][y] = a;
}

void Grid::LoadAllTextures()
{

	string directory = "Art/" + m_biome + "/";

	LoadGLTextures(directory + "ground.jpg");
	LoadGLTextures(directory + "walls.jpg");
	LoadGLTextures(directory + "converted.jpg");

	//-------------------LOAD ENEMIES TEXTURES
	
	//for (int i = 0; i < vecEnemies.size(); i++) {
	//	vecEnemies[i]->
	//}

	for (Enemy* c : vecEnemies)
	{
		c->LoadAllTextures();
	}
}

int Grid::LoadGLTextures(string name)
{
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
				cout << m_rows << endl;
			}
			else if (m_lignes == 0) { // if m_lignes has not been extracted yet
				m_lignes = extractInt;
				cout << m_lignes << endl;
			}
			else if (i < m_rows) {
				//--------------- LOOP FOR THE MAP
				if (j < m_lignes){
						map[i][j] = extractInt;
						cout << map[i][j];
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
				cout << endl << m_score << endl;
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
void Grid::PrintImg(int i, int j, int width, int height, int textureIt)
{
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, textures[textureIt]);
	glBegin(GL_QUADS);

	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i,j);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i + height, j);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + height, j + width);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i, j + width);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//------------------------------------- DRAW MAP
void Grid::DisplayMap()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			switch (map[i][j])
			{
			case 0:// Floor
				//glBegin(GL_QUADS);
				//glColor3d(1.0, 0.0, 0.0); glVertex2d(i, j);
				//glColor3d(0.0, 1.0, 0.0); glVertex2d(i + 1, j);
				//glColor3d(0.0, 0.0, 1.0); glVertex2d(i + 1, j + 1);
				//glColor3d(0.0, 0.0, 0.0); glVertex2d(i, j + 1);
				//glEnd();
				PrintImg(i, j, 1, 1, 0);
				break;
			case 1:// Wall
				PrintImg(i, j, 1, 1, 1);
				break;
			case 2:// Converted Floor
				PrintImg(i, j, 1, 1, 2);
				break;
			}
		}
	}// End drawing

}


void Grid::DrawEnemies()
{
	for (unsigned int i = 0; i < vecEnemies.size(); i++) {
		vecEnemies[i]->Draw();
	}

	//for (Enemy* c : vecEnemies)
	//{
	//	c;
	//}
}

void Grid::MoveAllEnemies()
{
	for (unsigned int i = 0; i < vecEnemies.size(); i++) {
		// Save previous position if it collide with a wall
		Position prevPos = { vecEnemies[i]->GetPos().x , vecEnemies[i]->GetPos().y , vecEnemies[i]->GetPos().z };

		//--------------------- MOVING ENEMIES
		vecEnemies[i]->Move(player.GetPos(), light);


		//---------- CHECK COLLISION PLAYER / ENEMIES - 1 player
		if (vecEnemies[i]->GetPos() == player.GetPos()) {
			player.SetLife(player.GetLife() - vecEnemies[i]->GetDamage()); // Player's life is minus by the enemy's contact damage
		}

		//----------- CHECK WALL COLLISION
		int pXleft = round(vecEnemies[i]->GetPos().x - 0.4);
		int pXright = round(vecEnemies[i]->GetPos().x + 0.4);
		int pYup = round(vecEnemies[i]->GetPos().y - 0.4);
		int pYdown = round(vecEnemies[i]->GetPos().y + 0.4);

		switch (vecEnemies[i]->GetDir())
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

void Grid::NewFire(string emitter, char dir, Position pos)
{
		vecWeapons.push_back(new Weapon(emitter, dir, pos));
}

void Grid::MoveAllFires()
{
	for (unsigned int i = 0; i < vecWeapons.size(); i++) {
		vecWeapons[i]->MoveFire();
	}
}

void Grid::DrawAllFires()
{
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

void Grid::HUD()
{
}

void Grid::Pause()
{
}

void Grid::EndGame()
{
}
