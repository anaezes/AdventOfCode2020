#include "days.hpp"
#include <vector>
#include <iostream>
#include <set>
#include <regex>
#include <algorithm>
#include <list>

int getNumColors(std::vector<std::string> rules);


void day7() {
    std::cout << "Day 7 \n";

    std::vector<std::string> rules = utils::getVecDataStr("days/inputs/day7.txt");

    std::cout << "Part One - " << getNumColors(rules) << std::endl;
}

int getNumColors(std::vector<std::string> rules)
{
    std::vector<std::string> colors;
    std::string line;

    colors.push_back("shiny gold");

    int len = colors.size();
    for(size_t i = 0; i < len; i++) {

        std::string colorToSearch = colors.at(i);
        std::vector<std::string> filterRules;
        for (auto r : rules) {
            size_t found = r.find(colorToSearch);
            if (found != std::string::npos) {
                filterRules.push_back(r);
            }
        }

        if(filterRules.empty()) {
            continue;
        }

        const std::regex expression("(\\w*) (\\w*) bag");
        for (auto f : filterRules) {
            std::smatch result;
            std::sregex_iterator i(f.begin(), f.end(), expression);
            std::string color = ((*i)[1]).str() + " " + ((*i)[2]).str();

            if(color != colorToSearch) {
                auto result = std::find(begin(colors), end(colors), color);
                if (result == std::end(colors)) {
                    colors.push_back(color);
                    ++len;
                }
            }
        }

        for (auto r : filterRules) {
            auto result = std::find(begin(rules), end(rules), r);
            if (result != std::end(rules)) {
                rules.erase(result);
            }
        }
    }
    return colors.size()-1;
}