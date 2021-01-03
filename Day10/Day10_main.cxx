//
//  Advent of Code 2020 Main Runner: Day 10
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay10{
    extern std::string solvea(std::string InputFileName);
    extern std::string solveb(std::string InputFileName);
}
using namespace std;

int main(int argc, char *argv[]) {
    static const std::string InputFileName = "Day10.txt";
    std::cout << "Day10" << "a: " << AocDay10::solvea(InputFileName) << std::endl;
    std::cout << "Day10" << "b: " << AocDay10::solveb(InputFileName) << std::endl;
    return 0;
}
