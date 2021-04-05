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

        for(int i = 0; i < line.size(); i++) {
            answer1.insert(line[i]);
            answer2.push_back({line[i], 1});
        }
        while (std::getline(file_in, line)) {
            if(line.empty() || line[0] == '\n'){
                break;
            }
            nGroup++;
            for(int i = 0; i < line.size(); i++) {
                answer1.insert(line[i]);
                for(int j = 0; j < answer2.size(); j++) {
                    if(answer2.at(j).first == line[i])
                        answer2.at(j).second++;
                }
            }
        }
        count1 += answer1.size();
        for(auto a: answer2)
        {
            if(a.second == nGroup)
                count2 ++;
        }
    }

    std::cout << "Part One: " << count1 << std::endl;
    std::cout << "Part Two: " << count2 << std::endl;
}