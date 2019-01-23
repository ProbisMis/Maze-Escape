#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>

class MazeCoordinate
{
private:
	int xcoord, ycoord;
	bool visited;
	bool enterance;
	bool wall;

public:
	MazeCoordinate();
	MazeCoordinate(int, int);

	int GetX();
	int GetY();
	int SetX(int);
	int SetY(int);
	bool getEnterance();


	//checks if path valid (wall && visited)
	bool goDown(MazeCoordinate **mc);
	bool goRight(MazeCoordinate **mc);
	bool goLeft(MazeCoordinate **mc);
	bool goUp(MazeCoordinate **mc);

	//set them true if needed
	bool setWall(bool);
	bool setEntreance(bool);
	bool setVisited(bool);


	//how many nbr cell have
	int nbrCounter(int **ary, int xmax, int ymax);
	// if MazeCoordinate has valid(wall && visited) neighboor
	bool nbrAvailable(MazeCoordinate **mc);

	friend class LinkedListStack;

};