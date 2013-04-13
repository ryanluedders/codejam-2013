//
//  CodeJam-1-1.cpp
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
#include "CodeJam-1-1.h"
#include "Board.h"

#define HEADER "***CodeJam 2013 Round 1-1***"

char * results[] = {
		"X won",
		"O won",
		"Draw",
		"Game has not completed",
};

namespace CJ11
{   
    bool solve
		(
        int argc,
        const char * argv[]
        )
    {
        bool result = false;

        std::cout << HEADER << std::endl;

        std::vector<std::string> file = CJUtil::readFile(argv[1]);
        int count = std::atoi(file[0].c_str());

        std::cout << "processing " << count << " samples" << std::endl;

        std::vector<std::string> lines;

        for(int i=0; i<count; i++)
        {
        	Board a;
        	for(int j=0; j<4; j++)
        	{
        		int start = 1 + i*5;
        		a.loadRow(j,file[start+j].c_str());
        	}
        	//a.print();
        	std::stringstream st;
        	st << (i+1);

        	std::string line = "";
        	line.append("Case #");
        	line.append(st.str());
        	line.append(": ");
        	line.append(results[a.result()]);
        	//std::cout << "Case #" << (i+1) << ": " << results[a.result()] << std::endl;
        	lines.push_back(line);
        }

        CJUtil::writeFile(argv[2],lines);

        return result;
    } // end of solve
}
