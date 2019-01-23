#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>
#include "MazeCoordinate.h"

class LinkedListStack {
private:
	struct node
	{
		MazeCoordinate cell;
		node* next;

	};
	node *top;
public:
	LinkedListStack();

	void push(MazeCoordinate  maze);
	MazeCoordinate pop();
	void PrintStack();
	MazeCoordinate getTop();




	friend class MazeCoordinate;

};
