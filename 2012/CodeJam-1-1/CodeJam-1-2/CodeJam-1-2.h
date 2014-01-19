//
//  CodeJam-1-2.h
//  CodeJam-1-2
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#ifndef _CODEJAM_1_2_H
#define _CODEJAM_1_2_H

#include <string>
#include <vector>

namespace CJ12
{    
    //-----------------------------------------
    // Composite score object
    //-----------------------------------------
    class CompositeScore
    {
    public:
        enum ResultType
        {
            PRESENT_NOT_SURPRISING,
            PRESENT_SURPRISING,
            NOT_PRESENT
        };
        
    public:
        CompositeScore
            (
             int aComposite
             );
        
        ~CompositeScore();
        
        ResultType hasScoreGreaterThan
            (
             int aIndividualScore
             );
        
    private:
        int mComposite;
    };
    
    //-----------------------------------------
    // Utility Functions
    //-----------------------------------------
    std::string solveProblem
        (
         int lineNumber,
         std::string aInput
         );
    
    bool runSolution
        (
         int argc, 
         const char * argv[]
         );
}

#endif //_CODEJAM_1_2_H

