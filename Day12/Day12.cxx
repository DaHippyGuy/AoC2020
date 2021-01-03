//
//  Advent of Code 2020 Solutions: Day 12
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/20/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <vector>


#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

using namespace std;
namespace AocDay12 {

    static const std::string InputFileName = "Day12.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

        int xPos    = 0;
        int yPos    = 0;
        int heading = EAST;

        for(auto line = input.begin(); line != input.end(); line++)
        {
            string tmp = *line;
            char command = tmp[0];
            int increment = stoi(tmp.substr(1, tmp.size()));

            switch(command){
            case 'F' :
                switch(heading) {
                case NORTH :
                    yPos += increment; break;
                case SOUTH :
                    yPos -= increment; break;
                case EAST :
                    xPos += increment; break;
                case WEST :
                    xPos -= increment; break;
                }
                break;
            case 'N' :
                yPos += increment; break;
            case 'S' :
                yPos -= increment; break;
            case 'E' :
                xPos += increment; break;
            case 'W' :
                xPos -= increment; break;
            case 'R' :
                heading = heading + increment/90;
                if(heading > WEST) heading -= 4;
                break;
            case 'L' :
                heading = heading - increment/90;
                if(heading < NORTH) heading += 4;
                break;
            }
        }
        cout << "Manhatten Distance is " << abs(xPos) + abs(yPos) << endl;

        return to_string(abs(xPos) + abs(yPos));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

        int wpxPos  = 10;
        int wpyPos  = 1;
        int xPos    = 0;
        int yPos    = 0;


        for(auto line = input.begin(); line != input.end(); line++)
        {
            string tmp = *line;
            char command = tmp[0];
            int increment = stoi(tmp.substr(1, tmp.size()));
            int rightTurns = 0;

            switch(command){
            case 'F' :
                xPos += increment*wpxPos;
                yPos += increment*wpyPos;
                break;
            case 'N' :
                wpyPos += increment; break;
            case 'S' :
                wpyPos -= increment; break;
            case 'E' :
                wpxPos += increment; break;
            case 'W' :
                wpxPos -= increment; break;
            case 'R' :
                rightTurns = rightTurns + increment/90;
                break;
            case 'L' :
                rightTurns = rightTurns + (360 - increment)/90;
                break;
            }
            switch(rightTurns){
            int tmp;
            case 1:
                tmp = wpxPos;
                wpxPos = wpyPos;
                wpyPos = -tmp;
                break;
            case 2:
                wpxPos = -wpxPos;
                wpyPos = -wpyPos;
                break;
            case 3:
                tmp = wpxPos;
                wpxPos = -wpyPos;
                wpyPos = tmp;
                break;
            }

        }

        cout << "Manhatten Distance is " << abs(xPos) + abs(yPos) << endl;
        return to_string(abs(xPos) + abs(yPos));
    }

}
