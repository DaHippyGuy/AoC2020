//
//  Advent of Code 2020 Tests: Day 10
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay10{
    extern std::string solvea(std::string InputFileName);
    extern std::string solveb(std::string InputFileName);
}

using namespace std;
using namespace AocDay10;

TEST(Y2020_SolveDay10, FinalSolutionPartA) {
    EXPECT_EQ("1656", solvea("Day10.txt"));
}

TEST(Y2020_SolveDay10, FinalSolutionPartB) {
    EXPECT_EQ("1656", solveb("Day10.txt"));
}

TEST(Y2020_Day10Example,Test1) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day10Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day10Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
