//
//  Chest.cpp
//

#include <iostream>
#include "Chest.h"

Chest::Chest()
{
}

void Chest::setNumber
	(
	int aNumber
	)
{
	mNumber = aNumber;
}

int Chest::getNumber()
{
	return mNumber;
}

void Chest::setRequiredKey
	(
	int aType
	)
{
	mRequired = aType;
}

int Chest::getRequiredKey()
{
	return mRequired;
}

void Chest::insertKeys
	(
	std::vector<int> aKeys
	)
{
	mContains = aKeys;
}


void Chest::insertKeys
	(
	std::vector<std::string> aKeys
	)
{
	mContains.clear();
	for(int i=0; i<aKeys.size(); i++)
	{
		mContains.push_back(std::atoi(aKeys[i].c_str()));
	}
}

std::vector<int> Chest::getKeys()
{
	return mContains;
}

bool Chest::containsKey
	(
	int aType
	)
{
	bool contains = false;
	for(int i=0; i<mContains.size(); i++)
	{
		if( aType == mContains[i] )
		{
			contains = true;
			break;
		}
	}
	return contains;
}

void Chest::setLocked
	(
	bool aLocked
	)
{
	mLocked = aLocked;
}

bool Chest::getLocked()
{
	return mLocked;
}

void Chest::print()
{
	std::cout << "Required Key: " << mRequired << std::endl;
	std::cout << "Contains: ";
	for(int i=0; i<mContains.size(); i++)
	{
		std::cout << mContains[i] << " ";
	}
	std::cout << std::endl;
}
