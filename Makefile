CC=g++ -std=c++14

all: RunTetris

RunTetris: Tetris.o TetrisShape.o GameBoard.o
	$(CC) Tetris.o TetrisShape.o GameBoard.o -o RunTetris

Tetris.o: Tetris.cpp
	$(CC) -c Tetris.cpp

TetrisShape.o: TetrisShape.cpp
	$(CC) -c TetrisShape.cpp

GameBoard.o: GameBoard.cpp
	$(CC) -c GameBoard.cpp

clean: 
	rm -rf *.o RunTetris