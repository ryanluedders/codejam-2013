//
//  CodeJam-1-3.cpp
//  CodeJam-1-3
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "CodeJam_Util.h"
#include "CodeJam-1-3.h"

#define MAX_INTEGER_LENGTH 50

namespace CJ13
{   
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
                    resultLines.push_back( CJ13::solveProblem( i, codeLines[i] ) );
                }
            }
            
            result = CJUtil::writeFile( argv[2], resultLines );
        }
        return result;
    }
    
    std::string solveProblem
        (
         int lineNumber,
         std::string aInput
        )
    {
        
        std::string returnString;
        std::string boundString;
        
        int lowerBound = 0;
        int upperBound = 0;
        int count = 0;
        
        std::stringstream stringStrm( aInput );
        
        // get upper and lower bound
        while( getline( stringStrm, boundString, ' ' ) )
        {
            if( count == 0 )
            {
                lowerBound = std::atoi( boundString.c_str() );
            }
            else if( count == 1 )
            {
                upperBound = std::atoi( boundString.c_str() );
            }
            count++;
        }
        
        int dupCount = 0;
        
        for( int i = lowerBound; i <= upperBound; i++ )
        {
            std::stringstream stringStrm;
            stringStrm << i;
            std::string iStr( stringStrm.str() );
            
            std::vector<std::string> pairsForI;
            
            for( int j = 0; j < iStr.size(); j++ )
            {
                if( std::atoi( iStr.c_str() ) >= lowerBound
                   && std::atoi( iStr.c_str() ) <= upperBound
                   && CJUtil::calculatePlaces( std::atoi( iStr.c_str() ) == CJUtil::calculatePlaces( lowerBound ) ) 
                   && i < std::atoi( iStr.c_str() ) )
                {
                    std::vector<std::string>::iterator iter = pairsForI.begin();
                    bool isInVec = false;
                    for( iter = pairsForI.begin(); iter != pairsForI.end(); iter++ )
                    {
                        if( ((std::string)(*iter)).compare( iStr ) == 0 )
                        {
                            isInVec = true;
                            break;
                        }
                    }
                    
                    if( !isInVec )
                    {
                        dupCount += 1;
                        //std::cout << i << " " << iStr << std::endl;
                        pairsForI.push_back( iStr );
                    }
                }
                
                std::string rotString = iStr.substr( iStr.size() - 1, iStr.size() );
                rotString += iStr.substr( 0, iStr.size() - 1 );
                iStr = rotString;
            }
            
            pairsForI.clear();
        }
        
        std::stringstream returnStream;
        returnStream << "Case #" << lineNumber << ": " << dupCount;
        returnString = returnStream.str();
    
        return returnString;
    } // end of solveProblem

}
