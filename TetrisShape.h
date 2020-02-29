#ifndef TETRISSHAPE
#define TETRISSHAPE

#include <vector>
#include <string>

  /////////////////////////////////////////////////////////
 //											Tetris Shape 										//
/////////////////////////////////////////////////////////
class TetrisShape{
	std::vector<int> SubPieceCoordinates;
	int orientation = 0; 
	bool resetOrientation = false;

public:
	TetrisShape(){
		for(int i = 0; i < 4; ++i){
			SubPieceCoordinates.push_back(i); 

		}
	}
	~TetrisShape(){}

	virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput) = 0;
	void ResetShapeOrientation();

	int getSubPiece1();
	int getSubPiece2();
	int getSubPiece3();
	int getSubPiece4();

};

  /////////////////////////////////////////////////////////////
 //											#1 Tetris Shape #1									//
/////////////////////////////////////////////////////////////
class TetrisShape1: public TetrisShape{
public:
	TetrisShape1();
	virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput);
}; 


  /////////////////////////////////////////////////////////////
 //											#2 Tetris Shape #2									//
/////////////////////////////////////////////////////////////
class TetrisShape2: public TetrisShape{
public:
	TetrisShape2();
	 virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput);
}; 


  /////////////////////////////////////////////////////////////
 //											#3 Tetris Shape #3									//
/////////////////////////////////////////////////////////////
class TetrisShape3: public TetrisShape{
public:
	TetrisShape3();
	virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput);

}; 


  /////////////////////////////////////////////////////////////
 //											#4 Tetris Shape #4									//
/////////////////////////////////////////////////////////////
class TetrisShape4: public TetrisShape{
public:
	TetrisShape4();
	virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput);
}; 

  /////////////////////////////////////////////////////////////
 //											#5 Tetris Shape #5									//
/////////////////////////////////////////////////////////////
class TetrisShape5: public TetrisShape{
public:
	TetrisShape5();
	virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput);
}; 

  /////////////////////////////////////////////////////////////
 //											#6 Tetris Shape #6									//
/////////////////////////////////////////////////////////////
class TetrisShape6: public TetrisShape{
public:
	TetrisShape6();
	virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput);
}; 

  /////////////////////////////////////////////////////////////
 //											#7 Tetris Shape #7									//
/////////////////////////////////////////////////////////////
class TetrisShape7: public TetrisShape{
public:
	TetrisShape7();
	virtual void DrawShape(std::vector <std::vector <std::string >>& Board, const int& runTime, const int& defaultSpawn, const char& userInput);
}; 

#endif