#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include "Menu.h"


//----------------------- COMMON VARIABLES
extern bool inGame;
extern int m_score;
int windowWidth = 200;
int windowHeight = 200;
extern const int TextWidth = 75;
extern const Position playerInitPos = { 750, 750, 0 };


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
HUD hud{ 1 };
Player player;
Menu menu;
Grid lvl("0menu");

//-------------------- CREATE VARs FOR ARDUINO'S COMM
Serial* SP = new Serial("COM4");    // adjust as needed

char incomingData[256] = "";	// don't forget to pre-allocate memory

int dataLength = 256;
int readResult = 0;


//----------------------A SUPPRIMER POUR UTILISER LE DETECTEUR DE LUMIERE

int currentFrame;

//----------------------

int refreshRate = 30; // in miliseconds
float light;
int enemySpawnFrequency = 5000;

//void PrintImg(float, float, float, float, int);
//void PrintNbr(int, int, int);
void Display();
void Redim(int x, int y);
void KeyAction(int x, int y, int z);
void KeyButtons(unsigned char key, int y, int z);
void DrawLevel();
void ActivateSpawnMob(int x);
//void Idle();
//void EnemiesTimer(int x);
void PlayerMovt(int x);
void NoKeyAction();
void InterfaceArduino();






void main() {
	cout << "ok";

	//--------------------- LOAD ARDUINO'S COMMUNICATION

	if (SP->IsConnected())
		printf("We're connected");

	//char incomingData[256] = "";	// don't forget to pre-allocate memory



	//------------------LOAD RANDOM
	srand(time(NULL)); // Create a seed to start the random from
	
	//------------------ LOAD PLAYER' SAVE
	//lvl.LoadGame("player1.txt");

	//Gestion de la fenetre
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1000, 1000);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);		//A remplacer pour l'affichage sur d'autres PC par GLUT_DOUBLE
	//glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("TerraSkweek");
	//glutFullScreen();           // making the window full screen


	//----------------------- LOAD EVERYBODY'S SPRITES
	menu.LoadAllTextures();
	lvl.LoadAllTextures();
	player.LoadAllTextures();
	hud.LoadAllTextures();
		
	//Gestion des evenements
	glutDisplayFunc(Display);
	glutReshapeFunc(Redim);
	glutSpecialFunc(KeyAction); // Switch player's direction

	glutKeyboardFunc(KeyButtons);// Keyboard keys to control the HUD // and Fire
	//glutTimerFunc(700, EnemiesTimer, 0); // Direction for the enemiesd
	glutTimerFunc(refreshRate, PlayerMovt, 0); // Continuous movement of the player
	glutTimerFunc(enemySpawnFrequency, ActivateSpawnMob, 0);
	//glutIdleFunc(Idle);



	glutMainLoop();
}





void InterfaceArduino()
{


	readResult = SP->ReadData(incomingData, dataLength);

	if (readResult != -1) {
		/*
		if (incomingData[0] == 'B') {
		cout << "bouclier" << endl;
		//SP->WriteData("b", 1);
		//Sleep(150); ------ si on envoie des données
		}
		else
		*/


		int L = player.GetLife();
		if (inGame) {
			if (L <= 150 && L > 125)
				SP->WriteData("7", 1);
			else if (L <= 125 && L > 100)
				SP->WriteData("6", 1);
			else if (L <= 100 && L > 75)
				SP->WriteData("5", 1);
			else if (L <= 75 && L > 50)
				SP->WriteData("4", 1);
			else if (L <= 50 && L > 25)
				SP->WriteData("3", 1);
			else if (L <= 25 && L > 0)
				SP->WriteData("2", 1);
			else if (L <= 0)
				SP->WriteData("1", 1);
		}
		else
			SP->WriteData("0", 1);



		if (incomingData[0] == 'P') { // Game is Paused
			menu.Pause();
		}
		else if (incomingData[0] == 'I') { // Player is invisible
			player.setOpacity(0.1);
		}
		else if (incomingData[0] == 'J') { // Player is visible
			player.setOpacity(0.4);
		}
		else if (incomingData[0] == 'W') { // Player is visible
			player.setOpacity(0.70);

		}
		else if (incomingData[0] == 'V') { // Player is visible
			player.setOpacity(1.0);
		}
		else if (incomingData[0] == 'F') { // Player is firing
			if (inGame) {

				if (player.IsFiring() == false)
				{
					if (!(player.HasPowderBag())) { // As long has player has no powder bag
						player.Attack();
						lvl.NewFire(player.GetWeapon(), player.GetDir(), player.GetPos());
					}
					else { // consume powder bag and convert cases

						int X = round(player.GetPos().x / TextWidth + 0.4);
						int Y = round(player.GetPos().y / TextWidth + 0.4);

						switch (player.GetDir())
						{
						case 'u':
							for (int i = player.GetPos().y / TextWidth; i > player.GetPos().y / TextWidth - 5; i--) {
								lvl.SetMap(X, i, 4);
							}
							break;
						case 'd':
							for (int i = player.GetPos().y / TextWidth; i < player.GetPos().y / TextWidth + 5; i++) {
								lvl.SetMap(X, i, 4);
							}
							break;
						case 'r':
							for (int i = player.GetPos().x / TextWidth; i < player.GetPos().x / TextWidth + 5; i++) {
								lvl.SetMap(i, Y, 4);
							}
							break;
						case 'l':
							for (int i = player.GetPos().x / TextWidth; i > player.GetPos().x / TextWidth - 5; i--) {
								lvl.SetMap(i, Y, 4);
							}
							break;
						}
						player.SetPowderBag(false);
					}
				}

			}
			else
			{
				menu.Clicking();
			}
		}
		else if (incomingData[0] == 'u') { // Player's Direction
			player.SwitchDir('u');
			player.SetMoving(true);
			player.SetStillMoving(true);
		}
		else if (incomingData[0] == 'd') {
			player.SwitchDir('d');
			player.SetMoving(true);
			player.SetStillMoving(true);
		}
		else if (incomingData[0] == 'r') {
			player.SwitchDir('r');
			player.SetMoving(true);
			player.SetStillMoving(true);
		}
		else if (incomingData[0] == 'l') {
			player.SwitchDir('l');
			player.SetMoving(true);
			player.SetStillMoving(true);
		}
		else if (incomingData[0] == 'A') { // Enemies' speed
			lvl.SetEnemiesSpeed(25);
		}
		else if (incomingData[0] == 'B') {
			lvl.SetEnemiesSpeed(18);
		}
		else if (incomingData[0] == 'C') {
			lvl.SetEnemiesSpeed(10);
		}
	}

	//Serial.read() ---- pour éteindre / allumer les leds
}


/*

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

*/


//----------------------------- SPAWN NEW MOB
void ActivateSpawnMob(int x) {
	if (inGame)
	{
		lvl.SpawnMob();

		//Update screen
		glutPostRedisplay();

	}

	//Reset Timer
	glutTimerFunc(enemySpawnFrequency, ActivateSpawnMob, 0);

}


//----------------------------CONTINUOUS PLAYER MOVEMENT + ENEMIES

void PlayerMovt(int x) {

	if (player.IsStillMoving()) {
	
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

	const int margin = 30;

	int pXleft = round((player.GetPos().x - margin )/TextWidth);
	int pXright = round((player.GetPos().x + margin) / TextWidth);
	int pYup = round((player.GetPos().y - margin) / TextWidth);
	int pYdown = round((player.GetPos().y + margin) / TextWidth);

	int pXleftConv = round(player.GetPos().x / TextWidth);
	int pXrightConv = round(player.GetPos().x / TextWidth);
	int pYupConv = round(player.GetPos().y / TextWidth);
	int pYdownConv = round(player.GetPos().y / TextWidth);


	//cout << pXleftConv << " , " << pYdownConv << endl;
	//cout << pXleft << " , " << pYup << endl;

	//cout << lvl.Map(pXleft, pYup) << endl;

	// ----------------- CHECK WALLS AND CONVERT
	switch (player.GetDir())
	{
	case 'u':
		switch (lvl.Map(pXleft, pYup))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			if (light > 1 && !(player.GetPos().z))
				lvl.SetMap(pXleft, pYup, 4);
				//cout << "Map convertie avec la valeur : "<< lvl.Map(pXleftConv, pYupConv) << endl;
			break;
		case 2: //Ground converted
			break;
		case 3: //Semi-converted case
			if (light > 1 && !(player.GetPos().z)) {
				lvl.SetMap(pXleft, pYup, 4);

				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						lvl.SetMap(pXleft + i, pYup + j, 4);
					}
				}
			}
			break;
		case 6 : // Fall
			player.SetLife(player.GetLife()-40); 
			player.Teleport(playerInitPos);
			break;

		}

		switch (lvl.Map(pXright, pYup))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert	
			if (light > 1 && !(player.GetPos().z))
			lvl.SetMap(pXright, pYup, 4);
			break;
		case 2: //Ground converted
			break;
		case 3: //Semi-converted case
			if (light > 1 && !(player.GetPos().z)) {
				lvl.SetMap(pXright, pYup, 4);

				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						lvl.SetMap(pXrightConv + i, pYupConv + j, 4);
					}
				}
			}
			break;
		case 6: // Fall
				player.SetLife(player.GetLife() - 40);
				player.Teleport(playerInitPos);
				break;
		}

		break;

	case 'd':
		switch (lvl.Map(pXleft, pYdown))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			if (light > 1 && !(player.GetPos().z))
			lvl.SetMap(pXleft, pYdown, 4);
			break;
		case 2: //Ground converted
			break;
		case 3: //Semi-converted case
			if (light > 1 && !(player.GetPos().z)) {
				lvl.SetMap(pXleft, pYdown, 4);

				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						lvl.SetMap(pXleft + i, pYdown + j, 4);
					}
				}
			}
			break;
		case 6: // Fall
			player.SetLife(player.GetLife() - 40);
			player.Teleport(playerInitPos);
			break;
		}

		switch (lvl.Map(pXright, pYdown))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			if (light > 1 && !(player.GetPos().z))
			lvl.SetMap(pXright, pYdown, 4);
			break;
		case 2: //Ground converted
			break;
		case 3: //Semi-converted case
			if (light > 1 && !(player.GetPos().z)) {
				lvl.SetMap(pXright, pYdown, 4);

				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						lvl.SetMap(pXright + i, pYdown + j, 4);
					}
				}
			}
			break;
		case 6: // Fall
			player.SetLife(player.GetLife() - 40);
			player.Teleport(playerInitPos);
			break;
		}

		break;

	case 'r':
		switch (lvl.Map(pXright, pYdown))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			if (light > 1 && !(player.GetPos().z))
			lvl.SetMap(pXright, pYdown, 4);
			break;
		case 2: //Ground converted
			break;
		case 3: //Semi-converted case
			if (light > 1 && !(player.GetPos().z)) {
				lvl.SetMap(pXright, pYdown, 4);

				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						lvl.SetMap(pXright + i, pYdown + j, 4);
					}
				}
			}
			break;
		case 6: // Fall
			player.SetLife(player.GetLife() - 40);
			player.Teleport(playerInitPos);
			break;
		}

		switch (lvl.Map(pXright, pYup))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			if (light > 1 && !(player.GetPos().z))
				lvl.SetMap(pXright, pYup, 4);
			break;
		case 2: //Ground converted
			break;
		case 3: //Semi-converted case
			if (light > 1 && !(player.GetPos().z)){
				lvl.SetMap(pXright, pYup, 4);

				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						lvl.SetMap(pXright + i, pYup + j, 4);
					}
				}
			}
			break;
		case 6: // Fall
			player.SetLife(player.GetLife() - 40);
			player.Teleport(playerInitPos);
			break;
		}
		break;


	case 'l':
		switch (lvl.Map(pXleft, pYup))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			if (light > 1 && !(player.GetPos().z))
			lvl.SetMap(pXleft, pYup, 4);
			break;
		case 2: //Ground converted
			break;
		case 3: //Semi-converted case
			if (light > 1 && !(player.GetPos().z)) {
				lvl.SetMap(pXleft, pYup, 4);

				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						lvl.SetMap(pXleft + i, pYup + j, 4);
					}
				}
			}
			break;
		case 6: // Fall
			player.SetLife(player.GetLife() - 40);
			player.Teleport(playerInitPos);
			break;
		}

		switch (lvl.Map(pXleft, pYdown))
		{
		case 1:// Walls
			player.Teleport(playerPrevPos);
			break;
		case 0: //Ground to convert
			if (light > 1 && !(player.GetPos().z))
			lvl.SetMap(pXleft, pYdown, 4);
			break;
		case 2: //Ground converted
			break;
		case 3: //Semi-converted case
			if (light > 1 && !(player.GetPos().z)) {
				lvl.SetMap(pXleft, pYdown, 4);

				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						lvl.SetMap(pXleft+ i, pYdown + j, 4);
					}
				}
			}
			break;
		case 6: // Fall
			player.SetLife(player.GetLife() - 40);
			player.Teleport(playerInitPos);
			break;
		}
		break;
	}
}

	//------------------------ MOVE ALL ENEMIES 
	lvl.MoveAllEnemies();

	//------------------------ MOVE ALL FIRE
	lvl.MoveAllFires();

	//Update screen
	glutPostRedisplay();

	//Reset Timer
	glutTimerFunc(refreshRate, PlayerMovt, 0);


    player.SetStillMoving(0);
}


//----------------------------DRAW LABYRINTHE - PLAYER - ENEMIES - UI
void DrawLevel() {

	glPushMatrix();

	if (inGame)
	{
		// Translate Map
		glTranslatef(-player.GetPos().x + (windowWidth / 2), -player.GetPos().y + (windowHeight / 2), 0);

		// Draw map
		lvl.DisplayMap();

		//Draw Enemies
		lvl.DrawSpecialCases();

		//Draw Enemies
		lvl.DrawEnemies();

		if (player.GetPos().z == 1) { // If the player is UP
			// Draw UpCase under the player and his fire
			lvl.DrawUpCase();
		}

		//Draw Fires
		lvl.DrawAllFires();

		// Add player
		player.Draw(inGame);

		if (player.GetPos().z == 0) { // If the player is DOWN
			// Draw UpCase over the player and his fire
			lvl.DrawUpCase();
		}

		
		glLoadIdentity();
		glutSwapBuffers();
		glPopMatrix();

		//Draw HUD
		hud.displayScore(lvl.HUD_Score(), player.GetLife(), player.GetWeapon());
		
	}

	else
	{
		lvl.DisplayMap();

		//Draw Menu
		menu.Display();

		// Add player
		player.Draw(inGame);

		glLoadIdentity();
		glutSwapBuffers();
		glPopMatrix();
	}

}

void Display() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	InterfaceArduino();
	cout << "le joueur tire : " << player.IsFiring() << endl;
	DrawLevel(); // Affiche le niveau
	glFlush();		//A remplacer par glutSwapBuffers.
//	glutSwapBuffers();

}

void Redim(int x, int y) {

	cout << glutGet(GLUT_WINDOW_WIDTH) << endl;
	cout << glutGet(GLUT_WINDOW_HEIGHT) << endl;
	windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	windowHeight = glutGet(GLUT_WINDOW_HEIGHT);


	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0.0, (double)(20), (double)(20), 0.0);
	gluOrtho2D(0.0, (double)(windowWidth), (double)(windowHeight), 0.0);
	cout << windowWidth << endl;
	//gluOrtho2D(0.0, (double)(res*windowWidth), (double)(res*windowHeight), 0.0);
	//gluOrtho2D(0.0, (double)(res*glutGet(GLUT_SCREEN_WIDTH)), (double)(res*glutGet(GLUT_SCREEN_HEIGHT)), 0.0);
	//gluOrtho2D(0.0, (double)(res*glutGet(GLUT_WINDOW_WIDTH)), (double)(res*glutGet(GLUT_WINDOW_HEIGHT)), 0.0);

}


//---------------------------- SCREEN/HUD CONTROLS
void KeyButtons(unsigned char key, int y, int z) {
	

	//-------------------------- A ENLEVER POUR LAISSER PLACE AU DETECTEUR DE LUMIERE SUR ARDUINO
	//if (key == '0') {
	//	const int div = 4;
	//	currentFrame = (currentFrame + 1) % div;
	//	light = currentFrame * 4 / div;

	//	player.setOpacity(light);// à placer dans une boucle infinie pour detecter toujours la valeur de "light"
	//}

	//cout << light << endl;


	//--------------------------CHANGE ENEMY' SPEED
	switch (key)
	{
	case '1':
		lvl.SetEnemiesSpeed(15);
		break;
	case '2':
		lvl.SetEnemiesSpeed(20);
		break;
	case '3':
		lvl.SetEnemiesSpeed(30);
		break;
	}


// -------------------------------- PLAYER FIRE
	if (inGame)
	{
		if (key == ' ' && (player.IsFiring() == false)) 
		{
			if (!(player.HasPowderBag())) { // As long has player has no powder bag
				player.Attack();
				lvl.NewFire(player.GetWeapon(), player.GetDir(), player.GetPos());
			}
			else { // consume powder bag and convert cases

				int X = round(player.GetPos().x / TextWidth + 0.4);
				int Y = round(player.GetPos().y / TextWidth + 0.4);

				switch (player.GetDir())
				{
				case 'u':
					for (int i = player.GetPos().y/TextWidth; i > player.GetPos().y/ TextWidth - 5; i--) {
						lvl.SetMap(X, i, 4);
					}
					break;
				case 'd':
					for (int i = player.GetPos().y / TextWidth; i < player.GetPos().y / TextWidth + 5; i++) {
						lvl.SetMap(X, i, 4);
					}
					break;
				case 'r':
					for (int i = player.GetPos().x / TextWidth; i < player.GetPos().x / TextWidth + 5; i++) {
						lvl.SetMap(i, Y, 4);
					}
					break;
				case 'l':
					for (int i = player.GetPos().x / TextWidth; i > player.GetPos().x / TextWidth - 5; i--) {
						lvl.SetMap(i, Y, 4);
					}
					break;
				}
				player.SetPowderBag(false);
			}
		}
	
		if (key == 'p') {
			cout << key << endl;
			menu.Pause();
		}
	}
	else
	{

		if (key == ' ') {
			menu.Clicking();
		}

		if (key == 'p') {
			cout << key << endl;
			menu.Pause();
		}
	}
}


//-------------------------- PLAYER MOVEMENTS
void KeyAction(int key, int x, int y) {

		switch (key)
	{
	case GLUT_KEY_LEFT:
		player.SwitchDir('l');
		player.SetMoving(1);
		player.SetStillMoving(1);
		break;
	case GLUT_KEY_RIGHT:
		player.SwitchDir('r');
		player.SetMoving(1);
		player.SetStillMoving(1);
		break;
	case GLUT_KEY_UP:
		player.SwitchDir('u');
		player.SetMoving(1);
		player.SetStillMoving(1);
		break;
	case GLUT_KEY_DOWN:
		player.SwitchDir('d');
		player.SetMoving(1);
		player.SetStillMoving(1);
		break;
	}

}


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
//}

