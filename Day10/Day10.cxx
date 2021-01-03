//
//  Advent of Code 2020 Solutions: Day 10
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <vector>

using namespace std;
namespace AocDay10 {

    std::string solvea(std::string InputFileName) {
        auto input = parseFileForNumberPerLine(InputFileName);
        //find max joltage
        int maxJoltage = 0;
        sort(input.begin(), input.end());
        for (auto adpt = input.begin(); adpt != input.end(); adpt++)
        {
            if(*adpt > maxJoltage) maxJoltage = *adpt;
        }
        int joltage = 0;
        vector<int> adaptors;
        while(joltage < maxJoltage)
        {
            //check for 1 jolt
            if (count(input.begin(), input.end(), joltage + 1))
            {
                joltage++;
                adaptors.push_back(1);
            }
            //check for 2 jolts
            else if (count(input.begin(), input.end(), joltage + 2))
            {
                joltage += 2;
                adaptors.push_back(2);
            }
            //check for 3 jolts
            else if (count(input.begin(), input.end(), joltage + 3))
            {
                joltage += 3;
                adaptors.push_back(3);
            }
        }
        //Add last 3 jolt adaptor
        adaptors.push_back(3);

        return to_string(count(adaptors.begin(), adaptors.end(), 1) * count(adaptors.begin(), adaptors.end(), 3));
    }

    std::string solveb(std::string InputFileName) {
        auto input = parseFileForNumberPerLine(InputFileName);
        int maxJoltage = 0;
        sort(input.begin(), input.end());
        //go through every adaptor and see if another branch is warranted
        vector<vector<int>> combos;
        combos.push_back(input);
        for(auto adaptor = input.begin(); adaptor != input.end(); adaptor++)
        {
            for(int combo = 0; combo < combos.size(); combo++)
            {
                //create new branches where appropriate
                int branches = 0;
                //check next three entries to see if one should create a branch
                if(count(combos[combo].begin(), combos[combo].end(), *adaptor + 1)) branches++;
                if(count(combos[combo].begin(), combos[combo].end(), *adaptor + 2)) branches++;
                if(count(combos[combo].begin(), combos[combo].end(), *adaptor + 3)) branches++;

                //subtract out the base branch
                branches--;
                //create copied of
                for(int newBranch = 0; newBranch < branches; branches++)
                {

                }
                cout << *adaptor << branches << " ";
            }

        }
        cout << combos[0][3] << " combos-----------------------------------" << endl;
        return "---";
    }

}
