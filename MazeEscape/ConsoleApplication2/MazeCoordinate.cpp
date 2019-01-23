#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>
#include "MazeCoordinate.h"

using namespace std;

//MazeCoordinate implementation
MazeCoordinate::MazeCoordinate()
{
	visited = false;
	wall = false;
	enterance = false;
}

MazeCoordinate::MazeCoordinate(int x, int y)
{
	xcoord = x;
	ycoord = y;
	visited = false;
	wall = false;
	enterance = false;
}

int MazeCoordinate::GetX()
{
	return  xcoord;
}

int MazeCoordinate::GetY()
{
	return ycoord;
}

int MazeCoordinate::SetX(int x)
{
	xcoord = x;
	return xcoord;
}

int MazeCoordinate::SetY(int y)
{
	ycoord = y;
	return ycoord;
}

bool MazeCoordinate::getEnterance()
{
	return enterance;
}

bool MazeCoordinate::goRight(MazeCoordinate **mc)
{
	if (((mc[xcoord][ycoord + 1].wall == false) && (mc[xcoord][ycoord + 1].visited == false)))
		return true;
	else
	{
		return false;
	}
}

bool MazeCoordinate::goDown(MazeCoordinate **mc)
{
	if (mc[xcoord + 1][ycoord].wall == false && mc[xcoord + 1][ycoord].visited == false)
		return true;
	else
	{
		return false;
	}
}

bool MazeCoordinate::goUp(MazeCoordinate **mc)
{
	if (mc[xcoord - 1][ycoord].wall == false && mc[xcoord - 1][ycoord].visited == false)
		return true;
	else
	{
		return false;
	}
}

bool MazeCoordinate::goLeft(MazeCoordinate **mc)
{
	if (mc[xcoord][ycoord - 1].wall == false && mc[xcoord][ycoord - 1].visited == false)
		return true;
	else
	{
		return false;
	}
}

bool MazeCoordinate::setWall(bool a)
{
	if (a == true)
		return wall = true;
	else
	{
		return wall = false;
	}
}

bool MazeCoordinate::setEntreance(bool a)
{
	if (a == true)
		return enterance = true;
	else
	{
		return enterance = false;
	}
}

bool MazeCoordinate::setVisited(bool a)
{
	if (a == true)
		return visited = true;
	else
	{
		return visited = false;
	}
}

int MazeCoordinate::nbrCounter(int ** ary, int xmax, int ymax)
{
	int count = 0;
	if ((ycoord< ymax - 1) && (ary[xcoord][ycoord + 1] == 0 || ary[xcoord][ycoord + 1] == 1))
	{
		count++;
	}
	if ((xcoord < xmax - 1) && (ary[xcoord + 1][ycoord] == 0 || ary[xcoord + 1][ycoord] == 1))
		count++;
	if ((ycoord >= 1) && (ary[xcoord][ycoord - 1] == 0 || ary[xcoord][ycoord - 1] == 1))
		count++;
	if ((xcoord >= 1) && (ary[xcoord - 1][ycoord] == 0 || ary[xcoord - 1][ycoord] == 1))
		count++;

	return count;


}

bool MazeCoordinate::nbrAvailable(MazeCoordinate ** mc)
{
	if (goDown(mc) == false && goRight(mc) == false && goLeft(mc) == false && goUp(mc) == false)
		return false;
	else
	{
		return true;
	}
}
