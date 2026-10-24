#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    
    int getDays(std::string date) {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));

        int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int totalDays = day;
        
        
        for (int m = 1; m < month; ++m) {
            if (m == 2 && isLeapYear(year)) {
                totalDays += 29; 
            } else {
                totalDays += daysInMonths[m - 1];
            }
        }
        
       
        for (int y = 1971; y < year; ++y) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }
        
        return totalDays;
    }

   
    int daysBetweenDates(std::string date1, std::string date2) {
        return std::abs(getDays(date1) - getDays(date2));
    }
};