#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int position = i + 1; // Convert 0-indexed to 1-indexed
            if (n % position == 0) {
                sum += nums[i] * nums[i];
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << "Sum: " << sol.sumOfSquares(nums) << endl;
    return 0;
}

/*=================================================== LEET CODE ===============================================*/

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int position = i + 1;
            
            if (n % position == 0) {
                sum += nums[i] * nums[i]; 
            }
        }

        return sum;
    }
};