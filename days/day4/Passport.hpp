#ifndef ADVENTOFCODE_PASSPORT_HPP
#define ADVENTOFCODE_PASSPORT_HPP

#include <string>
#include <vector>
#include <map>

#include "../utils/utils.hpp"

class Passport {
public:
    bool isValid();
    Passport(const std::map<std::string, std::string>& );

private:

    const std::vector<std::string> colors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

    std::string birth_year;
    std::string issue_year;
    std::string expiration_year;
    std::string height;
    std::string hair_color;
    std::string eye_color;
    std::string passport_id;

    bool heightIsValid(std::string basicString);

    bool hairColorIsValid(std::string basicString);

    bool eyeColorIsValid(std::string basicString);

    bool passportIdIsValid(std::string basicString);
};


#endif //ADVENTOFCODE_PASSPORT_HPP
