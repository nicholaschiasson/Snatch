/* worldClass ::: Luke Harper */

#ifndef WORLDCLASS_H
#define WORLDCLASS_H

#include "arraylist.h"
#include "integer.h"
#include "levelclass.h"
#include "PlayerClass.h"
#include "enemyobject.h"
#include "soundclass.h"
#include <iterator>
#include <math.h>
#include <vector>
#include <ctime>

class WorldClass
{
public:
	WorldClass(HWND);
	~WorldClass();
	bool initializeSound(HWND);
	void runGame();
	void toggleFloor();
	void doAction();
	bool isWall(int, int);

	void resetLevel();
	
	/*********
	*	Function:	checkLight
	*	out:		boolean whether light is on or off
	*	Purpose:	to check location of the player and determine if that floor is lit up.
	**********/
	bool checkLight();
	void updatePlayer(float, float);

	ArrayList<GameModel> getModels(); //models to be sent back to the system for rendering.

	/************
	*	Function:	Get Player
	*	Purpose:	Returns the Player as a pointer.
	************/
	PlayerClass* getPlayer();

	/************
	*	Function:	GetPlayerStartX
	*	Purpose:	Returns the world co-ordinates of the start position for the player.
	************/
	float getPlayerStartX();
	/************
	*	Function:	GetPlayerStartX
	*	Purpose:	Returns the world co-ordinates of the start position for the player.
	************/
	float getPlayerStartY();
	/************
	*	Function:	GetPlayerStartX
	*	Purpose:	Returns the world co-ordinates of the start position for the player.
	************/
	float getPlayerStartZ();

	void UpdatePlayerWalk(bool);

	bool GameMenu();
	bool GamePlaying();
	bool GameOver();
	void StartGame();

private:
	//objects
	LevelClass* level;
	GameModel* floor[100][100];
	GameModel* roof[100][100];

	ArrayList<EnemyObject> enemies;

	PlayerClass* player;

	//sound
	SoundClass* sound;

	//world variables
	bool winGame;

	//functions

	//setting up the default world.
	void initalizeWorld();
	void initalizeRoof();
	void initalizeFloor();

	/************	
	*	Function:	ConvertToInt
	*	in:			number as a float
	*	out:		number as an int
	*	Purpose:	To convert a number from float to int
	************/
	int convertToInt(float);

	//removing the world
	void Shutdown();

	void Menu();
	void playGame();
	void advanceLevel();
	void endGame();
	void updateLight(int,int);
	void scan(int, int);

	void FollowPath(EnemyObject*, vector<int>);
	void FindPath(int, int, int, int, vector<int>&, EnemyObject*);	
	vector<int> convertPath(int, int, vector<XMINT2>&, EnemyObject*);
	bool playerWalking;
	bool playerSeen;

	time_t startTime;
	time_t suspicionTime;
	GameState gameState;
};

#endif
