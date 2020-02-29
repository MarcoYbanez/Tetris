#ifndef GAMEBOARD
#define GAMEBOARD

#include <vector>
#include <functional>
#include <memory>
#include <mutex>
#include "TetrisShape.h"

class GameBoard{

/*
	 Notes
	- May need to change next shape choice so it does not spwan the same piece twice

	Leaving off at running the threads within the class functions


	 issues to solve:
	

	### Creating a restriction so horizontal change does not surpass the boarder

	-	need to figure out what is going to be done about drawing the shape
		and changing the orientation of the shapes 

	- point system 
	- rotating shapes

	- clearing the the entire line

	### also figuring out how to prevent the previous row from clearing the field
			---> possible soultion is to check each element in that row for any values...
					However, Efficiency is the concern. Vector processes data through cache
						which benefits us a bit...

	- Restart defaultSpawn to be the center of the gri
			-> where  it is currently positioned only applies for the long 4 horizontatl
				Solution: use a get function to obtain the cetner of the new shape being spwaned


	### when speeding up settings are constantly resetting - cannot get peice to speed up
		could reset the settings when the input is changed to NULL
	Debug: 
	
	input char 

	Problem: 
	1) In the first video, my method of clearing the previous move was to access and overwrite one row up with blanks (aka spaces). However, this gave undesired results erasing game pieces that were OKAY. 
	2) The Game piece advances automatically by using a 1 sec thread execution delay. So, we access 4 coordinates in the 2D Vector, fill it with A's, wait a second, then fill the next 4 coordinates (one row down) with A's, repeat. In order to increase speed when the user select's 'down', we have to shorten the time delay for execution. The problem is both threads run independent from one another and the varialble I'm using to bridge the gap between both threads resets after 1 key press. I have to find a way to decrease the variable for only the time 'down' is pressed and not reset the value unitl 'down' is unpressed (harder than it sounds in a Linux/Unix enviroment)

	Solution: 
	1) I used a variable to keep track of the x-axis adjustment made by the user. So, when I went one row up, I went back to the original position the shape came from and filled it with blanks. Video 2 shows the result and what I was looking for. It's possible issues may arise when other shape types are introduced, but the required conditions for a shape to advance should take care of everything.  
	2) None yet

	#30DaysOfCode #cplusplus

	if(! getch()){}?
*/
/*
	The photo above is what the memory allocation of a C++ program looks like.
	Quick preface Note: I use "Allocate" and "Reserve" interchangeably. Compile-time: when your source code is being compiled into an executable program. Run-time: when your program is running. 


	You could now let your program run on it's own because it's designed to handle many inputs (technically, only as much as you're system can handle).

	Dynamic memory is reserving memory on the fly. The benefit is, if you're storing some data within your program, 

	
	static variables are defined at compile time, 

	Quick Explanation:
	
	The photo above is what the memory allocation of a C++ program looks like. AT COMPILE TIME, When variables are defined 
	they are put onto the "stack" as a memory address. Whenever you call that variable, you are actually calling that memory address which stores the value you set it to be. 
	I.E. if you define a integer variable named "some_number", and equal it to 5... you're computer reserved for you an address on the "stack" and that stores a value of number 5(This is known as a Static Variable). 
	In Layman's term's, your basically saying "Hey computer, I just made this program. Make sure to save some space in memory ('some space' varies in size depending on data type. Since I said integer, it's 4 bytes) and call it 'some_number'. Oh yea, and it equals 5."
	On the other hand, there's what's called Dynamic Variables. Dynamic variables are variables that are defined MANUALLY by the programmer and  are stored on the heap. The heap is large segment of memory just that is free game for you to use. The benefit of Dynamic 
	Variables is the system does not have to reserve memory at complile time. 

	address'.  

*/
	// std::mutex mtx;
	bool update = false; 
	int millisecondsControl = 1000;
	char UserInputchar;	
	int defaultSpawn = 4;	
	int adjustment = 0;
	int Score;
	bool endGame = false; 
	int runTime = 1; 
	bool SpawnNextPiece = false;
	std::vector < std::vector <std::string> > Board;
	// std::vector<std::unique_ptr< TetrisShape >> ShapeLibrary{7};
	int previousShapeIndex; 
	int getch();

public:

	  /////////////////
	 //	Constuctors //
	/////////////////
	GameBoard();
	~GameBoard();

	// friend class TetrisShape;

	  ///////////////////
	 // Functionality //
 	///////////////////
	void RunGame();
	void PrintGame();
	void AdvancePieces();
	void UserInput();
	void DrawAndEraseShape();


};

#endif