//
//  Board.h
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2013 n/a. All rights reserved.
//

#ifndef _BOARD_H
#define _BOARD_H

class Board
{
	static const int ROW_COUNT = 4;
	static const int COL_COUNT = 4;

public:
	enum
	{
		ROW_1 = 0,
		ROW_2 = 1,
		ROW_3 = 2,
		ROW_4 = 3
	};

	enum
	{
		STATE_T = 0,
		STATE_X = 1,
		STATE_O = 2,
		STATE_EMPTY	= 3,

		MAX_STATES
	};

	enum
	{
		X_WON,
		O_WON,
		DRAW,
		NOT_OVER
	};

private:
	static char* key;

	int spaces[ROW_COUNT][COL_COUNT];

public:
	void loadRow
		(
		int row,
		const char * state
		);

	void print();

	int result();

};

#endif //_CODEJAM_1_1_H
