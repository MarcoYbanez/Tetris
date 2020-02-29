#include <vector>
#include <string>
#include "TetrisShape.h"

  /////////////////////////////////////////////////////////
 //											Tetris Shape 										//
/////////////////////////////////////////////////////////
void TetrisShape::ResetShapeOrientation(){ orientation = 0; }
int TetrisShape::getSubPiece1(){return SubPieceCoordinates[0];}
int TetrisShape::getSubPiece2(){return SubPieceCoordinates[1];}
int TetrisShape::getSubPiece3(){return SubPieceCoordinates[2];}
int TetrisShape::getSubPiece4(){return SubPieceCoordinates[3];}

  /////////////////////////////////////////////////////////////
 //											#1 Tetris Shape #1									//
/////////////////////////////////////////////////////////////
TetrisShape1::TetrisShape1(){
/*
		AAAA
*/
}
// virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn);
//The problem in compiling is the definition within the cpp file, user inout is passed

/*

	As of now there should be fixed position values for the positions, how would we model the change of shape when key pressed. 


	---->	Atomic and mutex??
	during key press for postion change, can we mutex lock SOMETHING so we can have a successful position change...

*/

void TetrisShape1::DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput) {
// Dependent on run time and defaultSpawn

//switch(orientation){
/*
	Draws the  shape onto the 2D array
*/	

// userinput and control can be seen by this function.


	// switch(orientation){
	// 	case 0:{};break;
	// 	case 1:{};break;
	// 	case 2:{};break;
	// 	case 3:{};break;
	// }




}

  /////////////////////////////////////////////////////////////
 //											#2 Tetris Shape #2									//
/////////////////////////////////////////////////////////////
/*  
	AA
	AA
*/
TetrisShape2::TetrisShape2(){

}

void TetrisShape2::DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput) {
	char v = '4';
}



  /////////////////////////////////////////////////////////////
 //											#3 Tetris Shape #3									//
/////////////////////////////////////////////////////////////
TetrisShape3::TetrisShape3(){
/*
		AA
		 AA	
*/
}

void TetrisShape3::DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput) {
}


  /////////////////////////////////////////////////////////////
 //											#4 Tetris Shape #4									//
/////////////////////////////////////////////////////////////
/*
		AA
	 AA
*/

TetrisShape4::TetrisShape4(){

}

void TetrisShape4::DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput) {
	char T = 'v';
}

  /////////////////////////////////////////////////////////////
 //											#4 Tetris Shape #4									//
/////////////////////////////////////////////////////////////
/*
	A
	A
	AA
*/

TetrisShape5::TetrisShape5(){

}

void TetrisShape5::DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput) {
	char T = 'v';
}


  /////////////////////////////////////////////////////////////
 //											#4 Tetris Shape #4									//
/////////////////////////////////////////////////////////////
/*
	 A
	 A
	AA
*/

TetrisShape6::TetrisShape6(){

}

void TetrisShape6::DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput) {
	char T = 'v';
}

  /////////////////////////////////////////////////////////////
 //											#4 Tetris Shape #4									//
/////////////////////////////////////////////////////////////
/*
	 A
	AAA 
*/

TetrisShape7::TetrisShape7(){

}

void TetrisShape7::DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput) {


}
