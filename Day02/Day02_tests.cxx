//
//  Advent of Code 2020 Tests: Day 2
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/08/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay02{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay02;

TEST(Y2020_SolveDay2, FinalSolutionPartA) {
    EXPECT_EQ("---", solvea());
}

TEST(Y2020_SolveDay2, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2020_Day2Example,Test1) {
    int x = 0;
    EXPECT_EQ(1,x);
}

TEST(Y2020_Day2Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day2Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
