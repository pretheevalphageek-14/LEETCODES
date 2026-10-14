#include <string>
#include <algorithm>

class Solution {
public:
     std::string maximizeSumOfSquares(int num, int sum) {

        if ((long long)num * 9 < sum) {
            return "";
        }
        
        std::string result = "";
    
        while (sum >= 9 && result.length() < num) {
            result += '9';
            sum -= 9;
        }

        if (sum > 0 && result.length() < num) {
            result += std::to_string(sum);
            sum = 0;
        }
        while (result.length() < num) {
            result += '0';
        }
        
        return result;
    }
};