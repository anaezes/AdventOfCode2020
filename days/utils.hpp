#ifndef ADVENTOFCODE_UTILS_HPP
#define ADVENTOFCODE_UTILS_HPP

#include "days.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>

namespace utils {
    bool inRange(unsigned low, unsigned high, unsigned x);
    std::ifstream getFile(std::string file);
    void clearFile(std::ifstream &file_in);
}

#endif //ADVENTOFCODE_UTILS_HPP




