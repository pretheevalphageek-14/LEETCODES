#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
        std::vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
     
        auto getDayOfYear = [&](std::string date) {
            int month = std::stoi(date.substr(0, 2));
            int day = std::stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };
        
       
        int aliceArrival = getDayOfYear(arriveAlice);
        int aliceLeave = getDayOfYear(leaveAlice);
        int bobArrival = getDayOfYear(arriveBob);
        int bobLeave = getDayOfYear(leaveBob);
        
        int latestArrival = std::max(aliceArrival, bobArrival);
        int earliestLeave = std::min(aliceLeave, bobLeave);
        
       
        if (latestArrival <= earliestLeave) {
            return earliestLeave - latestArrival + 1; 
        }
        
        return 0; 
    }
};