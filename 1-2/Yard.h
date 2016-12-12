//
//  Yard.h
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2013 n/a. All rights reserved.
//

#ifndef _YARD_H
#define _YARD_H

#include <stdlib.h>
#include <vector>

class Yard
{
private:
	int height;
	int width;

	std::vector< std::vector<int> > grid;

public:
	Yard
		(
		int aH,
		int aW
		);

	void fillRow
		(
		int aR,
		std::vector<std::string> aVals
		);

	void print();

	int result();

};

#endif
