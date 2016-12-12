//
//  CodeJam-1-3.h
//  CodeJam-1-3
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#ifndef _CODEJAM_1_3_H
#define _CODEJAM_1_3_H

#include <string>
#include <vector>

namespace CJ13
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

#endif //_CODEJAM_1_3_H

