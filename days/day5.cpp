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

int getIdMySeat(int id, int id1, std::vector<int> vector);

void day5() {
    std::cout << "Day 5 \n";

    std::vector<std::string> boardingPasses = utils::getVecDataStr("days/inputs/day5.txt");

    std::vector<int> idsSeats;
    int maxID = 0;
    int minID = INT32_MAX;
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

    std::cout << "Part One - max Id: " << maxID << std::endl;
    std::cout << "Part Two - my seat: " <<  getIdMySeat(minID, maxID, idsSeats) << std::endl;
}

int getIdMySeat(int minID, int maxID, std::vector<int> idsSeats) {
    for (int i = minID + 1; i < maxID; i++)
    {
        auto it = std::find(idsSeats.begin(), idsSeats.end(), i);
        if (it == idsSeats.end())
            return i;
    }
    return 0;
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
