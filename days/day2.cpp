#include "days.hpp"

#include <algorithm>
#include <vector>
#include <regex>
#include <iostream>

void day2()
{
    std::cout << "Day 2 \n";

    std::ifstream file_in = utils::getFile("days/inputs/day2.txt");

    std::string line;
    std::vector<std::string> data;
    const std::regex expression("(\\d*)-(\\d*) ([a-z]): (\\w*)");
    while (std::getline(file_in, line)) {
        std::smatch result;
        const std::sregex_iterator end;
        for(std::sregex_iterator i(line.begin(), line.end(), expression); i != end; ++i)
        {
            std::string letter = (*i)[3];
            std::string str = (*i)[4];

            int ntimes = std::count(str.begin(), str.end(), letter[0]);

            if(utils::inRange(stoi((*i)[1]), stoi((*i)[2]), ntimes)) {
                data.push_back(str);
            }
        }
    }
    std::cout << "Part One - Number of valid passwords: " << data.size() << std::endl;

    utils::clearFile(file_in);
    data.clear();

    while (std::getline(file_in, line)) {
        std::smatch result;
        const std::sregex_iterator end;
        for(std::sregex_iterator i(line.begin(), line.end(), expression); i != end; ++i)
        {
            std::string letter = (*i)[3];
            std::string str = (*i)[4];

            int pos1 = stoi((*i)[1]);
            int pos2 = stoi((*i)[2]);

            if(str[pos1-1] == letter[0] ^ str[pos2-1] == letter[0])
                data.push_back(str);
        }
    }
    std::cout << "Part Two - Number of valid passwords: " << data.size() << std::endl;
}



