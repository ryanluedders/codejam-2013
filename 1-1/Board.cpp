//
//  Board.cpp
//

#include <iostream>
#include "Board.h"

char* Board::key = "TXO.";

void Board::loadRow
	(
	int row,
	const char * state
	)
{
	for(int i = 0; i < COL_COUNT; i++)
	{
		for(int j = 0; j < MAX_STATES; j++)
		{
			if(state[i] == key[j])
			{
				spaces[row][i] = j;
			}
		}
	}
}

void Board::print()
{
	for(int i = 0; i < ROW_COUNT; i++)
	{
		for(int j = 0; j < COL_COUNT; j++)
		{
			std::cout << key[spaces[i][j]];
		}
		std::cout << std::endl;
	}
}

int Board::result()
{
	int retn_val = NOT_OVER;
	bool O = false;
	bool X = false;
	bool ip = false;

	for(int i = 0; i < ROW_COUNT; i++)
	{
		if( ( spaces[i][0] == STATE_X || spaces[i][0] == STATE_T ) &&
			( spaces[i][1] == STATE_X || spaces[i][1] == STATE_T ) &&
		    ( spaces[i][2] == STATE_X || spaces[i][2] == STATE_T ) &&
			( spaces[i][3] == STATE_X || spaces[i][3] == STATE_T ) )
		{
			X = true;
		}
		if( ( spaces[i][0] == STATE_O || spaces[i][0] == STATE_T ) &&
			( spaces[i][1] == STATE_O || spaces[i][1] == STATE_T ) &&
		    ( spaces[i][2] == STATE_O || spaces[i][2] == STATE_T ) &&
			( spaces[i][3] == STATE_O || spaces[i][3] == STATE_T ) )
		{
			O = true;
		}
	}

	for(int i = 0; i < COL_COUNT; i++)
	{
		if( ( spaces[0][i] == STATE_X || spaces[0][i] == STATE_T ) &&
			( spaces[1][i] == STATE_X || spaces[1][i] == STATE_T ) &&
		    ( spaces[2][i] == STATE_X || spaces[2][i] == STATE_T ) &&
			( spaces[3][i] == STATE_X || spaces[3][i] == STATE_T ) )
		{
			X = true;
		}
		if( ( spaces[0][i] == STATE_O || spaces[0][i] == STATE_T ) &&
			( spaces[1][i] == STATE_O || spaces[1][i] == STATE_T ) &&
		    ( spaces[2][i] == STATE_O || spaces[2][i] == STATE_T ) &&
			( spaces[3][i] == STATE_O || spaces[3][i] == STATE_T ) )
		{
			O = true;
		}
	}

	if( ( spaces[0][0] == STATE_X || spaces[0][0] == STATE_T ) &&
		( spaces[1][1] == STATE_X || spaces[1][1] == STATE_T ) &&
	    ( spaces[2][2] == STATE_X || spaces[2][2] == STATE_T ) &&
		( spaces[3][3] == STATE_X || spaces[3][3] == STATE_T ) )
	{
		X = true;
	}
	if( ( spaces[0][0] == STATE_O || spaces[0][0] == STATE_T ) &&
	    ( spaces[1][1] == STATE_O || spaces[1][1] == STATE_T ) &&
	    ( spaces[2][2] == STATE_O || spaces[2][2] == STATE_T ) &&
		( spaces[3][3] == STATE_O || spaces[3][3] == STATE_T ) )
	{
		O = true;
	}
	if( ( spaces[0][3] == STATE_X || spaces[0][3] == STATE_T ) &&
		( spaces[1][2] == STATE_X || spaces[1][2] == STATE_T ) &&
	    ( spaces[2][1] == STATE_X || spaces[2][1] == STATE_T ) &&
		( spaces[3][0] == STATE_X || spaces[3][0] == STATE_T ) )
	{
		X = true;
	}
	if( ( spaces[0][3] == STATE_O || spaces[0][3] == STATE_T ) &&
	    ( spaces[1][2] == STATE_O || spaces[1][2] == STATE_T ) &&
	    ( spaces[2][1] == STATE_O || spaces[2][1] == STATE_T ) &&
		( spaces[3][0] == STATE_O || spaces[3][0] == STATE_T ) )
	{
		O = true;
	}

	bool over = true;
	for(int i = 0; i < ROW_COUNT; i++ )
	{
		for(int j = 0; j < COL_COUNT; j++ )
		{
			if( spaces[i][j] == STATE_EMPTY )
			{
				over = false;
			}
		}
	}

	if( X == true )
	{
		retn_val = X_WON;
	}
	if( O == true )
	{
		retn_val = O_WON;
	}
	if( X != true && O != true && over )
	{
		retn_val = DRAW;
	}
	if( X != true && O != true && !over )
	{
		retn_val = NOT_OVER;
	}
	return retn_val;
}
