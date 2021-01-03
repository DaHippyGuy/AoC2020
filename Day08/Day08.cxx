//
//  Advent of Code 2020 Solutions: Day 8
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/08/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <cstdio>


using namespace std;
namespace AocDay08 {

    static const std::string InputFileName = "Day08.txt";
    string getCommand(string commandStr){
        // grab stuff before the space
        return commandStr.substr(0, commandStr.find(' '));
    }

    int getArgument(string commandStr){
        string direction = commandStr.substr(commandStr.find(' ') + 1, 1);
        int argument = stoi(commandStr.substr(commandStr.find(' ') + 2, commandStr.length()));
        //Filp polarity is sign is '-'
        if ("-" == direction) argument = argument * -1;
        //process commands
        return argument;
    }

    std::string solvea() {
        int index = 0;
        int accumulator = 0;
        vector<int> usedIndex;
        auto input = parseFileForLines(InputFileName);
        //Loop until an index repeats
        while (!(find(usedIndex.begin(), usedIndex.end(), index) != usedIndex.end()))
        {
            //Load index to ensure we don't hit it again
            usedIndex.push_back(index);
            //split the string into a cmd and value
            string tmp = input.at(index);
            string command = getCommand(tmp);
            int argument = getArgument(tmp);
            if ("acc" == command)
            {
                accumulator += argument;
                index++;
            }
            else if ("jmp" == command)
            {
                index += argument;
            }
            else
            {
                index++;
            }
            //cout << command << " " << argument << " " << index << endl;
        }
        return to_string(accumulator);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        // cycle through the list of commands. If nop is reversed with jmp, check to see if the
        // index gets to the final entry, indicating a full completion of the sequence
        int checkIndex = 0;
        int index = 0;
        int accumulator = 0;
        while (index < input.size() - 1)
        {
            vector<string> trialInput = input;
            cout << checkIndex << " " << trialInput.at(checkIndex) << endl;
            string tmp = trialInput.at(checkIndex);
            if(getCommand(tmp) == "nop") tmp.replace(0, 3, "jmp");
            else if(getCommand(tmp) == "jmp") tmp.replace(0, 3, "nop");
            trialInput.at(checkIndex) = tmp;
            // with jmp swapped with nop, check for end
            accumulator = 0;
            index = 0;
            vector<int> usedIndex;
            //Loop until an index repeats
            while ((!(find(usedIndex.begin(), usedIndex.end(), index) != usedIndex.end())) && (index != (input.size())))
            {
                //Load index to ensure we don't hit it again
                usedIndex.push_back(index);
                //split the string into a cmd and value
                string tmp = trialInput.at(index);
                string command = getCommand(tmp);
                int argument = getArgument(tmp);
                //process commands
                if ("acc" == command)
                {
                    accumulator += argument;
                    index++;
                }
                else if ("jmp" == command)
                {
                    index += argument;
                }
                else
                {
                    index++;
                }
                cout << command << " " << argument << " " << index << endl;
            }
            cout << " " << accumulator << endl;
            usedIndex.empty();
            checkIndex++;
        }
        return to_string(accumulator);
    }

}
