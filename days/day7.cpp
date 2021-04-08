#include "days.hpp"
#include <vector>
#include <iostream>
#include <set>
#include <regex>
#include <algorithm>

const std::regex EXPRESSION("(\\w*) (\\w*) bag");
const std::string MAIN_COLOR = "shiny gold";

int getNumColors(std::vector<std::string> rules);
int getNumBags(std::vector<std::string> rules);


void day7() {
    std::cout << "Day 7 \n";

    std::vector<std::string> rules = utils::getVecDataStr("days/inputs/day7.txt");
    std::cout << "Part One - " << getNumColors(rules) << std::endl;
    std::cout << "Part Two - " << getNumBags(rules) << std::endl;
}

int getNumColors(std::vector<std::string> rules)
{
    std::vector<std::string> colors;
    std::string line;

    colors.push_back(MAIN_COLOR);

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

        for (auto f : filterRules) {
            std::smatch result;
            std::sregex_iterator i(f.begin(), f.end(), EXPRESSION);
            std::string newColor = ((*i)[1]).str() + " " + ((*i)[2]).str();

            if(newColor != colorToSearch) {
                auto result = std::find(begin(colors), end(colors), newColor);
                if (result == std::end(colors)) {
                    colors.push_back(newColor);
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

void extractIntegerWords(std::vector<std::pair<std::string, int>> &colorsWithQuantity, std::string str, int numberBags)
{
    std::stringstream ss;
    ss << str;

    std::string temp;
    int quantity;
    std::string color1, color2;
    while (!ss.eof()) {
        ss >> temp;
        if (std::stringstream(temp) >> quantity) {
            ss >> temp;
            std::stringstream(temp) >> color1;
            ss >> temp;
            std::stringstream(temp) >> color2;
            colorsWithQuantity.push_back({color1 + " " + color2, quantity*numberBags});
        }
        temp = "";
    }
}

std::string getQuoteWithColor(std::vector<std::string> rules, std::string colorToSearch ){
    for (auto f : rules) {
        std::smatch result;
        std::sregex_iterator i(f.begin(), f.end(), EXPRESSION);
        std::string color = ((*i)[1]).str() + " " + ((*i)[2]).str();

        if(color == colorToSearch)
            return f;
    }
    return "";
}

int getNumBags(std::vector<std::string> rules)
{
    std::vector<std::pair<std::string, int>> colorsWithQuantity;
    colorsWithQuantity.push_back({MAIN_COLOR, 1});

    int result = 0;
    int len = colorsWithQuantity.size();
    for(size_t i = 0; i < len; i++) {
        auto [color, quantity] = colorsWithQuantity.at(i);
        std::string quote = getQuoteWithColor(rules, color);
        extractIntegerWords(colorsWithQuantity, quote, quantity);
        len = colorsWithQuantity.size();
        result += quantity;
    }
    return result-1;
}