#include "Grid.h"


//------------------LOADING MAP TEXTURES

vector<GLuint>	UI;

int LoadGLTextures(string name) // Load Bitmaps And Convert To Textures
{
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	UI.push_back(essai); // Add to the texture vector

	if (UI.at(UI.size() - 1) == 0)
		return false;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;       // Return Success
}



//----------------------CREATE PLAYER AND LEVELS
Grid lvl01("2corrupted");

Player player;



//----------------------A SUPPRIMER POUR UTILISER LE DETECTEUR DE LUMIERE

int currentFrame;

//----------------------



int refreshRate = 30; // in miliseconds
float light;

void PrintImg(float, float, float, float, int);
//void PrintNbr(int, int, int);
void Display();
void Redim(int x, int y);
void KeyAction(int x, int y, int z);
void invisibility(unsigned char key, int y, int z);
void DrawLevel();
//void Idle();
//void EnemiesTimer(int x);
void PlayerMovt(int x);


void main() {
	cout << "ok";

	//------------------LOAD RANDOM
	srand(time(NULL)); // Create a seed to start the random from


	//------------------ LOAD PLAYER' SAVE
	//lvl01.LoadGame("player1.txt");
		

	//Gestion de la fenetre
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);		A remplacer pour l'affichage sur d'autres PC par GLUT_DOUBLE
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("TerraSkweek");

	//----------------------- LOAD EVERYBODY'S SPRITES
	lvl01.LoadAllTextures();
	player.LoadAllTextures();
	//slime_01.LoadAllTextures();


	
	//Gestion des evenements
	glutDisplayFunc(Display);
	glutReshapeFunc(Redim);
	glutSpecialFunc(KeyAction); // Switch player's direction
	glutKeyboardFunc(invisibility);// Keyboard keys to control the HUD // and Fire
	//glutTimerFunc(700, EnemiesTimer, 0); // Direction for the enemiesd
	glutTimerFunc(refreshRate, PlayerMovt, 0); // Continuous movement of the player
	//glutIdleFunc(Idle);



	glutMainLoop();

	
}




//------------------ PRINT IMAGES TO SCREEN
void PrintImg(float i, float j, float width, float height, int textureIt) {

	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, UI[textureIt]);
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

//----------------------------CONTINUOUS PLAYER MOVEMENT + ENEMIES

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

	int pXleftConv = round(player.GetPos().x - 0.3);
	int pXrightConv = round(player.GetPos().x + 0.3);
	int pYupConv = round(player.GetPos().y - 0.3);
	int pYdownConv = round(player.GetPos().y + 0.3);


	// ----------------- CHECK WALLS AND CONVERT v2
	switch (player.GetDir())
	{
	case 'u' :
		switch (lvl01.Map(pXleft,pYup))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			lvl01.SetMap(pXleftConv, pYupConv, 2);
			break;
		case 2: //Ground converted
			break;
		}

		switch (lvl01.Map(pXright, pYup))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			lvl01.SetMap(pXrightConv , pYupConv, 2);
			break;
		case 2: //Ground converted
			break;
		}

		break;

	case 'd':
		switch (lvl01.Map(pXleft, pYdown))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			lvl01.SetMap(pXleftConv, pYdownConv, 2);
			break;
		case 2: //Ground converted
			break;
		}

		switch (lvl01.Map(pXright, pYdown))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			lvl01.SetMap(pXrightConv, pYdownConv, 2);
			break;
		case 2: //Ground converted
			break;
		}

		break;

	case 'r' : 
		switch (lvl01.Map(pXright, pYdown))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			lvl01.SetMap(pXrightConv, pYdownConv, 2);
			break;
		case 2: //Ground converted
			break;
		}

		switch (lvl01.Map(pXright, pYup))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			lvl01.SetMap(pXrightConv, pYupConv, 2);
			break;
		case 2: //Ground converted
			break;
		}

		break;


	case 'l':
		switch (lvl01.Map(pXleft, pYup))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			lvl01.SetMap(pXleftConv, pYupConv, 2);
			break;
		case 2: //Ground converted
			break;
		}

		switch (lvl01.Map(pXleft, pYdown))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			lvl01.SetMap(pXleftConv, pYdownConv, 2);
			break;
		case 2: //Ground converted
			break;
		}

		break;
	}


	//------------------------ MOVE ALL ENEMIES 
	lvl01.MoveAllEnemies();

	//------------------------ MOVE ALL FIRE
	lvl01.MoveAllFires();

	//Update screen
	glutPostRedisplay();

	//Reset Timer
	glutTimerFunc(refreshRate, PlayerMovt, 0);
}


//----------------------------DRAW LABYRINTHE - PLAYER - ENEMIES - UI
void DrawLevel() {

	// Draw map
	lvl01.DisplayMap();
	
	// Add player
	player.Draw();

	//Draw Enemies
	lvl01.DrawEnemies();

	//Draw Fires
	lvl01.DrawAllFires();

	// Translate Map
	glLoadIdentity();
	glTranslatef(-player.GetPos().x + 4, -player.GetPos().y + 4, 0);
	glutSwapBuffers();

}

void Display() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	DrawLevel(); // Affiche le niveau
//	glFlush();		A remplacer par glutSwapBuffers.
//	glutSwapBuffers();

}

void Redim(int x, int y) {

	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)10, (double)10, 0.0);

}


//---------------------------- SCREEN/HUD CONTROLS
void invisibility(unsigned char key, int y, int z) {
	

//-------------------------- A ENLEVER POUR LAISSER PLACE AU DETECTEUR DE LUMIERE SUR ARDUINO
	if (key == '0') {
		const int div = 4;
		currentFrame = (currentFrame + 1) % div;
		light = currentFrame * 4 / div;


		//		const int div = 4;
		//		fLight = (fLight) / div;
		//		light = fLight * 4 / div;


		player.setOpacity(light);// à placer dans une boucle infinie pour detecter toujours la valeur de "light"
	}
	//cout << light << endl;

// -------------------------------- PLAYER FIRE
	if (key == ' ') {

		player.Attack();
		lvl01.NewFire("player", player.GetDir(), player.GetPos());
		cout << "NewFire" << endl;
	}





}

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
