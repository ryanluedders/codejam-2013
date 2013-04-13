//
//  CodeJam-1-3.cpp
//
//  Created by Ryan Luedders on 4/13/12.
//  Copyright 2012 n/a. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <map>
#include "CodeJam_Util.h"
#include "CodeJam-1-3.h"

#define HEADER "***CodeJam 2013 Round 1-3***"

bool isPal
	(
	std::string num
	)
{
    int str_size = num.size();
    double div_size_d = (double)str_size / 2.0;
    int div_size_i = str_size / 2;

    bool same = true;
    if( div_size_d == div_size_i )
    {
    	//even number
    	for(int i=0; i<div_size_i; i++)
    	{
    		same &= num.c_str()[div_size_i - i] == num.c_str()[div_size_i + i];
    	}
    }
    else
    {
    	//odd number
    	int start_pos = std::ceil(div_size_d);
    	for(int i=1; i<=div_size_i; i++)
    	{
    		same &=  num.c_str()[start_pos - i] == num.c_str()[start_pos + i];
    	}
    }

    return same;
}

namespace CJ13
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

		for(int i=1; i<count+1; i++)
		{
			std::vector<std::string> vals = CJUtil::parseLine(file[i],' ');
			int lowerBound = std::atoi(vals[0].c_str());
			int upperBound = std::atoi(vals[1].c_str());
			//std::cout << lowerBound << " " << upperBound << std::endl;

			//std::string lbString = std::string( vals[0].rbegin(), vals[0].rend() );
			//std::string upString = std::string( vals[1].rbegin(), vals[1].rend() );

			//std::cout << reverse(lowerBound) << " " << reverse(upperBound) << std::endl;

			int case_count = 0;
			for(int i=lowerBound; i<=upperBound; i++)
			{
				std::stringstream st;
				st << (i);

				if( isPal(std::string(st.str())) )
				{
					double sq_rt = std::sqrt(i);
					int rounded_rt = (int)sq_rt;

					if( sq_rt == rounded_rt )
					{
						std::stringstream sta;
						sta << (sq_rt);

						if( isPal(std::string(sta.str())) )
						{
							//std::cout << i << std::endl;
							case_count += 1;
						}

						sta.str("");
					}
				}
				st.str("");
			}

        	std::stringstream st;
        	st << (i);

        	std::string line = "";
        	line.append("Case #");
        	line.append(st.str());
        	line.append(": ");

        	st.str("");
        	st << case_count;
        	line.append(st.str());
        	std::cout << line << std::endl;
        	//std::cout << "Case #" << (i+1) << ": " << results[a.result()] << std::endl;
        	lines.push_back(line);

		}
		CJUtil::writeFile(argv[2],lines);

		return result;
    } // end of solve
}
