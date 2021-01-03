//
//  Advent of Code 2020 Solutions: Day 14
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/31/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <map>

namespace AocDay14 {
//Function Definitions
    std::string convertIntToBinaryString(long int num, int size);
    void maskAndStoreDataA(std::map<long int, long int>& addrData, std::string add, std::string dat, std::string msk);
    void maskAndStoreDataB(std::map<long int, long int>& addrData, std::string add, std::string dat, std::string msk);
}
