//
//  CodeJam-1-4.cpp
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
#include "CodeJam-1-4.h"
#include "Chest.h"

#define HEADER "***CodeJam 2013 Round 1-4***"

bool inVector
	(
	std::vector<int> vector,
	int value
	)
{
	bool present = false;
	for(int i=0; i<vector.size(); i++)
	{
		if(vector[i] == value)
		{
			present = true;
			break;
		}
	}
	return present;
}

void removeFromVector
	(
	std::vector<int> vector,
	int value
	)
{
	for(std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		if((int)(*it) == value )
		{
			vector.erase(it);
			break;
		}
	}
}

namespace CJ14
{   
    bool solve
		(
        int argc,
        const char * argv[]
        )
    {
        bool result = false;

        std::cout << HEADER << std::endl;

		int cur_line = 0;
        std::vector<std::string> file = CJUtil::readFile(argv[1]);
		int count = std::atoi(file[cur_line].c_str());
		cur_line++;

		std::cout << "processing " << count << " samples" << std::endl;
		std::vector<std::string> lines;

		for(int i=0; i<count; i++)
		{
			std::vector<int> order;

			std::vector<std::string> args = CJUtil::parseLine(file[cur_line],' ');
			cur_line += 1;

			// get num keys, num chests
			int start_count = std::atoi(args[0].c_str());
			int chest_count = std::atoi(args[1].c_str());

			//std::cout << start_count << " " << chest_count << std::endl;

			// get starting keys
			std::vector<std::string> keys_held_str = CJUtil::parseLine(file[cur_line],' ');
			cur_line += 1;

			std::vector<int> keys_held;
			//std::cout << "keys held: ";
			for(int j=0; j<start_count; j++)
			{
				keys_held.push_back(std::atoi(keys_held_str[j].c_str()));
				//std::cout << keys_held[j] << " ";
			}
			//std::cout << std::endl;

			std::vector<Chest> chests;
			for(int j=0; j<chest_count; j++)
			{
				std::vector<std::string> chest_contents = CJUtil::parseLine(file[cur_line],' ');
				cur_line += 1;

				Chest a;
				a.setNumber(j+1);
				a.setRequiredKey(std::atoi(chest_contents[0].c_str()));
				chest_contents.erase(chest_contents.begin());
				//discard number of keys entry, as well
				chest_contents.erase(chest_contents.begin());

				a.insertKeys(chest_contents);
				a.setLocked(true);
				//a.print();

				chests.push_back(a);
			}

			bool action_taken = true;

			while(action_taken)
			{
				action_taken = false;

				// determine the keys needed
				std::vector<int> need;
				for(int j=0; j<chest_count; j++)
				{
					if( chests[j].getLocked() )
					{
						need.push_back(chests[j].getRequiredKey());
					}
				}

				// find the most beneficial chest to open (one with the most keys)
				int max_count = -1;
				int chest_max_count = -1;
				for(std::vector<int>::iterator it = keys_held.begin(); it != keys_held.end(); it++)
				{
					for( int j=chest_count-1; j>=0; j--)
					{
						int needed_keys = -1;
						if( chests[j].getLocked() &&
							(int)(*it) == chests[j].getRequiredKey() )
						{
							needed_keys = 0;
							std::vector<int> keys_in_chest = chests[j].getKeys();
							for(int n=0; n<need.size(); n++)
							{
								if(inVector(keys_in_chest,need[n]))
								{
									needed_keys += 1;
								}
							}
						}

						if( needed_keys > 1 )
						{
							max_count = needed_keys;
							chest_max_count = j;
						}
					}
				}

				// if there is no concern about number of keys, open the lowest N chest
				if( keys_held.size() > 1 )
				{
					for(int j=chests.size()-1; j>=0; j--)
					{
						//std::cout << j << std::endl;
						if( inVector(keys_held,chests[j].getRequiredKey()) &&
								chests[j].getLocked())
						{
							chest_max_count = j;
							//break;
						}
					}
				}

				if( chest_max_count != -1 )
				{
					order.push_back(chests[chest_max_count].getNumber());
					chests[chest_max_count].setLocked(false);
					removeFromVector(keys_held,chests[chest_max_count].getRequiredKey());
					action_taken = true;
					std::vector<int> newKeys = chests[chest_max_count].getKeys();
					for(int j=0; j<newKeys.size(); j++)
					{
						keys_held.push_back(newKeys[j]);
					}
				}
			}

			std::stringstream strm;
			strm << (i+1);

			std::string line = "";
			line.append("Case #");
			line.append(strm.str());
			line.append(": ");


			//std::cout << "Case #" << i+1 << ": ";
			if( order.size() != chests.size() )
			{
				//std::cout << "IMPOSSIBLE" << std::endl;
				line.append("IMPOSSIBLE");
			}
			else
			{
				for(int j=0; j<order.size(); j++)
				{
					//std::cout << order[i] << " ";
					strm.str("");
					strm << order[j];
					line.append(strm.str());
					if( j != order.size()-1 )
					{
						line.append(" ");
					}
				}
			}

			lines.push_back(line);
		}

		CJUtil::writeFile(argv[2],lines);

        return result;
    } // end of solve
}
