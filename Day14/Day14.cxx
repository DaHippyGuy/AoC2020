//
//  Advent of Code 2020 Solutions: Day 14
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/31/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include <map>
#include "Day14.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <math.h>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
namespace AocDay14 {

    static const std::string InputFileName = "Day14.txt";

    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        std::string address = "";
        std::string mask = "";
        std::string data = "";
        std::string dataStr = "";
        map<long int, long int> dataFromMemory;

        for(auto line = input.begin(); line != input.end(); line++)
        {
            string tmpStr = *line;
            //Grab mask updates
            if(tmpStr.find("mask") == 0)
            {
                mask = tmpStr.substr((tmpStr.find('=') + 2), 36);
            }
            //.. or grab address and data
            else
            {
                address = tmpStr.substr((tmpStr.find('[') + 1), (tmpStr.find(']') - tmpStr.find('[') - 1));
                data    = tmpStr.substr((tmpStr.find('=') + 2), (tmpStr.size() - tmpStr.find('=') - 1));

                //convert data to a binary string
                dataStr = convertIntToBinaryString((stol(data)), 36);
                maskAndStoreDataA(dataFromMemory, address, dataStr, mask);
            }
        }
        long long int total = 0;
        for(auto &dataSet: dataFromMemory)
        {
            total += dataSet.second;
        }

        return to_string(total);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        std::string address = "";
        std::string mask = "";
        std::string data = "";
        std::string addressStr = "";
        map<long int, long int> dataFromMemory;

        for(auto line = input.begin(); line != input.end(); line++)
        {
            string tmpStr = *line;
            //Grab mask updates
            if(tmpStr.find("mask") == 0)
            {
                mask = tmpStr.substr((tmpStr.find('=') + 2), 36);
            }
            //.. or grab address and data
            else
            {
                address = tmpStr.substr((tmpStr.find('[') + 1), (tmpStr.find(']') - tmpStr.find('[') - 1));
                data    = tmpStr.substr((tmpStr.find('=') + 2), (tmpStr.size() - tmpStr.find('=') - 1));

                //convert address to a binary string
                addressStr = convertIntToBinaryString((stol(address)), 36);
                //mask the address
                maskAndStoreDataB(dataFromMemory, addressStr, data, mask);
            }
        }
        long long int total = 0;
        for(auto &dataSet: dataFromMemory)
        {
            //cout << "[" << dataSet.first << "] " << dataSet.second << endl;
            total += dataSet.second;
        }

        return to_string(total);
    }

    std::string convertIntToBinaryString(long int num, int size)
    {
        string dataString = "";
        // Divide num down and store the remainder in string
        while(num!=0) {dataString=(num%2==0 ?"0":"1")+dataString; num/=2;}
        int dataSize = dataString.size();
        // Next pack zeros
        for(int i = 0; i < size - dataSize; i++) dataString.insert(0, 1, '0');

        return dataString;
    }

    void maskAndStoreDataA(std::map<long int, long int>& addrData, std::string add, std::string dat, std::string msk)
    {
        //Mask data in address
        for(int ch = 0; ch < 36 ; ch++)
        {
            if(msk[ch] == '0') dat[ch] = '0';
            if(msk[ch] == '1') dat[ch] = '1';
            addrData[stol(add)] = stol(dat, 0, 2);
        }
    }

    void maskAndStoreDataB(std::map<long int, long int>& addrData, std::string add, std::string dat, std::string msk)
    {
        //Force 1s and gather positions of Xs
        std::vector<int> xPos = {};
        string newMask = "";
        for(int ch = 0; ch < 36 ; ch++)
        {
            if(msk[ch] == '1') add[ch] = '1';
            if(msk[ch] == 'X') xPos.push_back(ch);
        }
        for (int i = 0; i < pow(2, xPos.size()); i++)
        {
            newMask = convertIntToBinaryString(i, xPos.size());
            for(int j = 0; j < xPos.size(); j++)
            {
                add[xPos.at(j)] = newMask[j];
            }
            addrData[stol(add, 0, 2)] = stol(dat);
        }
    }
}
