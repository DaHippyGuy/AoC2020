//
//  Advent of Code 2020 Tests: Day 12
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/20/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay12{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay12;

TEST(Y2020_SolveDay12, FinalSolutionPartA) {
    EXPECT_EQ("2270", solvea());
}

TEST(Y2020_SolveDay12, FinalSolutionPartB) {
    EXPECT_EQ("138669", solveb());
}

TEST(Y2020_Day12Example,Test1) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day12Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day12Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
