//
//  Advent of Code 2020 Tests: Day 11
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/18/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay11{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay11;

TEST(Y2020_SolveDay11, FinalSolutionPartA) {
    EXPECT_EQ("2338", solvea());
}

TEST(Y2020_SolveDay11, FinalSolutionPartB) {
    EXPECT_EQ("2134", solveb());
}

