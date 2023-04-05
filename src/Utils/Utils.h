//
// Created by Andy Nguyen on 30/03/2023.
//

#ifndef CPP_QLKS_UTILS_H
#define CPP_QLKS_UTILS_H

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <regex>


const std::string getString(const std::string& msg, int maxLen);

int getNumber(const std::string& msg);

int getNumberWithLimit(const std::string& msg, int limit);

const std::string getDate(const std::string& msg);

std::vector<int> stringsToInts(std::vector<std::string> strs);

int getNumberFromProvided(std::vector<std::string> strs);

bool userChoice();

#endif //CPP_QLKS_UTILS_H
