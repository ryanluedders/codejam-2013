//
//  CodeJam-1-1.cpp
//  CodeJam-1-1
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "CodeJam_Util.h"
#include "CodeJam-1-1.h"

namespace CJ11 
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
            std::vector<std::string> translatedLines;
            
            // start at line 1, to ignore the first line which is just the
            // number of lines to follow
            for( int i = 1; i < codeLines.size(); i++ )
            {
                if( codeLines[i].size() > 0 )
                {
                    translatedLines.push_back( CJ11::solveProblem( i, codeLines[i] ) );
                }
            }
            
            result = CJUtil::writeFile( argv[2], translatedLines );
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

        char lineNum[10];
        snprintf( lineNum, 10, "%i", lineNumber);
        
        returnString += "Case #";
        returnString += lineNum;
        returnString += ": ";
        returnString += translateFromCode( aInput );
    
        return returnString;
    }
    
    void parseLines
        (
         std::string aInput
         )
    {
        int count = 0;
        while( aInput.find( "\n" ) != std::string::npos )
        {
            std::string line = aInput.substr( 0, aInput.find( "\n" ) );
            aInput.erase( 0, line.size() + 1 );
            if( count != 0 )
            {
                lines.push_back( line );
            }
            count++;
        }
    }
    
    std::string translateFromCode
        (
        std::string aString
        )
    {
        std::string translatedString( "" );
        for( int i = 0; i < aString.size(); i++ )
        {
            translatedString += getCharFromCode( aString[i] );
        }
        return translatedString;
    }
    
    char getCharFromCode
    (
     char aCode
     )
    {        
        char asciiChar = aCode;
        
        if( aCode != ' ' )
        {
            asciiChar = asciiForCode[ aCode - 96 ];
        }
        
        return asciiChar;
    }
}
