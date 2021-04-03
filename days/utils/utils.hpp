#ifndef ADVENTOFCODE_UTILS_HPP
#define ADVENTOFCODE_UTILS_HPP

#include "../days.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

namespace utils {
    bool inRange(unsigned low, unsigned high, unsigned x);
    std::vector<std::string> getVecDataStr(std::string file);
    std::vector<int> getVecDataInt(std::string file);
    std::ifstream getFile(std::string file);
    void clearFile(std::ifstream &file_in);
    bool isNumber(std::string s);
}

#endif //ADVENTOFCODE_UTILS_HPP




