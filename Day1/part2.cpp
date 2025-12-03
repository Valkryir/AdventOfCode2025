//
// Created by Madeleine on 1/12/2025.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    cout << "ADVENT OF CODE 2025 DAY 1 PART 2" << endl;

    // Create a text string, which is used to output the text file
    //ifstream file("../Day1/test_input.txt");
    ifstream file("../Day1/input.txt");
    string content;

    vector<string> instructions;

    int currentPos = 50;
    int maxPos = 99;

    int zeroCount = 0;

    while(getline(file, content)) {
        instructions.push_back(content);
    }

    for (string inst : instructions ) {
        char dir = inst[0];
        inst.erase(0, 1);

        if (dir == 'L') {
            int distance = stoi(inst);
            for (int i = 0; i < distance; ++i) {
                --currentPos;
                if (currentPos < 0) {
                    currentPos = maxPos;
                    ++zeroCount;
                }
            }
        }

        if (dir == 'R') {
            int distance = stoi(inst);
            for (int i = 0; i < distance; ++i) {
                ++currentPos;
                if (currentPos > 99) {
                    currentPos = 0;
                    ++zeroCount;
                }
            }
        }

//        if (currentPos == 0) {
//            ++zeroCount;
//        }

        //cout << currentPos << endl;
    }

    cout << "Zero Count: ";
    cout << zeroCount << endl;

    return 0; // End of the program
}