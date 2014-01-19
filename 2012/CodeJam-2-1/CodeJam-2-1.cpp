//
//  CodeJam-2-1.cpp
//  CodeJam-2-1
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "float.h"

#include "CodeJam_Util.h"
#include "CodeJam-2-1.h"

namespace CJ21
{   
    /*-----------------------------------------------*
     * run the solution
     *-----------------------------------------------*/
    bool runSolution
        (
         int argc, 
         const char * argv[]
         )
    {
        std::vector<std::string> lines = CJUtil::readFile(argv[1]);
        std::vector<std::string> results;
        
        for( int i=1; i<lines.size(); i++ )
        {
            if( lines[i].size() > 0 )
            {
                results.push_back( solveProblem(i, lines[i]) );
            }
        }
        
        CJUtil::writeFile(argv[2], results);
    }
    
    /*-----------------------------------------------*
     * function with logic to solve the problem
     *-----------------------------------------------*/
    std::string solveProblem
        (
         int lineNumber,
         std::string aInput
        )
    {
        std::vector<float> scores;
        float totalForAll = 0;
        
        std::vector<std::string> scoreStrs = CJUtil::parseLine(aInput, ' ' );
        
        std::stringstream outString;
        outString.setf(std::ios::fixed,std::ios::floatfield);
        outString.precision( 6 );
        
        outString << "Case #" << lineNumber << ":";
        
        for( int i=1; i<scoreStrs.size(); i++ )
        {
            scores.push_back(atof(scoreStrs[i].c_str()));
            totalForAll += scores[i-1];
        }
        
        for( int i=0; i<scores.size(); i++ )
        {
            outString << " ";
            
            std::vector<float> workingScores = scores;
            
            float availableVotes = totalForAll;
            float votesUsed = 0;
            
            while( availableVotes > scores.size() )
            {                
                float lowestVal = FLT_MAX;
                int lowestIdx = -1;
                
                for( int j=0; j<workingScores.size(); j++ )
                {
                    if( workingScores[j] <= lowestVal )
                    {
                        lowestIdx = j;
                        lowestVal = workingScores[j];
                    }
                }
                
                workingScores[ lowestIdx ] += 1;
                availableVotes -= 1;
                if( lowestIdx == i )
                {
                    votesUsed += 1;
                }
            }
            
            float totalNeeded = votesUsed / totalForAll;
            
            outString << ( totalNeeded * 100.0 );
        }
        
        return outString.str();
    } // end of solveProblem

}
