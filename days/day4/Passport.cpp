#include "Passport.hpp"

#include <iterator>
#include <regex>
#include <algorithm>

Passport::Passport(const std::map<std::string, std::string> &map)
{
    auto it = map.begin();
    while (it != map.end())
    {
        std::string key = it->first;
        std::string value = it->second;

        if(key == "byr"){
            birth_year = value;
        }
        else if(key == "ecl") {
            eye_color = value;
        }
        else if(key == "eyr") {
            expiration_year = value;
        }
        else if(key == "hcl") {
            hair_color = value;
        }
        else if(key == "hgt") {
            height = value;
        }
        else if(key == "iyr") {
            issue_year = value;
        }
        else if(key == "pid") {
            passport_id = value;
        }

        it++;
    }
}

bool Passport::isValid() {

    //four digits; at least 1920 and at most 2002
    if(birth_year.size() != 4 || !utils::inRange(1920,2002, std::stoi(birth_year))) {
        return false;
    }

    //four digits; at least 2010 and at most 2020.
    if(issue_year.size() != 4 || !utils::inRange(2010,2020, std::stoi(issue_year))) {
        return false;
    }

    // four digits; at least 2020 and at most 2030.
    if(expiration_year.size() != 4 || !utils::inRange(2020,2030, std::stoi(expiration_year))) {
        return false;
    }

    if(utils::isNumber(height) || !heightIsValid(height)) {
        return false;
    }

    if(!hairColorIsValid(hair_color)) {
        return false;
    }

    if(!eyeColorIsValid(eye_color)) {
        return false;
    }

    if( passport_id.size() != 9 || !passportIdIsValid(passport_id)) {
        return false;
    }

    return true;
}

bool Passport::heightIsValid(std::string height) {

    if(std::regex_match(height, std::regex("([0-9]{3}[cm])\\w+"))){
        std::string value = height.substr(0, (height.find('c')));
        if(utils::inRange(150, 193, std::stoi(value)))
            return true;
    }

    if(std::regex_match(height, std::regex("([0-9]{2}[in])\\w+"))){
        std::string value = height.substr(0, (height.find('i')));
        if(utils::inRange(59, 76, std::stoi(value)))
            return true;
    }

    return false;
}

//a # followed by exactly six characters 0-9 or a-f.
bool Passport::hairColorIsValid(std::string color) {
    return std::regex_match(color, std::regex("(#[a-z0-9]{6})\\w*"));
}

//exactly one of: amb blu brn gry grn hzl oth.
bool Passport::eyeColorIsValid(std::string color) {
    auto result = std::find(begin(colors), end(colors), color);
    return result != std::end(colors);
}

// a nine-digit number, including leading zeroes.
bool Passport::passportIdIsValid(std::string id) {
    return std::regex_match(id, std::regex("([0-9])\\w{8}"));
}
