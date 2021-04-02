cmake_minimum_required(VERSION 3.17)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp days/day1.cpp days/day2.cpp days/days.hpp days/utils/utils.cpp days/utils/utils.hpp days/day3.cpp days/day4/day4.cpp days/day4/Passport.cpp days/day4/Passport.hpp)
