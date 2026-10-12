#include <climits>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the special overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // Use long long to safely handle absolute value of INT_MIN (-2147483648)
        long long a = std::abs((long long)dividend);
        long long b = std::abs((long long)divisor);
        
        long long left = 0, right = a;
        long long ans = 0;
        
        // Binary search for the quotient
        while (left <= right) {
            long long mid = left + ((right - left) >> 1);
            
            // Check if (mid * b) <= a without using multiplication '*'
            if (isLessOrEqual(mid, b, a)) {
                ans = mid;
                left = mid + 1;  // Try a larger quotient
            } else {
                right = mid - 1; // Try a smaller quotient
            }
        }
        
        return negative ? -ans : ans;
    }

private:
    bool isLessOrEqual(long long mid, long long b, long long target) {
        long long res = 0;
        long long temp_mid = mid;
        long long temp_b = b;
        
        while (temp_mid > 0) {
            if (temp_mid & 1) {
                res += temp_b;
                if (res > target) {
                    return false;
                }
            }
            temp_b <<= 1;
            temp_mid >>= 1;
        }
        
        return res <= target;
    }
};

/*======================================================================LEET CODE======================================================================*/

#include <climits>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the final sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = std::abs((long long)dividend);
        long long dvs = std::abs((long long)divisor);
        long long ans = 0;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            ans += multiple;
        }
        
        return negative ? -ans : ans;
    }
};