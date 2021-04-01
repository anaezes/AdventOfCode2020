#include <iostream>
#include <map>

#include "days/days.h"

using namespace std;

typedef std::map<uint32_t, void(*)()> function;
function calender = {
        {1, &day1 },
        {2, &day2 }
};

int main() {
    cout << "Hello, World!" << endl;
    cout << "Welcome to Advent of code 2020!" << endl;

    while (true)
    {
        int day;
        cout << "Please insert a day (1-31) or 0 to exit:" << endl;
        cin  >> day;

        if (day <= 0)
            break;

        auto it = calender.find(day);
        if ( it != calender.end() )
            it->second();
        else
            cout << "Ops! " << day << " day not found" << endl;

        cout << endl << endl;
    }

    return 0;
}
