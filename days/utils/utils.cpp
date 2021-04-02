#include <iostream>

#include "utils.hpp"

bool utils::inRange(unsigned low, unsigned high, unsigned x)
{
    return (low <= x && x <= high);
}

std::ifstream utils::getFile(std::string file)
{
    std::ifstream file_in(file);
    if (!file_in) {
        std::cout << "Error! File inputs not found!" << std::endl;
    }
    return file_in;
}

void utils::clearFile(std::ifstream &file_in)
{
    file_in.clear();
    file_in.seekg(0, std::ios::beg);
}

bool utils::isNumber(std::string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}


