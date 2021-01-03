//
//  Advent of Code 2020 Tests: Day 14
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/31/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay14{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay14;

TEST(Y2020_SolveDay14, FinalSolutionPartA) {
    EXPECT_EQ("2346881602152", solvea());
}

TEST(Y2020_SolveDay14, FinalSolutionPartB) {
    EXPECT_EQ("3885232834169", solveb());
}

TEST(Y2020_Day14Example,TestBinaryConversion) {
    EXPECT_EQ("011",convertIntToBinaryString(3, 3));
    EXPECT_EQ("10111",convertIntToBinaryString(23, 5));
}

TEST(Y2020_Day14Example,MaskAndMapA) {
    std::map<long int, long int> testmap;
    maskAndStoreDataA(testmap,
                     "8",
                     convertIntToBinaryString(11, 36),
                     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X");
    EXPECT_EQ(73, testmap[8]);
}
TEST(Y2020_Day14Example,MaskAndMapB1) {
    std::map<long int, long int> testmap;
    maskAndStoreDataB(testmap,
                     convertIntToBinaryString(42, 36),
                     "100",
                     "000000000000000000000000000000X1001X");
    EXPECT_EQ(100, testmap[26]);
    EXPECT_EQ(100, testmap[27]);
    EXPECT_EQ(100, testmap[58]);
    EXPECT_EQ(100, testmap[59]);
}

TEST(Y2020_Day14Example,MaskAndMapB2) {
    std::map<long int, long int> testmap;
    maskAndStoreDataB(testmap,
                     convertIntToBinaryString(26, 36),
                     "1",
                     "00000000000000000000000000000000X0XX");
    EXPECT_EQ(1, testmap[16]);
    EXPECT_EQ(1, testmap[17]);
    EXPECT_EQ(1, testmap[18]);
    EXPECT_EQ(1, testmap[19]);
    EXPECT_EQ(1, testmap[24]);
    EXPECT_EQ(1, testmap[25]);
    EXPECT_EQ(1, testmap[26]);
    EXPECT_EQ(1, testmap[27]);
}
