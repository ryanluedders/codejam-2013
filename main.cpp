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

#define ROUND_1_2

// main
int main(int argc, const char * argv[])
{
#if defined( ROUND_1_1 )
		return CJ11::solve(argc, argv);
#elif defined( ROUND_1_2 )
		return CJ12::solve(argc, argv);
#elif defined( ROUND_1_3 )
		return CJ13::solve(argc, argv);
#elif defined( ROUND_1_4 )
		return CJ14::solve(argc, argv);
#endif
} // end of main

