#include "days.hpp"
#include <vector>
#include <iostream>
#include <set>

void day6() {
    std::cout << "Day 6 \n";
    
    std::ifstream file_in = utils::getFile("days/inputs/day6.txt");

    std::vector<std::set<char>> answers;
    std::string line;

    int count1 = 0;
    int count2 = 0;
    while(std::getline(file_in, line))
    {
        std::set<char> answer1;
        std::vector<std::pair<char, int>> answer2;
        int nGroup = 1;

        for(auto c1 : line) {
            answer1.insert(c1);
            answer2.push_back({c1, 1});
        }
        while (std::getline(file_in, line)) {
            if(line.empty() || line[0] == '\n'){
                break;
            }
            nGroup++;
            for(auto c2 : line) {
                answer1.insert(c2);
                for(auto& a: answer2) {
                    if(a.first == c2)
                        a.second++;
                }
            }
        }
        count1 += answer1.size();
        for(auto a: answer2)
        {
            if(a.second == nGroup)
                count2++;
        }
    }

    std::cout << "Part One: " << count1 << std::endl;
    std::cout << "Part Two: " << count2 << std::endl;
}