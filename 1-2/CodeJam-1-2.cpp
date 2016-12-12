//
//  CodeJam-1-2.cpp
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
#include "CodeJam-1-2.h"
#include "Yard.h"

#define HEADER "***CodeJam 2013 Round 1-2***"

enum
{
	HEIGHT = 0,
	WIDTH = 1
};

namespace CJ12
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

		int cur_line = 1;

		std::vector<std::string> lines;
		for(int i=0; i<count; i++)
		{
			std::vector<std::string> dims = CJUtil::parseLine(file[cur_line], ' ');
			//std::cout << dims[HEIGHT] << " " << dims[WIDTH] << std::endl;
			Yard a(
					std::atoi(dims[HEIGHT].c_str()),
					std::atoi(dims[WIDTH].c_str())
			);

			for(int j=cur_line+1; j<(cur_line+std::atoi(dims[HEIGHT].c_str())+1); j++)
			{
				std::vector<std::string> row = CJUtil::parseLine(file[j],' ');
				a.fillRow(j-cur_line-1, row);
			}

			//a.print();
			cur_line += std::atoi(dims[HEIGHT].c_str())+1;
			//std::cout << file[i] << std::endl;
			//std::cout << std::endl << a.result() << std::endl;

        	//a.print();
        	std::stringstream st;
        	st << (i+1);

        	std::string line = "";
        	line.append("Case #");
        	line.append(st.str());
        	line.append(": ");
        	line.append((a.result() ? "YES" : "NO"));
        	//std::cout << line << std::endl;
        	//std::cout << "Case #" << (i+1) << ": " << results[a.result()] << std::endl;
        	lines.push_back(line);
		}

		CJUtil::writeFile(argv[2],lines);

		return result;
    } // end of solve
}
