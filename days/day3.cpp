#include "days.hpp"
#include <vector>
#include <iostream>

unsigned int countTrees(std::vector<std::string> map, unsigned int incrementY, unsigned int incrementX);

void day3()
{
    std::cout << "Day 3 \n";

    std::vector<std::string> data = utils::getVecDataStr("days/inputs/day3.txt");

    unsigned total = countTrees(data, 1, 3);
    std::cout << "Part One - " << total << std::endl;

    total *= countTrees(data, 1, 1);
    total *= countTrees(data, 1, 5);
    total *= countTrees(data, 1, 7);
    total *= countTrees(data, 2, 1);
    std::cout << "Part Two - " << total << std::endl;
}

unsigned int countTrees(std::vector<std::string> map, unsigned int incrementY, unsigned int incrementX)
{
    int down_coordinate = 0;
    int right_coordinate = 0;
    int tree_counter = 0;

    int xLength = (map.at(0)).length();
    while (down_coordinate < map.size() - 1 )
    {
        right_coordinate += incrementX;
        down_coordinate += incrementY;

        if (map.at(down_coordinate)[right_coordinate % xLength] == '#')
            tree_counter++;
    }

    return tree_counter;
}


