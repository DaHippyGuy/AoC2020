//
//  Advent of Code 2020 Tests: Day 13
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/29/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay13{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay13;

TEST(Y2020_SolveDay13, FinalSolutionPartA) {
    EXPECT_EQ("---", solvea());
}

TEST(Y2020_SolveDay13, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2020_Day13Example,Test1) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day13Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day13Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
