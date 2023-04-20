//
// Created by Andy Nguyen on 30/03/2023.
//

#include "Utils.h"

/*
This function takes user input check if it`s correct , if so return it.
@param msg - message to show for user in console
@param maxLen - maximal length of inputed by user string
@return string
*/
const std::string getString(const std::string& msg, int maxLen)
{
    std::string s;
    std::cout << msg;
    std::getline(std::cin >> std::ws, s);

    while (s.empty())
    {
        std::cout << "Vui long nhap gia tri: ";
        std::getline(std::cin, s);
    }

    while (s.size() > maxLen) {
        printf("Qua dai vui long nhap duoi %d ki tu: ", maxLen);
        std::getline(std::cin, s);
    }
    return s;
}
/*
This function takes user input check if it`s int , if so return it.
@param msg - message to show for user in console
@return int
*/
int getNumber(const std::string& msg)
{
    int number = 0;
    std::cout << msg;
    while (!(std::cin >> number))
    {
        std::cout << "Vui long nhap lai:";
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    return number;
}

int getNumberWithLimit(const std::string& msg, int limit)
{
    int number = 0;
    std::cout << msg;
    while ((!(std::cin >> number)) || number > limit)
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    return number;
}

/*
	Convert strings to ints.
	@param strs - a vector of strings to conert
*/
std::vector<int> stringsToInts(std::vector<std::string> strs)
{
    std::vector<int> nums;
    if (strs.empty()) {
        return std::vector<int>();
    }
    for (std::string i : strs) {
        int num = std::stoi(i);
        nums.push_back(num);
    }
    return nums;
}

int getNumberFromProvided(std::vector<std::string> strs)
{
    //converting to ints
    std::vector<int> nums = stringsToInts(strs);

    if (nums.empty()) {
        return 0;
    }

    bool numberIsInVec = false;
    int badInputNum = 0;
    int num;

    while (!numberIsInVec) {
        if (badInputNum == 0) {
            num = getNumber("Enter the number you have dialed: ");
        }
        else {
            num = getNumber("Select number from the list. Try again: ");
        }

        for (int i : nums) {
            if (i == num) {
                numberIsInVec = true;
            }
        }
        badInputNum++;
    }
    return num;
}

bool userChoice()
{
    std::string choice = getString("What's your choice ,type (y/n): ", 1);
    if (choice == "Y" || choice == "y")
        return true;

    return false;
}

const std::string getDate(const std::string &msg) {
    std::regex date_regex("^(\\d{4})-(0?[1-9]|1[0-2])-(0?[1-9]|[12][0-9]|3[01])\\s([01]?[0-9]|2[0-3]):([0-5][0-9])(:([0-5][0-9]))?$");
    std::string s;
    std::cout << msg;
    std::getline(std::cin >> std::ws, s);

    while (s.empty())
    {
        std::cout << "Vui long nhap thoi gian (YYYY-MM-DD HH:MI:SS)\n";
        std::cout << msg;
        std::getline(std::cin, s);
    }

    while (!std::regex_match(s, date_regex)) {
        std::cout << "Sai dinh dang vui long nhap lai (YYYY-MM-DD HH:MI:SS)\n";
        std::cout << msg;
        std::getline(std::cin, s);
    }
    return s;
}

float calculateTimeDiff(const std::string &time1, const std::string &time2) {
    struct std::tm tm1 = {0}, tm2 = {0};
    std::istringstream ss1(time1), ss2(time2);
    ss1 >> std::get_time(&tm1, "%Y-%m-%d %H:%M");
    ss2 >> std::get_time(&tm2, "%Y-%m-%d %H:%M");
    std::time_t t1 = std::mktime(&tm1),
    t2 = std::mktime(&tm2);

    return (float)(t2 - t1) / 3600; // return difference in hours
}

void clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}
