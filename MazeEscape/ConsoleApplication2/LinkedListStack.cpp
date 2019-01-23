#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>
#include "MazeCoordinate.h"
#include "LinkedListStack.h"


using namespace std;
//LinkedList implementation
LinkedListStack::LinkedListStack()
{
	top = NULL;

}

void LinkedListStack::push(MazeCoordinate maze)
{
	struct node *ptr;
	ptr = new node;
	ptr->cell = maze;

	if (top == NULL)
	{
		top = ptr;
		ptr->next = NULL;
	}
	else
	{
		ptr->next = top;
		top = ptr;
	}
}

MazeCoordinate LinkedListStack::pop()
{
	MazeCoordinate store;


	if (top == NULL) {
		cout << "Stack empty";
		return store;

	}
	else
	{
		store = top->cell;
		top = top->next;

		return store;
	}

}


void LinkedListStack::PrintStack()
{
	LinkedListStack tmpStack;
	MazeCoordinate temp;
	cout << "The solution of the puzzle is:" << endl;


	while (top != NULL)
	{
		temp = getTop();
		pop();
		tmpStack.push(temp);
	}

	while (tmpStack.top != NULL)
	{
		temp = tmpStack.pop();
		cout << temp.GetX() << " " << temp.GetY() << endl;
	}

}

MazeCoordinate LinkedListStack::getTop()
{
	MazeCoordinate store;


	if (top == NULL) {
		cout << "Stack empty";
		return store;

	}
	else
	{

		return top->cell;
	}
}


