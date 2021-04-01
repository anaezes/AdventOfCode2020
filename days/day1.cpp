#include "days.hpp"

#include <iostream>
#include <vector>

using namespace std;

void day1()
{
    std::cout << "Day 1 \n";

    std::ifstream file_in = utils::getFile("days/input/day1.txt");

    std::vector<int> data;
    std::string line;
    while (std::getline(file_in, line))
        data.push_back(stoi(line));

    for(auto val1: data) {
        for(auto val2: data) {
            if(val1 + val2 == 2020) {
                std::cout << "Part One - " << val1 << " * " << val2 << " = "<< val1 * val2 << std::endl;
                goto next;
            }
        }
    }

    next:

    for(auto val1: data) {
        for(auto val2: data) {
            for(auto val3: data) {
                if (val1 + val2 + val3 == 2020) {
                    std::cout << "Part Two - " << val1 << " * " << val2 << " * " << val3 << " = " << val1 * val2 * val3 << std::endl;
                    goto finish;
                }
            }
        }
    }

    finish: return;
}

