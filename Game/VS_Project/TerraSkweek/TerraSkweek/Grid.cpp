#include "Grid.h"



Grid::Grid()
{
	m_score = 0;
	m_rows = 10;
	m_lignes = 10;

	int mapTemp[10][10] = {
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,1,0,0,0,0,1,
		1,0,0,0,1,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,1,1,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,
	};

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			map[i][j] = mapTemp[i][j];
		}
	}


}


Grid::~Grid()
{

}

void Grid::SetMap(int x, int y, int a)
{
	map[x][y] = a;
}

int Grid::Map(int x, int y)
{
	return map[x][y];
}

void Grid::SaveGame()
{
	//--------------------------Ouvrir le fichier en écriture | supprimer ce qui est dedans avant d'ecrire
	ofstream fichier("Saves/map2.txt", ios::out | ios::trunc);

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

void Grid::LoadGame()
{
	m_rows = 0;
	m_lignes = 0;

	//--------------------------Ouvrir le fichier en lecture
	ifstream fichier("Saves/map1.txt", ios::in);

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

void Grid::NewGame()
{

}

//-------------------------------------DRAW MAP
void Grid::DisplayMap()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			switch (map[i][j])
			{
			case 0:// Floor
				glBegin(GL_QUADS);

				glColor3d(0.5, 0.5, 0.0); glVertex2d(i, j);
				glColor3d(0.5, 0.0, 0.0); glVertex2d(i + 1, j);
				glColor3d(0.5, 0.0, 0.0); glVertex2d(i + 1, j + 1);
				glColor3d(0.5, 0.0, 0.0); glVertex2d(i, j + 1);

				glEnd();
				break;
			case 1:// Wall
				glBegin(GL_QUADS);

				glColor3d(0.0, 0.5, 0.5); glVertex2d(i, j);
				glColor3d(0.0, 0.5, 0.0); glVertex2d(i + 1, j);
				glColor3d(0.0, 0.5, 0.0); glVertex2d(i + 1, j + 1);
				glColor3d(0.0, 0.5, 0.0); glVertex2d(i, j + 1);

				glEnd();
				break;
			case 2:// Converted Floor
				glBegin(GL_QUADS);

				glColor3d(0.0, 0.5, 1.0); glVertex2d(i, j);
				glColor3d(0.0, 0.0, 0.5); glVertex2d(i + 1, j);
				glColor3d(0.0, 0.0, 0.5); glVertex2d(i + 1, j + 1);
				glColor3d(0.0, 0.0, 0.5); glVertex2d(i, j + 1);

				glEnd();
				break;
			}
		}
	}// End drawing

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
