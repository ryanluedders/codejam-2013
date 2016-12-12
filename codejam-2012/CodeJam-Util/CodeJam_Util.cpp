//
//  CodeJam_Util.cpp
//  CodeJam_Util
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

#define OUTPUT_TO_STDOUT    true

namespace CJUtil
{   
    /*-----------------------------------------------*
     * read a file by name
     * \param fileName name of file to read
     * \return a vector of lines
     *-----------------------------------------------*/
    std::vector<std::string> readFile
    (
     const char * fileName
     )
    {
        std::vector<std::string> returnVector;
        
        std::ifstream inputFile;
        inputFile.open( fileName );
        
        if( inputFile.is_open() )
        {
            std::string fileLine;
            while( inputFile.good() )
            {
                getline( inputFile, fileLine );
                returnVector.push_back( fileLine );
            }
        }
        
        return returnVector;
    } // end of readFile
    
    /*-----------------------------------------------*
     * write to a file by name
     * \param fileName name of file to write
     * \param fileLines vector of lines to write
     * \return whether write was successful
     *-----------------------------------------------*/
    bool writeFile
    (
     const char * fileName,
     std::vector<std::string> fileLines
     )
    {
        bool result = false;
        std::ofstream outputFile;

        outputFile.open( fileName );
    
        if( outputFile.is_open() )
        {
            for( int i = 0; i < fileLines.size(); i++ )
            {
                outputFile << fileLines[i] << std::endl;
                #if( OUTPUT_TO_STDOUT )
                    std::cout << fileLines[i] << std::endl;
                #endif
            }
            
            outputFile.close();
            result = true;
        }
        return result;
    } // end of writeFile
    
    /*-----------------------------------------------*
     * parse a line into arguments
     *-----------------------------------------------*/
    std::vector<std::string> parseLine
    (
     std::string line,
     char delimiter
     )
    {
        std::stringstream stringStrm( line );
        std::string token;
        std::vector<std::string> tokens;

        while( getline( stringStrm, token, delimiter ) )
        {
            tokens.push_back( token );
        }
        
        return tokens;
    } // end of parseLine
    
    /*-----------------------------------------------*
     * calculate number of places in a number
     * \param aNumber number to check places
     * \return number of places
     *-----------------------------------------------*/
    int calculatePlaces
    (
     int aNumber
     )
    {
        std::stringstream stringStrm;
        stringStrm << aNumber;
        
        return (int)std::string( stringStrm.str() ).size();
    } // end of calculatePlaces
}
