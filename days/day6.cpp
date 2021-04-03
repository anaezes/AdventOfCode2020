#include "days.hpp"
#include <vector>
#include <iostream>
#include <set>

void day6() {
    std::cout << "Day 6 \n";
    
    std::ifstream file_in = utils::getFile("days/inputs/day6.txt");

    std::vector<std::set<char>> answers;
    std::string line;

    int count = 0;
    while(std::getline(file_in, line))
    {
        std::set<char> answer;
        for(int i = 0; i < line.size(); i++)
            answer.insert(line[i]);
        while (std::getline(file_in, line)) {
            if(line.empty() || line[0] == '\n'){
                break;
            }
            for(int i = 0; i < line.size(); i++)
                answer.insert(line[i]);

        }
        count += answer.size();
    }

    std::cout << "Part One: " << count << std::endl;
}