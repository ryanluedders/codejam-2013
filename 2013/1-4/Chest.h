//
//  Chest.h
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2013 n/a. All rights reserved.
//

#ifndef _CHEST_H
#define _CHEST_H

#include <stdlib.h>
#include <vector>

class Chest
{
private:
	int mNumber;
	int mRequired;
	int mLocked;
	std::vector<int> mContains;

public:
	Chest();

	void setNumber
		(
		int aNumber
		);

	int getNumber();

	void setRequiredKey
		(
		int aType
		);

	int getRequiredKey();

	void insertKeys
		(
		std::vector<int> aKeys
		);

	void insertKeys
		(
		std::vector<std::string> aKeys
		);

	std::vector<int> getKeys();

	bool containsKey
		(
		int aType
		);

	void print();

	void setLocked
		(
		bool aLocked
		);

	bool getLocked();

};

#endif
