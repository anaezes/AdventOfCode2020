#include "days.hpp"
#include <vector>
#include <iostream>
#include <utility>      // std::pair, std::make_pair

const int MAX_ROW = 127;
const int MAX_COL = 7;

const int ROW_SIZE = 7;
const int COL_SIZE = 3;

const int ID_FACTOR = 8;

int getSeat(const std::string &str, char first, char second, int max,  int size);

void day5() {
    std::cout << "Day 5 \n";

    std::ifstream file_in = utils::getFile("days/inputs/day5.txt");

    std::vector<std::string> boardingPasses;
    std::string line;
    while (std::getline(file_in, line))
        boardingPasses.push_back(line);

    std::vector<int> idsSeats;
    int maxID = 0;
    int minID = 1000;
    for(auto bp: boardingPasses) {
        std::string rowStr = bp.substr(0, 7);
        std::string colStr = bp.substr(7, bp.size());

        int col =  getSeat(colStr, 'R', 'L', MAX_COL, COL_SIZE);
        int row =  getSeat(rowStr, 'B', 'F', MAX_ROW, ROW_SIZE);

        int id = row * ID_FACTOR + col;
        idsSeats.push_back(id);
        if(id < minID) minID = id;
        if(id > maxID) maxID = id;
    }

    std::cout << "Part One - " << maxID << std::endl;

    for (int i = minID + 1; i < maxID; i++)
    {
        auto it = std::find(idsSeats.begin(), idsSeats.end(), i);
        if (it == idsSeats.end()) {
            std::cout << "Part Two - " << i << std::endl;
            break;
        }
    }
}

int getSeat(const std::string &str, char first, char second, int max,  int size) {
    std::pair <int,int> range(0, max);
    int i = 0;
    while(range.first != range.second && i < size) {
        if (str[i] == first) {
            range.first += ((range.second - range.first + 1 ) / 2);
        } else if (str[i] == second) {
            range.second -= ((range.second - range.first + 1) / 2);
        }
        i++;
    }
    return range.first;
}
