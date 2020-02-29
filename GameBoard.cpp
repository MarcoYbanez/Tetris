#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <functional>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "GameBoard.h"

  ///////////////////////////////////////////////////////////
 //											Constructors											//
///////////////////////////////////////////////////////////
GameBoard::GameBoard(): Board{ 20, std::vector<std::string>{12, " "} }{

	/* Algortithm to plot Board of game */ 

		for(int i = 0; i < 19; ++i){
			Board[i][0] = u8"║";
			Board[i][11] = u8"║"; 
		}
		for(int i = 1; i < 11; ++i){
			Board[19][i] = u8"═";
		}
		Board[19][0] = u8"╚";
		Board[19][11] = u8"╝";	
	// ShapeLibrary[0] = new
	// ShapeLibrary[1] = new
	// ShapeLibrary[2] = new 
	// ShapeLibrary[3] = new 
	// ShapeLibrary[4] = new
	// ShapeLibrary[5] = new
	// ShapeLibrary[6] = new

}

GameBoard::~GameBoard(){
	// for(auto i = ShapeLibrary.begin(); i!= ShapeLibrary.end(); ++i){
	// 	delete *i; 
	// }
}

  ///////////////////////////////////////////////////////////
 //											Functionality 										//
///////////////////////////////////////////////////////////
void GameBoard::PrintGame(){

	do{

		// std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		if(update){
				system("clear");
				for(auto i = Board.begin(); i != Board.end(); ++i){
					for(auto j = i->begin(); j != i->end(); ++j){
						std::cout << *j;
					}
					std::cout << std::endl;
				}
			// std::cout << "defaultSpawn: " << defaultSpawn << std::endl << "adjustment: " << adjustment <<std::endl; 
			// std::cout << "UserInputChar: " << UserInputchar <<std::endl << "runTime: " << runTime <<std::endl;
			// if(SpawnNextPiece){std::cout << "Next Piece Spawned\n";}
			if(update){update = false;}	

		}
	}while(!endGame); 

}

void DrawAndEraseShape(const char& orientation){//Necessary because this depends on orientation
	

	// switch(orientation){

	// 	case '': {

	// 	};break; 
	// 	case '': {

	// 	};break;
	// 	case '': {

	// 	};break;
	// 	case '': {

	// 	};break; 
	// }



		// if(Board[runTime][4] == " "){
		// Board[runTime][4] = "A";
		// Board[runTime][5] = "A";
		// Board[runTime][6] = "A";
		// Board[runTime][7] = "A";

		// //Erase previous piece
		// Board[runTime-1][4] = " ";
		// Board[runTime-1][5] = " ";
		// Board[runTime-1][6] = " ";
		// Board[runTime-1][7] = " ";


}

void GameBoard::UserInput(){
/* Game piece speed only increases when 'down' is pressed --> Time should reset  */
	do{

		UserInputchar = '0';

		// if(std::cin >> UserInput){
			//Might need to set mutex to lock values here

		// }

 		UserInputchar = getch();
 		update = true;

 		// std::cout << "UserInputchar: '" << UserInputchar << "'" <<std::endl;

		switch(UserInputchar){
			case 'a': { //Need to set conditions here or in drawing for the maximum that 
									// the user can modify 
				millisecondsControl = 1000;
				if(defaultSpawn > 1){
					--defaultSpawn;
					--adjustment;					
				}

			};break;
			case 'd': {
				millisecondsControl = 1000;
				if(defaultSpawn < 7){
					++defaultSpawn;
					++adjustment;					
				}

			};break;
			case 's': {
				millisecondsControl = 200;
				// std::this_thread::sleep_for(std::chrono::milliseconds(1000));

			};break; 
			case ' ': { millisecondsControl = 0;};break;
			case 'q': {endGame = true;};break;
		}
		update = false; 

	}while(UserInputchar != 'q');

}

void GameBoard::AdvancePieces(){

	//Each pice consiss of 4 sub pieces
	int subPiece1;
	int subPiece2;
	int subPiece3;
	int subPiece4;

	do{
		if(SpawnNextPiece){ millisecondsControl = 1000; SpawnNextPiece = false;}

		/* draw shpae */



		// int subPiece1 = /*SpawnedShape.getCoord1*/;
		// int subPiece2;
		// int subPiece3;
		// int subPiece4;

		// DrawAndEraseShape();
		if(Board[runTime][defaultSpawn] == " " && Board[runTime][defaultSpawn + 1] == " " && Board[runTime][defaultSpawn+2] == " " && Board[runTime][defaultSpawn +3] == " "){
			// if(orientation == 1){
				Board[runTime][defaultSpawn] = "A";
				Board[runTime][defaultSpawn + 1] = "A";
				Board[runTime][defaultSpawn + 2] = "A";
				Board[runTime][defaultSpawn + 3] = "A";

				//Erase previous piece
				if(adjustment != 0 ){
					Board[runTime-1][defaultSpawn - adjustment] = " ";
					Board[runTime-1][defaultSpawn - adjustment+1] = " ";
					Board[runTime-1][defaultSpawn - adjustment+2] = " ";
					Board[runTime-1][defaultSpawn - adjustment+3] = " ";
					adjustment = 0;
				}
				else{
					Board[runTime-1][defaultSpawn] = " ";
					Board[runTime-1][defaultSpawn + 1] = " ";
					Board[runTime-1][defaultSpawn + 2] = " ";
					Board[runTime-1][defaultSpawn + 3] = " ";
				}

				// Board[runTime-1][10] = " ";
			// }
				update = true;
		}
		else{
			
			SpawnNextPiece = true;
			defaultSpawn = 4;
			millisecondsControl = 1000;
			runTime = 1; 
		}
		++runTime;
		update = true; 			//Once update has been set to true, it needs to hold here temp until it's been set to false....
												//But how. --> while loop? if is a check condition. while loop can work, but it cwould be inefficientwd
		while(update){}
		std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsControl));
		// update = false;


	}while(!endGame);

}

void GameBoard::RunGame(){

	/* 
			Spwan Thread 1						Spawn Thread 2 
			- Print game baoard				- Wait for user input 
			- Erasing happens here		- input sends signal to change next shaoes coordinates
																	--> roatate 
																- Spawn thread 3 for user control 
	*/
	std::thread PrintThread(&GameBoard::PrintGame, this);
	std::thread AdvancePiecesThread(&GameBoard::AdvancePieces, this);
	std::thread UserInputThread(&GameBoard::UserInput, this);


	PrintThread.join();
	AdvancePiecesThread.join();
	UserInputThread.join();

}

int GameBoard::getch(){
	struct termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;
}



  ///////////////////////////////////////////////////////////
 //											Main Window												//
///////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////
 //											Main Window												//
///////////////////////////////////////////////////////////