//
//  CodeJam-1-1.h
//  CodeJam-1-1
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#ifndef _CODEJAM_1_1_H
#define _CODEJAM_1_1_H

#include <string>
#include <vector>

/*
 ejp mysljylc kd kxveddknmc re jsicpdrysi
 rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
 de kr kd eoya kw aej tysr re ujdr lkgc jv
 
 
 Output
 Case #1: our language is impossible to understand
 Case #2: there are twenty six factorial possibilities
 Case #3: so it is okay if you want to just give up
 
  "a zoo" will become "y qee".
 */

namespace CJ11
{
    //-----------------------------------------
    // Data
    //-----------------------------------------
                                      // abcdefghijklmnopqrstuvwxyz
    static const char asciiForCode[] = " yhesocvxduiglbkrztnwjpfmaq";
    
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
    
    void parseLines
        (
         std::string aInput
         );
    
    std::string translateFromCode
        (
        std::string aString
         );
    
    char getCharFromCode
        (
         char aCode
         );
    
    static std::vector<std::string> lines;
}

#endif

