//
//  Advent of Code 2020 Solutions: Day 11
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/18/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <vector>
#include <iostream>
#include <string>
#include <cstdio>

#define xInc(n) ((n) < 4 ? int(!(n%4 == 0)) : (-1 * int(!(n%4 == 0))))
#define yInc(n) ((((n) < 3) || ((n) > 6)) ? int(!((n-2)%4 == 0)) : (-1 * int(!((n-2)%4 == 0))))
#define inRange(n, b, t) ( ((n) > b) && ((n) < t) )

using namespace std;
namespace AocDay11 {

    char swapChar(int row, int col, char seat){
        char temp;
        if(seat == '#') temp = 'L';
        if(seat == 'L') temp = '#';
        return temp;
    }

    int printSeats(vector<string> input){
        for(int row = 0; row < input.size(); row++)
        {
            for(int column = 0; column < input[row].size(); column++)
            {
                cout << input[row][column];
            }
            cout << endl;
        }
        cout << endl;
        return 0;
    }

    bool leaveSeat(int row, int col, vector<string> input)
    {
        int filledSeats = 0;
        bool result = false;
        for(int i = row-1; i <= row+1; i++)
        {
            for(int j = col-1; j <= col+1; j++)
            {
                if(input[i][j] == '#') filledSeats++;
            }
        }
        if(input[row][col] == '#') filledSeats--;
        if(filledSeats >= 4) result = true;
        return result;
    }

    bool leaveSeatExt(int row, int col, vector<string> input)
    {
        int filledSeats = 0;
        int xMax = input[0].size();
        int yMax = input.size();
        bool result = false;

        for(int dir = 0; dir < 8; dir++)
        {
            int dis = 1;
            while(inRange((row + dis*yInc(dir)), 0, yMax) && inRange((col + dis*xInc(dir)), 0, xMax))
            {
                if(input[row + dis*yInc(dir)][col + dis*xInc(dir)] == 'L') break;
                if(input[row + dis*yInc(dir)][col + dis*xInc(dir)] == '#')
                {
                    filledSeats++;
                    break;
                }
                dis++;
            }
        }
        if(filledSeats >= 5) result = true;
        return result;
    }

    bool sitDown(int row, int col, vector<string> input)
    {
        int filledSeats = 0;
        bool result = false;
        for(int i = row-1; i <= row+1; i++)
        {
            for(int j = col-1; j <= col+1; j++)
            {
                if(input[i][j] == '#') filledSeats++;
            }
        }
        if(input[row][col] == '#') filledSeats--;
        if(filledSeats < 1) result = true;
        return result;
    }

    bool sitDownExt(int row, int col, vector<string> input)
    {
        int filledSeats = 0;
        int xMax = input[0].size();
        int yMax = input.size();
        bool result = false;
        //cout << row << col;
        for(int dir = 0; dir < 8; dir++)
        {
            int dis = 1;
            //cout << dir << " ";
            while(inRange((row + dis*yInc(dir)), 0, yMax) && inRange((col + dis*xInc(dir)), 0, xMax))
            {
                if(input[row + dis*yInc(dir)][col + dis*xInc(dir)] == 'L') break;
                else if(input[row + dis*yInc(dir)][col + dis*xInc(dir)] == '#')
                {
                    filledSeats++;
                    break;
                }
                //cout << dis;
                dis++;
            }
            //cout << filledSeats << endl;
        }
        if(filledSeats < 1) result = true;
        return result;
    }

    static const std::string InputFileName = "Day11.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        //pad input with a border
        for (int line = 0; line < input.size(); line++){
            input[line].insert(0, ".");
            input[line].insert(input[line].size(), ".");
        }
        string tmpString;
        for (int i = 0; i < input[0].size(); i++) tmpString.insert(0, ".");
        input.push_back(tmpString);
        input.insert(input.begin(), tmpString);

        bool match = false;
        vector<string> newInput = input;
        while(!match)
        {
            for(int row = 0; row < input.size(); row++)
            {
                for(int column = 0; column < input[row].size(); column++)
                {
                    if(input[row][column] != '.')
                    {
                        if(leaveSeat(row, column, input) && input[row][column] == '#') newInput[row][column] = swapChar(row, column, input[row][column]);
                        if(sitDown(row,column, input) && input[row][column] == 'L') newInput[row][column] = swapChar(row, column, input[row][column]);
                    }
                    else newInput[row][column] = '.';
                }
            }
            match = newInput == input;
            input = newInput;
        }
        int seatsOccupied = 0;
        for(int i = 0; i < input.size(); i++){
            for(int j = 0; j < input[0].size(); j++){
                if(input[i][j] == '#') seatsOccupied++;
            }
        }
        cout << "Seats Occupied = " << seatsOccupied << endl;

        return to_string(seatsOccupied);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        //pad input with a border
        for (int line = 0; line < input.size(); line++){
            input[line].insert(0, ".");
            input[line].insert(input[line].size(), ".");
        }
        string tmpString;
        for (int i = 0; i < input[0].size(); i++) tmpString.insert(0, ".");
        input.push_back(tmpString);
        input.insert(input.begin(), tmpString);

        bool match = false;
        vector<string> newInput = input;
        while(!match)
        {
            for(int row = 1; row < input.size(); row++)
            {
                for(int column = 1; column < input[row].size(); column++)
                {
                    if(input[row][column] != '.')
                    {
                        if(input[row][column] == '#')
                        {
                            if(leaveSeatExt(row, column, input)) newInput[row][column] = swapChar(row, column, input[row][column]);
                        }
                        else if(input[row][column] == 'L')
                        {
                            if(sitDownExt(row,column, input)) newInput[row][column] = swapChar(row, column, input[row][column]);
                        }
                    }
                    else newInput[row][column] = '.';
                }
            }
            match = newInput == input;
            input = newInput;
        }
        int seatsOccupied = 0;
        for(int i = 0; i < input.size(); i++){
            for(int j = 0; j < input[0].size(); j++){
                if(input[i][j] == '#') seatsOccupied++;
            }
        }
        cout << "Seats Occupied = " << seatsOccupied << endl;
        return to_string(seatsOccupied);
    }

}
