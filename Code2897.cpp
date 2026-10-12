#include <vector>

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
       
        vector<int> count(32, 0);
        
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num >> i) & 1) {
                    count[i]++;
                }
            }
        }
        
        long long total_sum = 0;
        long long MOD = 1e9 + 7;
        for (int i = 0; i < k; ++i) {
            long long current_num = 0;
            for (int bit = 31; bit >= 0; --bit) {
                if (count[bit] > 0) {
                    current_num |= (1LL << bit); 
                    count[bit]--;                
                }
            }
            
            total_sum = (total_sum + (current_num * current_num) % MOD) % MOD;
        }
        
        return total_sum;
    }
};