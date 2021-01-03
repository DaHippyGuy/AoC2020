//
//  Advent of Code 2020 Tests: Day 9
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/11/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay09{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay09;

TEST(Y2020_SolveDay9, FinalSolutionPartA) {
    EXPECT_EQ("---", solvea());
}

TEST(Y2020_SolveDay9, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2020_Day9Example,Test1) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day9Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day9Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
