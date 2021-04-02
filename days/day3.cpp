#include "days.hpp"
#include <vector>
#include <iostream>

using namespace std;

unsigned int countTrees(vector<string> map, unsigned int incrementY, unsigned int incrementX)
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

void day3()
{
    std::cout << "Day 3 \n";

    std::ifstream file_in = utils::getFile("days/input/day3.txt");

    vector<string> data;
    string line;
    while (std::getline(file_in, line))
        data.push_back(line);

    unsigned total = countTrees(data, 1, 3);
    std::cout << "Part One - " << total << std::endl;

    total *= countTrees(data, 1, 1);
    total *= countTrees(data, 1, 5);
    total *= countTrees(data, 1, 7);
    total *= countTrees(data, 2, 1);
    std::cout << "Part Two - " << total << std::endl;
}


