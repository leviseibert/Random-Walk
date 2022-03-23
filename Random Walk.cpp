// Random Walk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//open file
ofstream outputFile("RandomWalkData.txt");

//function prototypes
void reset(int island[][14], int &flowers, bool &over, int &r, int &c);
void move(int island[][14], int &r, int &c);
bool nextSpace(int island[][14], int &r, int &c, int &water, int &bridge, int &flowers);

//This function resets the island, the value of over, the number of flowers destroyed, and Harvey's starting position.
void reset(int island[][14], int &flowers, bool &over, int &r, int &c)
{
	//flowers = 0;
	int row, col;
	 
	//fill water around island
	for (col = 0; col < 14; col++)
	{
		island[0][col] = -1;
		island[14][col] = -1;
	}

	for (row = 0; row < 15; row++)
	{
		island[row][0] = -1;
		island[row][13] = -1;
	}

	//fill in flowers
	for (row = 1; row < 14; row++)
	{
		for (col = 1; col < 13; col++)
		{
			island[row][col] = 2;
		}
	}

	//fill in path
	for (col = 1; col < 13; col++)
	{
		island[7][col] = 0;
	}

	//fill in bridge
	island[7][0] = 3;
	island[7][13] = 3;

	//reset values;
	r = 7;
	c = 1;
	over = false;
	flowers = 0;
	return;
}

//This function gets a random number and determines which directionto step
void move(int island[][14], int &r, int &c)
{
	int random;

	//generate random number from 0-99
	random = rand() % 100;

	if (random <= 43)
	{
		c++;
	}

	else if (random <= 70)
	{
		r++;
	}

	else if (random <= 91)
	{
		r--;
	}

	else
	{
		c--;
	}

	return;
}

//This function moves Harvey and checks if he steps in the water, on the bridge, or on a flower
bool nextSpace(int island[][14], int &r, int &c, int &water, int &bridge, int &flowers)
{
	if (island[r][c] == 3)
	{
		bridge++;
		return true;
	}

	if (island[r][c] == -1)
	{
		water++;
		return true;
	}

	if (island[r][c] != 0)
	{
		island[r][c]--;
		flowers++;
		return false;
	}

	if (island[r][c] == 0)
	{
		return false;
	}
}

int main()
{
	//declare array
	int island[15][14];

	//declare and define variables
	bool over = false;
	int i;
	int row = 7;
	int column = 1;
	int water = 0;
	int bridge = 0;
	int flowers = 0;
	long int totalCost = 0;
	
	//run 7000 times
	for (i = 0; i < 7000; i++)
	{
		//reset data
		reset(island, flowers, over, row, column);

		while (!over)
		{
			move(island, row, column);
			over = nextSpace(island, row, column, water, bridge, flowers);
			totalCost += flowers * 4;
			flowers = 0;
		}

	}

	outputFile << "Harvey's average cost of walking is $" << setprecision(2) << fixed << showpoint << (totalCost / 7000) << endl;
	outputFile << "Harvey made it across the island " << bridge << " times." << endl;
	outputFile << "Harvey had to be rescued from the water " << water << " times." << endl;

	return 0;
}