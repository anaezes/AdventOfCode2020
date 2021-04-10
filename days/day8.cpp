#include "days.hpp"
#include <vector>
#include <iostream>
#include <set>
#include <tuple>
#include <regex>

int getFirstPart(std::vector<std::tuple<std::string, int, bool>> instructions);
//int getSecondPart(std::vector<std::tuple<std::string, int, bool, bool>> instructions);

void day8() {
    std::cout << "Day 8 \n";

    std::ifstream file_in = utils::getFile("days/inputs/day8.txt");

    std::string line;
    std::vector<std::tuple<std::string, int, bool>> instructions;
    std::vector<std::tuple<std::string, int, bool, bool>> instructions2;
    while (std::getline(file_in, line)) {
        std::stringstream ss;
        ss << line;

        std::string temp;

        std::string operation;
        int argument;

        while (!ss.eof()) {

            ss >> temp;
            std::stringstream(temp) >> operation;

            ss >> temp;
            std::stringstream(temp) >> argument;

            instructions.push_back({operation, argument, false});
            //instructions2.push_back({operation, argument, false, false});

            temp = "";
        }
    }

    int result = getFirstPart(instructions);
    std::cout << "Part One: " << result << std::endl;
    //std::cout << "Part Two: " <<  getSecondPart(instructions2) << std::endl;
}

int getFirstPart(std::vector<std::tuple<std::string, int, bool>> instructions) {
    int accumulator = 0;
    int i = 0;
    while (i < instructions.size()) {

        auto [operation, argument, called] = instructions.at(i);

        if(called){
            std::cout << "Its a trap! \n";
            break;
        }

        std::get<2>(instructions.at(i)) = true;

        if(operation == "jmp")
        {
            i+= argument;
            continue;
        }
        else if(operation == "acc")
            accumulator += argument;
        ++i;
    }
    return accumulator;
}

/*int getSecondPart(std::vector<std::tuple<std::string, int, bool, bool>> instructions) {
    bool reverse = false;
    std::vector<int> order;
    int accumulator = 0;
    int i = 0;
    int j = 0;

    while (i < instructions.size()) {
        if(!reverse) {
            auto [operation, argument, called, used] = instructions.at(i);

            if (called) {
                std::cout << "It's a loop! \n";
                reverse = true;
                j = order.size()-1;
                continue;
            }

            order.push_back(i);

            if (operation == "jmp") {
                std::get<2>(instructions.at(i)) = true; //mark jmp called
                i += argument;
                continue;
            } else if (operation == "acc")
                accumulator += argument;
            ++i;
        }
        else {
            i = order.at(j);
            auto [operation, argument, called, used] = instructions.at(i);
            order.pop_back();

            if(used) {
                order.pop_back();
                j--;
                continue;
            }

            if (operation == "acc") {
                std::get<2>(instructions.at(i)) = false;
                accumulator -= argument;
                order.pop_back();
                j--;
                continue;
            }

            if (operation == "nop") {
                i+=argument;
            }
            else {
                i++;
            }

            std::get<3>(instructions.at(i)) = true; // mark used
            reverse = false;
            //i--;
        }
    }

    i = 0;
    while (i < instructions.size()) {
        auto[operation, argument, called, used] = instructions.at(i);
        std::cout << operation << " " << argument << "\n";
        ++i;
    }
    return accumulator;
}*/

