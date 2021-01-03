//
//  Advent of Code 2020 Solutions: Day 9
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/11/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <unordered_set>


using namespace std;
namespace AocDay09 {

    static const std::string InputFileName = "Day09.txt";
    std::string solvea() {
        auto input = parseFileForNumberPerLine(InputFileName);
        int numbers = 25;
        vector<long long int> answers;
        unordered_set<long long int> sums;
        //loop through the data set
        for (int i = numbers; i < input.size(); i++)
        {
            //Set match flag to false;
            //grab the set of number to evaluate
            vector<long long int> factors(&input[i-numbers],&input[i]);
            for(vector<long long int>::iterator j = factors.begin(); j != factors.end(); j++)
            {
                for(vector<long long int>::iterator  k = factors.begin(); k != factors.end(); k++)
                {
                    if(*j != *k)
                    {
                        sums.insert(*j + *k);
                    }
                }
            }
            if(sums.count(input.at(i)) == 0){
                //cout << endl << input.at(i) << endl;
                answers.push_back(input.at(i));
            }
            sums.clear();
        }
        return to_string(answers.at(0));
    }

    std::string solveb() {
        auto input = parseFileForNumberPerLine(InputFileName);
        long long int matchedNum = stoll(solvea());
        long long int sum = 0;
        int index = 0;
        int range = 0;
        //If we're still in range and haven't found a match, keep going
        while (index < input.size() && sum != matchedNum)
        {
            range = 0;
            sum = 0;
            //Add up numbers in a sequence until you exceed the matchedSum
            while (sum < matchedNum){
                sum = sum + input.at(index+range);
                //cout << index << " " << range << " " << sum << " " << endl;
                range++;
            }
            index++;
        }
        long long int min = 0;
        long long int max = 0;
        for(int i = index-1; i< index + range - 2 ; i++)
        {
            cout << i << " " << input.at(i) << endl;
            if(input.at(i) > max) max = input.at(i);
            if(input.at(i) < min || min == 0) min = input.at(i);
        }


        cout << min << " " << max << endl;

        return to_string(min + max);
    }

}
