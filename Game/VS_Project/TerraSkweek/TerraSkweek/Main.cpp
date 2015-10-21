#include "Grid.h"


//------------------LOADING MAP TEXTURES


vector<GLuint>	texture;

int LoadGLTextures(string name) // Load Bitmaps And Convert To Textures
{
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	texture.push_back(essai); // Add to the texture vector

	if (texture.at(texture.size() - 1) == 0)
		return false;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success
}


//------------------CREATE MAP 0
int colonnes = 10, lignes = 10; 
int map0[10][10] = {
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





//----------------------CREATE PLAYER AND GRID
Grid grid;
Player player;
Slime_Forest slime_01;



void PrintImg(float, float, float, float, int);
//void PrintNbr(int, int, int);
void DisplayMap();
void LabyRedim(int x, int y);
void KeyAction(int x, int y, int z);
//void HUD(unsigned char key, int y, int z);
void DessinerNiveau();
//void Idle();
//void LabyTimer1(int x);
void PlayerMovt(int x);


int main() {



	
	//Gestion de la fenetre
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(200, 200);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("TerraSkweek");

	player.LoadAllTextures();
	slime_01.LoadAllTextures();


	
	//Gestion des evenements
	glutDisplayFunc(DisplayMap);
	glutReshapeFunc(LabyRedim);
	glutSpecialFunc(KeyAction); // Directions for the player
	//glutKeyboardFunc(HUD);// Keyboard keys to control the HUD
	//glutTimerFunc(700, LabyTimer1, 0); // Direction for the enemies
	glutTimerFunc(50, PlayerMovt, 0); // Continuous movement of the player
	//glutIdleFunc(Idle);






	glutMainLoop();
	
	
	
	return 0;
	


}




//------------------ PRINT IMAGES TO SCREEN
void PrintImg(float i, float j, float width, float height, int textureIt) {

	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, texture[textureIt]);//Texture[0] is linked to the first LoadGLTextures() in the glutMainLoop()
	glBegin(GL_QUADS);

	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);// coord flipped along the vertical axis
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + height, j);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i + height, j + width);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + width);

	glEnd();
	glDisable(GL_TEXTURE_2D);

}

//------------------ PRINT INT INTO IMGs
//void PrintNbr(int x, int y, int val) {
//
//	if (val < 0) {// If the value is negative, no need to print it!
//		return;
//	}
//
//	string valTxt = to_string(val);
//	int len = valTxt.length();
//
//	int textItStart = 24; // Indice de texture[] correspondant au premier chiffre (texture[textItStart] = 0.png)
//	float height = 1;
//	float width = 0.5;
//
//	for (int i = 0; i < len; i++) {
//		// Space between numbers
//		float space = 0.3;
//		//For each char of valTxt (=digit of val), Print the corresponding number
//		switch (valTxt[i])
//		{
//		case '0':
//			PrintImg(x + i*space, y, height, width, textItStart);
//			break;
//		case '1':
//			PrintImg(x + i*space, y, height, width, textItStart + 1);
//			break;
//		case '2':
//			PrintImg(x + i*space, y, height, width, textItStart + 2);
//			break;
//		case '3':
//			PrintImg(x + i*space, y, height, width, textItStart + 3);
//			break;
//		case '4':
//			PrintImg(x + i*space, y, height, width, textItStart + 4);
//			break;
//		case '5':
//			PrintImg(x + i*space, y, height, width, textItStart + 5);
//			break;
//		case '6':
//			PrintImg(x + i*space, y, height, width, textItStart + 6);
//			break;
//		case '7':
//			PrintImg(x + i*space, y, height, width, textItStart + 7);
//			break;
//		case '8':
//			PrintImg(x + i*space, y, height, width, textItStart + 8);
//			break;
//		case '9':
//			PrintImg(x + i*space, y, height, width, textItStart + 9);
//			break;
//
//		}
//
//	}
//
//}

//----------------------------CONTINUOUS PLAYER MOVEMENT
void PlayerMovt(int x) {

	// Save previous position to revert changes if the new one is invalid
	Position playerPrevPos = { player.GetPos().x, player.GetPos().y, player.GetPos().z };

	switch (player.GetDir())
	{
	case 'l':
		player.MoveLeft();
		break;
	case 'r':
		player.MoveRight();
		break;
	case 'u':
		player.MoveUp();
		break;
	case 'd':
		player.MoveDown();
		break;
	}

	int newX = (player.GetPos().x); // for easier (and shorter) operation
	int newY = (player.GetPos().y);
	//int newZ = player.GetPos().z;

	int pXleft = round(player.GetPos().x - 0.4);
	int pXright = round(player.GetPos().x + 0.4);
	int pYup = round(player.GetPos().y - 0.4);
	int pYdown = round(player.GetPos().y + 0.4);

	int pXleftConv = round(player.GetPos().x - 0.1);
	int pXrightConv = round(player.GetPos().x + 0.1);
	int pYupConv = round(player.GetPos().y - 0.1);
	int pYdownConv = round(player.GetPos().y + 0.1);


	// ----------------- CHECK WALLS AND CONVERT v2
	switch (player.GetDir())
	{
	case 'u' :
		switch (map0[pXleft][pYup])
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			map0[pXleftConv][pYupConv] = 2;
			break;
		case 2: //Ground converted
			break;
		}

		switch (map0[pXright][pYup])
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			map0[pXrightConv][pYupConv] = 2;
			break;
		case 2: //Ground converted
			break;
		}

		break;

	case 'd':
		switch (map0[pXleft][pYdown])
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			map0[pXleftConv][pYdownConv] = 2;
			break;
		case 2: //Ground converted
			break;
		}

		switch (map0[pXright][pYdown])
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			map0[pXrightConv][pYdownConv] = 2;
			break;
		case 2: //Ground converted
			break;
		}

		break;

	case 'r' : 
		switch (map0[pXright][pYdown])
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			map0[pXrightConv][pYdownConv] = 2;
			break;
		case 2: //Ground converted
			break;
		}

		switch (map0[pXright][pYup])
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			map0[pXrightConv][pYupConv] = 2;
			break;
		case 2: //Ground converted
			break;
		}

		break;


	case 'l':
		switch (map0[pXleft][pYup])
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			map0[pXleftConv][pYupConv] = 2;
			break;
		case 2: //Ground converted
			break;
		}

		switch (map0[pXleft][pYdown])
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			map0[pXleftConv][pYdownConv] = 2;
			break;
		case 2: //Ground converted
			break;
		}

		break;
	}



	//------------------- CHECK CONVERT
	//if () {
	//	map0[newX][newY] = 2;
	//}


	//Update screen
	glutPostRedisplay();

	//Reset Timer
	glutTimerFunc(50, PlayerMovt, 0);
}

//----------------------------DRAW LABYRINTHE - PLAYER - ENEMIES - UI
void DessinerNiveau() {

	// Draw labyrinthe
	for (int i = 0; i < colonnes; i++) {
		for (int j = 0; j < lignes; j++) {
			switch (map0[i][j])
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

				glColor3d(0.0, 0.0, 1.0); glVertex2d(i, j);
				glColor3d(0.0, 0.0, 0.5); glVertex2d(i + 1, j);
				glColor3d(0.0, 0.0, 0.5); glVertex2d(i + 1, j + 1);
				glColor3d(0.0, 0.0, 0.5); glVertex2d(i, j + 1);

				glEnd();
				break;
			}
		}
	}// End drawing

	 // Add player
	player.Draw();
	slime_01.Draw();

	// Translate Map
	glLoadIdentity();
	glTranslatef(-player.GetPos().x + 4, -player.GetPos().y + 4, 0);
	glutSwapBuffers();

}

void DisplayMap() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	DessinerNiveau(); // Affiche le niveau
	glFlush();

}

void LabyRedim(int x, int y) {

	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)colonnes, (double)lignes, 0.0);

}


//---------------------------- SCREEN/HUD CONTROLS
//void HUD(unsigned char key, int y, int z) {
//
//	if (screenIt>3) {// If screen Death or WIN, then skip the function
//		return;
//	}
//
//	if ((screenIt == 3) && (key == ' ')) {
//		screenIt = 2;
//	}
//	else {
//		screenIt++;
//	}
//
//}

//-------------------------- PLAYER MOVEMENTS
void KeyAction(int key, int x, int y) {

			switch (key)
		{
		case GLUT_KEY_LEFT:
			player.SwitchDir('l');
			break;
		case GLUT_KEY_RIGHT:
			player.SwitchDir('r');
			break;
		case GLUT_KEY_UP:
			player.SwitchDir('u');
			break;
		case GLUT_KEY_DOWN:
			player.SwitchDir('d');
			break;
		}

}


//---------------------------- TIMER ENEMIES MOVEMENTS

// Slow and Random
//void LabyTimer1(int x) {
//
//	if (screenIt != 3) {
//		// Reset Timer to move again
//		glutTimerFunc(700, LabyTimer1, 0);
//		return;
//	}// If it's not in game (Title screen, controls screen, or paused), then do nothing
//
//	Position prevPos = ghost1.GetPos();	//Previous Position (before moving)
//
//	do {
//
//		ghost1.Teleport(prevPos); // If invalid reset to the previous Position
//
//		int dir = rand() % 4; // Create a value between 0 and 3 (inclusive)
//
//							  //Move accordingly
//		switch (dir)
//		{
//		case 0:
//			ghost1.MoveUp();
//			break;
//		case 1:
//			ghost1.MoveDown();
//			break;
//		case 2:
//			ghost1.MoveRight();
//			break;
//		case 3:
//			ghost1.MoveLeft();
//			break;
//		}
//
//
//		//Check if Teleportation
//		if ((ghost1.GetPos().x == m_teleportLeft.x - 1) && (ghost1.GetPos().y == m_teleportLeft.y)) {// If Player is on the Teleport platform on the Left of the screen
//			ghost1.Teleport(m_teleportRight);//Teleport to the Right of the screen
//		}
//		else if ((ghost1.GetPos().x == m_teleportRight.x + 1) && (ghost1.GetPos().y == m_teleportRight.y)) {
//			ghost1.Teleport(m_teleportLeft);
//		}
//		else {}
//
//		// Check if the new Position is valid (avoid walls, UI surface, and Exit)
//	} while ((labyrinthe[ghost1.GetPos().x][ghost1.GetPos().y] == 1) || (labyrinthe[ghost1.GetPos().x][ghost1.GetPos().y] == -1) || (labyrinthe[ghost1.GetPos().x][ghost1.GetPos().y] == 2) || (labyrinthe[ghost1.GetPos().x][ghost1.GetPos().y] == 3) || (labyrinthe[ghost1.GetPos().x][ghost1.GetPos().y] == 4));
//
//	// Update screen
//	glutPostRedisplay();
//
//
//	// Reset Timer
//	glutTimerFunc(700, LabyTimer1, 0);
//
//
//}



//-----------------------------WHAT HAPPENS WHEN NOTHING HAPPENS :)
//Check LOSE
//Check if player is attacked
//void Idle() {
//
//	//-------------------IF NO MORE LIFE
//	if (player.Life() <= 0) {
//		screenIt = 4;
//	}
//
//	//------------------IS PLAYER SAFE ?
//	if (player.GetPos() != ghost1.GetPos()) {
//		hurt1 = false;
//	}
//
//	if (player.GetPos() != ghost2.GetPos()) {
//		hurt2 = false;
//	}
//
//	if (player.GetPos() != ghost3.GetPos()) {
//		hurt3 = false;
//	}
//
//	if (player.GetPos() != ghost4.GetPos()) {
//		hurt4 = false;
//	}
//
//	//----------------- IS GHOST 1 ON THE PLAYER ? - 1 life
//	// Check if the player was safe before the attack (else the life would decrease at each frame!)
//	if ((player.GetPos() == ghost1.GetPos()) && (hurt1 == false)) {
//		hurt1 = true;
//		player.Hurt(1);
//		player.Teleport(m_start);
//	}
//
//	//----------------- IS GHOST 2 ON THE PLAYER ? - 2 lives
//	if ((player.GetPos() == ghost2.GetPos()) && (hurt2 == false)) {
//		hurt2 = true;
//		player.Hurt(2);
//		player.Teleport(m_start);
//	}
//
//	//----------------- IS GHOST 3 ON THE PLAYER ? - 3 lives
//	if ((player.GetPos() == ghost3.GetPos()) && (hurt3 == false)) {
//		hurt3 = true;
//		player.Hurt(3);
//		player.Teleport(m_start);
//	}
//
//	//----------------- IS GHOST 4 ON THE PLAYER ? - 1 life
//	if ((player.GetPos() == ghost4.GetPos()) && (hurt4 == false)) {
//		hurt4 = true;
//		player.Hurt(1);
//		player.Teleport(m_start);
//	}
//
//
//
//}
//
