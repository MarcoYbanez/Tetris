#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

#include "GameBoard.h"

/*
	Game twitching has been resolved. 
	while loop within advance game piece that doesn;t advance the piece until printing
	has changed the update value



	To do (12/25/19)
		- figure out how the program ran snoothly
		 . Was it a timing delay?
		- figure out game plan for the game piece orientation
			. which method.
		- after pressing down, need to reset the speed so it doesn't lkeep updateoing


	Checklist for tetris
	--> go back and change update to mutex/atomic lock

	- create layout 
	- data base for shapes
	- rotating the shapes
	- score
	- level failure


	--> Questions to think abut: 

	- How to make an object 

	--> Possible ideas to implement
		- 2D array? 

*/


/*
	Actual game 2D Array

	std::string BackGround[Down][Across] = { 
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "},
		{" ", " ", " ", " ", " "}		
	};	
*/



/*
	CURRRENT GAME NOTES: 12/24/19
	 - Game runs with a fixed piece position at start up

	 	--> need to figure out a way to spawn random pieces
	 			and up date position of piece depending on key press.

	 	--> Potentially mutex/atomic fuctions required for a game piece rotation
*/


#define Down 20
#define Across 12
#define OneSec 1

void print(std::string BackGround[][Across]){

	for(int i = 0; i < Down; ++i){
		for(int j = 0; j < Across; ++j){

			std::cout << BackGround[i][j];
		}
		std::cout << std::endl; 

	}	
}

void pause(){
	std::cout << "Out\n"; 
	std::cin.ignore(100, '\n');

}

int main(){

	GameBoard Game;
	Game.RunGame();



	// std::string BackGround[Down][Across] = { 
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"║", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", u8"║"},
	// 	{u8"╚", u8"═",  u8"═", u8"═", u8"═", u8"═", u8"═", u8"═", u8"═", u8"═", u8"═", u8"╝"}		
	// };

	// clock_t start = clock();
	// clock_t end;

	// int gameClock = 0;
	// int previousTime = 0; 

	// int firstRow = 1; 

	// system("clear");






	// do{

	// 		/* Restart clock if the bottom is reached */
	// 	if(gameClock == Down-2){ start = clock(); }		
		
	// 	end = clock();
	// 	previousTime = gameClock;
	// 	gameClock = (int)(end - start) / CLOCKS_PER_SEC;
	// 	gameClock += 1;	

	// 	if(gameClock % OneSec == 0 && gameClock != previousTime){

	// 		if(BackGround[gameClock][4] == " "){
	// 			//Print piece 
	// 			BackGround[gameClock][4] = "A";
	// 			BackGround[gameClock][5] = "A";
	// 			BackGround[gameClock][6] = "A";
	// 			BackGround[gameClock][7] = "A";

	// 			//Erase previous piece
	// 			BackGround[gameClock-1][4] = " ";
	// 			BackGround[gameClock-1][5] = " ";
	// 			BackGround[gameClock-1][6] = " ";
	// 			BackGround[gameClock-1][7] = " ";
	// 		}
	// 		else{
	// 			start = clock();

	// 		}

	// 		print(BackGround);

	// 		std::cout << gameClock << std::endl;
	// 	}
	// }while (gameClock <= Down-2);



	return 0; 
}