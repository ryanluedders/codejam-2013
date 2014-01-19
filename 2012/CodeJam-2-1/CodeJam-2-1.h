//
//  CodeJam-2-1.h
//  CodeJam-2-1
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#ifndef _CODEJAM_2_1_H
#define _CODEJAM_2_1_H

#include <string>
#include <vector>

namespace CJ21
{        
    bool runSolution
        (
         int argc, 
         const char * argv[]
         );
    
    std::string solveProblem
        (
         int lineNumber,
         std::string aInput
         );
}

#endif //_CODEJAM_2_1_H

