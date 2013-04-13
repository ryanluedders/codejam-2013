//
//  Yard.cpp
//

#include <iostream>
#include "Yard.h"

Yard::Yard
	(
	int aH,
	int aW
	)
{
	grid.resize(aH);
	for(int i=0; i < grid.size(); i++)
	{
		grid[i].resize(aW);
	}
	height = aH;
	width = aW;
}

void Yard::fillRow
	(
	int aR,
	std::vector<std::string> aVals
	)
{
	for(int i=0; i < aVals.size(); i++)
	{
		grid[aR][i] = std::atoi(aVals[i].c_str());
	}
}

void Yard::print()
{
	for(int i=0; i < height; i++)
	{
		for(int j=0; j < width; j++)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
}

int Yard::result()
{
	bool ok = true;

	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{

		}
	}

	return ok;
}

