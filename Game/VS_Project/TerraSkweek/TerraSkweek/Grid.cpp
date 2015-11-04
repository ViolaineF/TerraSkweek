#include "Grid.h"

//-------------- CALL EXTERN VALUES

extern Player player;
extern float light;


Grid::Grid(string biome)
{
	m_biome = biome;

	m_score = 0;
	m_rows = 20;
	m_lignes = 20;

	int mapTemp[20][20] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
		1,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
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

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			map[i][j] = mapTemp[i][j];
		}
	}

	//------------------------LOAD SEMI CONVERTED CASE V1

	//for (int i = 0; i < m_rows; i++) {
	//	for (int j = 0; j < m_lignes; j++) {
	//		if (map[i][j] != 1) {
	//			int chance = rand() % 100 + 1; // Give an int between 1 and 100;

	//			if (chance == 1 && chance <= 5) {
	//				map[i][j] = 3; // Semi-converted case index
	//			}
	//		}
	//	}
	//}




	//------------------------LOAD ENEMY SPAWNER

//	vecCaseAnimated.push_back(new SpecialCase(10,10,"1forest/spawner"));


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
		vecTNT.push_back(new TNT(3, 3, 1));
		vecArrow.push_back(new Arrow(7, 7, 1, 'l'));
		vecArrow.push_back(new Arrow(7, 6, 1, 'r'));
		vecArrow.push_back(new Arrow(8, 5, 1, 'd'));
		vecArrow.push_back(new Arrow(8, 4, 1, 'd'));
		//vecCaseAnimated.push_back(new SpecialCase(2,5, "cracking"));
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

	if (a == 4) {
		vecCaseAnimated.push_back(new SimpleConversion(x, y, "conversion"));
	}
	else {
	}
		
}

void Grid::LoadAllTextures()
{

	string directory = "Art/" + m_biome + "/";

	//--------------BASE TEXTURES
	LoadGLTextures( directory + "ground.png"); // 0
	LoadGLTextures( directory + "walls.png"); // 1
	LoadGLTextures( "Art/converted.png"); // 2
	LoadGLTextures( "Art/semi_converted.png"); // 3
	LoadGLTextures( directory + "fall.png"); // 4



	//-------------------LOAD ENEMIES TEXTURES
	
	for (Enemy* c : vecEnemies)
	{
		c->LoadAllTextures();
	}

	for (TNT* d : vecTNT)
	{
		d->LoadAllTextures();
	}

	for (Arrow* e : vecArrow)
	{
		e->LoadAllTextures();
	}


	//------------------------LOAD SEMI-CONVERTED CASE 
	//------------------------LOAD CRACKED FLOOR
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_lignes; j++) {
			if (map[i][j] != 1) { // Avoid spwaning in a wall
				int chance = rand() % 100 + 1; // Give an int between 1 and 100;

				if (chance == 1 && chance <= 5) { // 5% chance ---------------------------------SEMI CONVERTED FLOOR
					map[i][j] = 3;
					vecCaseAnimated.push_back(new SemiConverted(i, j, "semiConverted"));
				}

				if (chance > 5 && chance <= 10) { // 5% chance ---------------------------------CRACKED FLOOR
					map[i][j] = 5;
					vecCaseAnimated.push_back(new CrackedFloor(i, j, "cracking"));
				}
			}
		}
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
	//--------------------------Ouvrir le fichier en �criture | supprimer ce qui est dedans avant d'ecrire
	ofstream fichier("Saves" + save, ios::out | ios::trunc);

	if (fichier)//-------------------Si le fichier existe, �crire
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
void Grid::PrintImg(int i, int j, int width, int height, int textureIt)
{
	glEnable(GL_TEXTURE_2D); // Start textures
	glBindTexture(GL_TEXTURE_2D, textures[textureIt]);
	glBegin(GL_QUADS);

	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex2d(i,j);
	glTexCoord2f(0.0f, 1.0f); glVertex2d(i + height+0.1, j);
	glTexCoord2f(1.0f, 1.0f); glVertex2d(i + height+ 0.1, j + width+ 0.1);
	glTexCoord2f(1.0f, 0.0f); glVertex2d(i, j + width+ 0.1);

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
				PrintImg(i, j, 1, 1, 0);
				break;
			case 1:// Wall
				PrintImg(i, j, 1, 1, 1);
				break;

			case 2:// Converted Floor
				PrintImg(i, j, 1, 1, 2);
				break;	

			case 3: // Semi-Converted animation
				PrintImg(i, j, 1, 1, 0); // Corrupted floor
				break;

			case 4 : // Conversion animation
				PrintImg(i, j, 1, 1, 0); // Corrupted floor
				break;

			case 5: // Cracked floor
				PrintImg(i, j, 1, 1, 0); // Corrupted floor
				break;

			case 6: // Fall
				PrintImg(i, j, 1, 1, 4); // Corrupted floor
				break;
			}
		}
	}// End drawing

}

void Grid::DrawSpecialCases()
{
	for (unsigned int i = 0; i < vecCaseAnimated.size(); i++) {

		if (vecCaseAnimated[i]->Draw()) {// If the animation is complete ...

			if (typeid(*vecCaseAnimated[i]) == typeid(SimpleConversion)) {
				SetMap(vecCaseAnimated[i]->GetPos().x, vecCaseAnimated[i]->GetPos().y, 2); // ... Convert floor
			}

			if (typeid(*vecCaseAnimated[i]) == typeid(CrackedFloor)) {
				SetMap(vecCaseAnimated[i]->GetPos().x, vecCaseAnimated[i]->GetPos().y, 6); // ... Convert floor
			}
			

			m_score = m_score + 1;	// SCORE + converted tile

			vecCaseAnimated.erase(vecCaseAnimated.begin() + i);// Destroy it
			i--;
		}
		else if (vecCaseAnimated[i]->GetPos() == player.GetPos()) {

			if (typeid(*vecCaseAnimated[i]) == typeid(CrackedFloor)) {
				vecCaseAnimated[i]->SetAnimated(true);

				//------------------PLAY SOUND
				sfx_gap.PlayAudio();
			}
		}
		
	}

	for (unsigned int i = 0; i < vecTNT.size(); i++) {
		vecTNT[i]->Draw();

	}

		///////////////////////////////////////////////////////////////////////////
	
	for (unsigned int i = 0; i < vecArrow.size(); i++) 
	{
		vecArrow[i]->Draw();

		if (vecCaseAnimated[i]->Draw()) 
		{// If the animation is complete ...


		}

		else if (vecCaseAnimated[i]->GetPos() == player.GetPos()) 
		{
			vecArrow[i]->activation(); // Player's movement forced in the direction of the Arrow
			cout << "moving" << endl;

			Position Player_pos = player.GetPos();

			if (vecArrow[i]->GetDir() == 'r')
			{
				Player_pos.x = Player_pos.x + 10;
				player.Teleport(Player_pos);
			}

			if (vecArrow[i]->GetDir() == 'l')
			{
				Player_pos.x = Player_pos.x - 10;
				player.Teleport(Player_pos);
			}
			if (vecArrow[i]->GetDir() == 'u')
			{
				Player_pos.x = Player_pos.y + 10;
				player.Teleport(Player_pos);
			}
			if (vecArrow[i]->GetDir() == 'd')
			{
				Player_pos.x = Player_pos.y - 10;
				player.Teleport(Player_pos);
			}

		}
	}
	

	

	///////////////////////////////////////////////////////////////////////////




	//---------- CHECK COLLISION WITH PLAYER - 1 player

	for (unsigned int i = 0; i < vecTNT.size(); i++) {
		if (vecTNT[i]->GetPos() == player.GetPos()) {
			vecTNT[i]->activation(); // Activation of TNT timer
		}
	}


	/*
	for (unsigned int i = 0; i < vecArrow.size(); i++) {

		if (vecArrow[i]->GetPos() == player.GetPos()) {
			vecArrow[i]->activation(); // Player's movement forced in the direction of the Arrow
			cout << "moving" << endl;

			
			Position Player_pos = player.GetPos();

			if (vecArrow[i]->GetDir() == 'r')
			{
				Player_pos.x = Player_pos.x + 1;
				player.Teleport(Player_pos);
			}
			if (vecArrow[i]->GetDir() == 'l')
			{
				Player_pos.x = Player_pos.x - 1;
				player.Teleport(Player_pos);
			}
			if (vecArrow[i]->GetDir() == 'u')
			{
				Player_pos.x = Player_pos.y + 1;
				player.Teleport(Player_pos);
			}			
			if (vecArrow[i]->GetDir() == 'd')
			{
				Player_pos.x = Player_pos.y - 1;
				player.Teleport(Player_pos);
			}
			//player.MoveDown();

			


			if (vecArrow[i]->GetDir() == 'r')
			{
				player.MoveRight();
				cout << "moving" << endl;
			}
			if (vecArrow[i]->GetDir() == 'l')
			{
				player.MoveLeft();
				cout << "moving" << endl;

			}
			if (vecArrow[i]->GetDir() == 'u')
			{
				player.MoveUp();
				cout << "moving" << endl;

			}
			if (vecArrow[i]->GetDir() == 'd')
			{
				player.MoveDown();
				cout << "moving" << endl;

			}


		}
	}
	*/

	//switch (map[player.GetPos().x][player.GetPos().y])
	//{
	//case 3 : // Semi-converted
	//	break;
	//case 5 : // Cracked Floor
	//	vecCaseAnimated[i]->SetAnimated(true);
	//	break;

	//}

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
				
				int dropType = rand() % 100 + 1; // Give an int between 1 and 100;

				if (dropType >= 1 && dropType <= 10) { // 50% chance to drop weapon 1
					vecWeapons.push_back(new Weapon(vecEnemies[i]->GetPos(), true, 1));// Create new weapon sprite
				}
				else if (dropType > 10 && dropType <= 50) {
					vecWeapons.push_back(new Weapon(vecEnemies[i]->GetPos(), true, 2));
				}
				else if (dropType > 50 && dropType <= 100) {
					vecWeapons.push_back(new Weapon(vecEnemies[i]->GetPos(), true, 3));
				}
							
			}
			
			vecEnemies.erase(vecEnemies.begin() + i);// Destroy enemy
			i--;
		}
	}

	//--------------- DRAW THE REMAINING ONES
	for (unsigned int i = 0; i < vecEnemies.size(); i++) {
		vecEnemies[i]->Draw();
	}
}


void Grid::MoveAllEnemies()
{
	for (unsigned int i = 0; i < vecTNT.size(); i++)
	{
		if (vecTNT[i]->GetPos() == player.GetPos()) {
			vecTNT[i]->activation(); // TNT is activated
		}
	}

	for (unsigned int i = 0; i < vecArrow.size(); i++)
	{
		if (vecArrow[i]->GetPos() == player.GetPos()) {
			vecArrow[i]->activation(); // arrow force is activated
		}
	}


	for (unsigned int i = 0; i < vecEnemies.size(); i++) {
		// Save previous position if it collides with a wall
		Position prevPos = { vecEnemies[i]->GetPos().x , vecEnemies[i]->GetPos().y , vecEnemies[i]->GetPos().z };

		//--------------------- MOVING ENEMIES
		if (vecEnemies[i]->Move(player.GetPos(), light)) { // If the enemy is moving, then move it and check, else check nothing
														  
		    //---------- CHECK COLLISION WITH PLAYER - 1 player
			if (vecEnemies[i]->GetPos() == player.GetPos()) {
				player.SetLife(player.GetLife() - vecEnemies[i]->GetDamage()); // Player's life is minus by the enemy's contact damage
				sfx_hit.PlayAudio();
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
					//vecWeapons[i]->SetCurrentFrame(1); // ... And start the impact animation
					return; // No need to check walls
				}
			}

			//----------- CHECK WALL COLLISION
			int pXleft = round(vecWeapons[i]->GetPos().x - 0.4);
			int pXright = round(vecWeapons[i]->GetPos().x + 0.4);
			int pYup = round(vecWeapons[i]->GetPos().y - 0.4);
			int pYdown = round(vecWeapons[i]->GetPos().y + 0.4);

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

void Grid::Pause()
{
}

void Grid::EndGame()
{
}
