#include <iostream>
#include <map>

#include "days/days.hpp"

typedef std::map<uint32_t, void(*)()> function;
function calender = {
        {1, &day1 },
        {2, &day2 },
        {3, &day3 },
        {4, &day4 },
        {5, &day5 },
        {6, &day6 },
        {7, &day7 },
        {8, &day8 }
};

int main() {
    std::cout << "Welcome to Advent of code 2020!" << std::endl;

    while (true)
    {
        int day;
        std::cout << "Please insert a day (1-31) or 0 to exit:" << std::endl;
        std::cin  >> day;

        if (day <= 0)
            break;

        auto it = calender.find(day);
        if ( it != calender.end() )
            it->second();
        else
            std::cout << "Ops! " << day << " day not found" << std::endl;

        std::cout << "\n-------------------------------------------\n\n";
    }

    return 0;
}

