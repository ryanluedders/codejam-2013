//
//  CodeJam_Util.h
//  CodeJam_Util
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#ifndef _CODEJAM_UTIL_H
#define _CODEJAM_UTIL_H

#include <string>
#include <vector>

namespace CJUtil
{        
    //-----------------------------------------
    // Data
    //-----------------------------------------
    std::vector<std::string> readFile
        (
         const char * fileName
         );
    
    bool writeFile
        (
         const char * fileName,
         std::vector<std::string> fileLines
         );
    
    std::vector<std::string> parseLine
        (
         std::string line,
         char delimiter
         );
    
    int calculatePlaces
        (
         int aNumber
         );
}

#endif //_CODEJAM_UTIL_H

