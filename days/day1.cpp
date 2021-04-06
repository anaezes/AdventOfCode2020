#include "days.hpp"

#include <iostream>
#include <vector>

void day1()
{
    std::cout << "Day 1 \n";

    std::vector<int> data = utils::getVecDataInt("days/inputs/day1.txt");

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

