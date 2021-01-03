//
//  Advent of Code 2020 Solutions: Day 13
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/29/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <vector>



using namespace std;
namespace AocDay13 {

    static const std::string InputFileName = "Day13.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int earliest = stoi(input.at(0));
        string stops = input.at(1);
        vector<int> stop;
        string tmp = "";

        for (int chars = 0; chars < stops.size(); chars++)
        {
            if (stops.at(chars) != 'x')
            {
                if (stops.at(chars) != ',')
                {
                    tmp.push_back(stops.at(chars));
                }
                else if (tmp.size() != 0 || chars == stops.size() - 1)
                {
                    stop.push_back(stoi(tmp));
                    tmp = "";
                }
            }

        }
        int shortest = 0;
        int shortestStop = 0;
        for (auto i = stop.begin(); i != stop.end(); i++)
        {
            if (shortest == 0 || shortest > (*i - earliest%*i))
            {
                shortest = (*i - earliest%*i);
                shortestStop = *i;
            }
        }

        int result = shortest * shortestStop;
        return to_string(result);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        string stops = input.at(1);
        vector<int> stop;
        string tmp = "";
        int index = 0;

        for (int chars = 0; chars < stops.size(); chars++)
        {
            if (stops.at(chars) != ',')
            {
                tmp.push_back(stops.at(chars));
            }
            if (stops.at(chars) == ',' || chars == stops.size() - 1)
            {
                if(tmp.size() != 0)
                {
                    if(tmp != "x")
                    {
                        stop.push_back(index);
                        stop.push_back(stoi(tmp));
                    }
                    tmp = "";
                }
                index++;
            }
        }

        long long int checkNum = 100000000000000;
        bool checked = false;
        int inc     = 0;
        int offset  = 0;
        cout << stop.size();
        for(int i = 0; i < stop.size(); i = i + 2)
        {
            cout << stop.at(i) << ", " << stop.at(i + 1) << ", ";
            if(stop.at(i + 1) > inc)
            {
                inc = stop.at(i + 1);
                offset = stop.at(i);
                cout << inc << " " << offset << " " << checkNum << endl;
            }
        }
        checkNum = checkNum - checkNum%inc - offset;
        cout << inc << " " << offset << " " << checkNum << endl;

        while(!checked)
        {
            checked = true;
            for(int ind = 0; ind < stop.size(); ind = ind + 2)
            {
                //Fail the test if any of the offset items don't divide evenly.
                if((checkNum + stop.at(ind)) % stop.at(ind + 1) != 0)
                {
                    checked = false;
                    break;
                }
            }
            checkNum += inc;

            if(checkNum%10000000 == 0) cout << checkNum << endl;
        }
        //Subtract the last one I added
        checkNum -= inc;
        return to_string(checkNum);
    }

}
