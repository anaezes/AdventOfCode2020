#include "days.hpp"
#include <vector>
#include <iostream>

using namespace std;

void day3()
{
    std::cout << "Day 3 \n";

    std::ifstream file_in = utils::getFile("days/input/day3.txt");

    std::vector<string> data;
    std::string line;
    while (std::getline(file_in, line))
        data.push_back(line);

    int down_coordinate = 0;
    int right_coordinate = 0;
    int tree_counter = 0;

    int xLength = (data.at(0)).length();
    while (down_coordinate < data.size() - 1 )
    {
        right_coordinate += 3;
        down_coordinate += 1;

        int map_x = right_coordinate % xLength;
        if (data.at(down_coordinate)[map_x] == '#')
            tree_counter++;
    }

    std::cout << "Part One - " << tree_counter << std::endl;
}


