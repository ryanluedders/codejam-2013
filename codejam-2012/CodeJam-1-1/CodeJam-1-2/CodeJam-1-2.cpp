//
//  CodeJam-1-1.cpp
//  CodeJam-1-1
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "CodeJam_Util.h"
#include "CodeJam-1-2.h"

namespace CJ12
{
    CompositeScore::CompositeScore
        (
         int aComposite
         )
    : mComposite( aComposite )
    {
    } // CompositeScore::CompositeScore
        
    CompositeScore::~CompositeScore()
    {
    } // CompositeScore::~CompositeScore
    
    CompositeScore::ResultType CompositeScore::hasScoreGreaterThan
        (
         int aIndividualScore
         )
    {
        ResultType result = CompositeScore::NOT_PRESENT;
        
        if( mComposite >= ( ( aIndividualScore * 3 ) - 2 ) )
        {
            result = CompositeScore::PRESENT_NOT_SURPRISING;
        }
        else if( aIndividualScore > 1 && ( mComposite >= ( ( aIndividualScore * 3 ) - 4 ) ) )
        {
            result = CompositeScore::PRESENT_SURPRISING;
        }
        else
        {
            result = CompositeScore::NOT_PRESENT;
        }
        
        return result;
    } // CompositeScore::hasScoreGreaterThan
    
    std::string solveProblem
        (
         int lineNumber,
         std::string aInput
        )
    {
        std::string returnString;
        
        std::vector<int> compositeScores;
        std::string scoreString;
        int count = 0;
        
        int countSurprising = 0;
        int minimumScore = 0;
        
        std::stringstream stringStrm( aInput );
        
        while( getline( stringStrm, scoreString, ' ' ) )
        {
            if( count == 0 )
            {
            }
            else if( count == 1 )
            {
                countSurprising = std::atoi( scoreString.c_str() );
            }
            else if( count == 2 )
            {
                minimumScore = std::atoi( scoreString.c_str() );
            }
            else
            {
                compositeScores.push_back( std::atoi( scoreString.c_str() ) );
            }
            count++;
        }
        
        int surprising = 0;
        int definite = 0;
        for( int i = 0; i < compositeScores.size(); i++ )
        {
            CompositeScore::ResultType result = CompositeScore( compositeScores[i] ).hasScoreGreaterThan( minimumScore );
            if( result == CompositeScore::PRESENT_NOT_SURPRISING )
            {
                definite++;
            }
            if( result == CompositeScore::PRESENT_SURPRISING )
            {
                surprising++;
            }
        }
        
        int totalCount = definite + std::min( surprising, countSurprising );

        char lineNum[10];
        snprintf( lineNum, 10, "%i", lineNumber);
        char countNum[10];
        snprintf( countNum, 10, "%i", totalCount);
        
        returnString += "Case #";
        returnString += lineNum;
        returnString += ": ";
        returnString += countNum;
    
        return returnString;
    } // end of solveProblem
    
    bool runSolution
        (
         int argc, 
         const char * argv[]
         )
    {
        bool result = false;
        
        if( argc > 1 )
        {
            std::vector<std::string> codeLines = CJUtil::readFile( argv[1] );
            std::vector<std::string> resultLines;
            
            // start at line 1, to ignore the first line which is just the
            // number of lines to follow
            for( int i = 1; i < codeLines.size(); i++ )
            {
                if( codeLines[i].size() > 0 )
                {
                    resultLines.push_back( CJ12::solveProblem( i, codeLines[i] ) );
                }
            }
            
            result = CJUtil::writeFile( argv[2], resultLines );
        }
        return result;
    }
}
