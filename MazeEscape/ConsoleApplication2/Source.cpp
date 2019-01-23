// 19016BurakMerichw1.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>
#include "MazeCoordinate.h"
#include "LinkedListStack.h"

using namespace std;

//Maze generator with 1s and 0s
void AnotherMazeGenerator(int **ary, int xstart, int ystart, int xcoord, int ycoord, MazeCoordinate **mc) {


	//mc[i][j].visited = true;
	for (int i = 0; i < xcoord; i++)
		for (int j = 0; j < ycoord; j++)
		{
			ary[i][j] = 1;
			mc[i][j].setWall(true);
			mc[i][j].SetX(i);
			mc[i][j].SetY(j);
		}



	for (int i = 0; i < xcoord - 2; i++)
	{

		ary[i][ystart] = 0;
		mc[i][ystart].setWall(false);
		mc[i][ystart].setVisited(false);
		mc[i][ystart].SetX(i);
		mc[i][ystart].SetY(ystart);

	}

	for (int i = 1; i < xcoord; i++)
	{
		ary[i][ystart + 2] = 0;
		mc[i][ystart + 2].setWall(false);
		mc[i][ystart + 2].setVisited(false);
		mc[i][ystart + 2].SetX(i);
		mc[i][ystart + 2].SetY(ystart + 2);
	}


	for (int i = 1; i < ycoord - 2; i++)
	{

		ary[3][i] = 0;
		mc[3][i].setWall(false);
		mc[3][i].setVisited(false);
		mc[3][i].SetX(3);
		mc[3][i].SetY(i);

	}
} // test maze generator

//will print the maze 
void PrintMaze(int **ary, int xcoord, int ycoord, MazeCoordinate **mc) {
	//This code prints the maze.
	for (int i = 0; i<xcoord; ++i)
	{
		for (int j = 0; j<ycoord; ++j)
		{
			std::cout << ary[i][j] << " ";

		}
		std::cout << "\n";
	}

}

//will solve the maze
bool solve(MazeCoordinate **mc, LinkedListStack stack, int x, int y, int **ary, int xmax, int ymax) {



	MazeCoordinate Cell = mc[x][y];

	//End Condition
	if ((Cell.getEnterance() == false) && (Cell.nbrCounter(ary, xmax, ymax) != 4))
	{
		stack.PrintStack();

		return true;
	}

	if (Cell.goDown(mc) == true)
	{
		mc[x + 1][y].setVisited(true);
		stack.push(mc[x + 1][y]);
		solve(mc, stack, x + 1, y, ary, xmax, ymax);

		return true;
	}
	else if (Cell.goRight(mc) == true)
	{
		mc[x][y + 1].setVisited(true);
		stack.push(mc[x][y + 1]);
		solve(mc, stack, x, y + 1, ary, xmax, ymax);

		return true;
	}
	else if (Cell.goLeft(mc) == true)
	{
		mc[x][y - 1].setVisited(true);
		stack.push(mc[x][y - 1]);
		solve(mc, stack, x, y - 1, ary, xmax, ymax);

		return true;
	}
	else if (Cell.goUp(mc) == true)
	{
		mc[x - 1][y].setVisited(true);
		stack.push(mc[x - 1][y]);
		solve(mc, stack, x - 1, y, ary, xmax, ymax);

		return true;
	}
	else
	{
		stack.pop();

		MazeCoordinate temp = stack.getTop();
		Cell = temp;
		x = Cell.GetX();

		y = Cell.GetY();
		solve(mc, stack, x, y, ary, xmax, ymax);
	}

	//



}


int main()
{
	int xcoord, ycoord, xstart, ystart;
	cin >> xcoord >> ycoord;
	cin >> xstart >> ystart;


	//2D array for integer represantation of maze
	int **ary = new int*[xcoord];
	for (int i = 0; i < xcoord; ++i)
		ary[i] = new int[ycoord];

	//2D array for cells
	MazeCoordinate **mc = new MazeCoordinate*[xcoord];
	for (int i = 0; i < xcoord; ++i)
		mc[i] = new MazeCoordinate[ycoord];


	
	int value;

		for (int i = 0; i < xcoord; i++)
		{
		for (int j = 0; j < ycoord; j++)
		{
			cin >> value;
			if (value == 1)
			{
				ary[i][j] = 1;
				mc[i][j].setWall(true);
				mc[i][j].SetX(i);
				mc[i][j].SetY(j);
			}
			else
			{
				ary[i][j] = 0;
				mc[i][j].setWall(false);
				mc[i][j].setVisited(false);
				mc[i][j].SetX(i);
				mc[i][j].SetY(j);
			}
		}
	}





	//AnotherMazeGenerator(ary, xstart, ystart, xcoord, ycoord, mc);  //For testing the maze 
	PrintMaze(ary, xcoord, ycoord, mc);

	mc[xstart][ystart].setEntreance(true);
	LinkedListStack stack;
	stack.push(mc[xstart][ystart]);
	solve(mc, stack, xstart, ystart, ary, xcoord, ycoord);




	system("pause");
	return 0;
}

