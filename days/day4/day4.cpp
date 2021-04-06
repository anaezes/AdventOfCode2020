#include "../days.hpp"
#include "Passport.hpp"

#include <vector>
#include <iostream>
#include <regex>
#include <algorithm>
#include <map>

const std::vector<std::string> keys = {"byr", "ecl", "eyr", "hcl", "hgt", "iyr", "pid" };

std::vector<std::string> getPassports();

void day4() {
    std::cout << "Day 4 \n";

    std::vector<std::string> passports = getPassports();

    const std::regex expression("([\\w]*:[#a-z0-9])\\w*");
    int validPassportsCount1 = 0;
    int validPassportsCount2 = 0;

    for(auto p: passports) {
        std::smatch result;
        const std::sregex_iterator end;
        std::vector<std::string> vecData;
        std::map<std::string, std::string> mapData;
        for (std::sregex_iterator i(p.begin(), p.end(), expression); i != end; ++i) {
            std::string field = (*i)[0];
            std::string key = field.substr(0, (field.find(':')));

            //part one
            if(key == "cid"){
                continue;
            }
            vecData.push_back(key);

            //part two
            std::string value = field.substr((field.find(':'))+1);
            mapData.insert({ key, value });
        }

        // solve part one
        std::sort(vecData.begin(), vecData.end());
        if(std::equal(keys.begin(), keys.end(), vecData.begin()) && vecData.size() == keys.size()){
            validPassportsCount1++;
        }

        //solve part two
        Passport passport_tmp(mapData);
        if(passport_tmp.isValid()){
            validPassportsCount2++;
        }
    }

    std::cout << "Part One - " << validPassportsCount1 << std::endl;
    std::cout << "Part Two - " << validPassportsCount2 << std::endl;
}

std::vector<std::string> getPassports() {
    std::ifstream file_in = utils::getFile("days/inputs/day4.txt");

    std::vector<std::string> passaports;
    std::string line;

    while(std::getline(file_in, line)) {
        std::string passaport = line;
        while (std::getline(file_in, line)) {
            if(line.empty() || line[0] == '\n'){
                break;
            }
            passaport = passaport + " " + line;
        }
        passaports.push_back(passaport);
    }
    return passaports;
}