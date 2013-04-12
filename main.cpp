//
//  main.cpp
//  CodeJam-1-3
//
//  Created by Ryan Luedders on 4/23/12.
//  Copyright (c) 2012 n/a. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "CodeJam-1-1.h"
#include "CodeJam-1-2.h"
#include "CodeJam-1-3.h"
#include "CodeJam-1-4.h"

#define CURRENT_ROUND 11

// main
int main(int argc, const char * argv[])
{
#if( 11 == CURRENT_ROUND )
		return CJ11::solve(argc, argv);
#elif( 12 == CURRENT_ROUND )
		return CJ12::solve(argc, argv);
#elif( 13 == CURRENT_ROUND )
		return CJ13::solve(argc, argv);
#elif( 14 == CURRENT_ROUND )
		return CJ14::solve(argc, argv);
#endif
} // end of main

