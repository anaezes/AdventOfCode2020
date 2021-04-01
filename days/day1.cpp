#include <iostream>
#include <fstream>
#include <vector>

#include "days.h"

using namespace std;

void day1()
{
    cout << "Day One \n";

    std::ifstream file_in("days/input/day1.txt");
    if (!file_in) {
        cout << "Error! File input not found!" << endl;
    }

    std::vector<int> data;
    std::string line;
    while (std::getline(file_in, line))
        data.push_back(stoi(line));

    for(auto val1: data) {
        for(auto val2: data) {
            if(val1 + val2 == 2020) {
                cout << val1 << " * " << val2 << " = "<< val1 * val2 << endl;
            }
        }
    }
}

