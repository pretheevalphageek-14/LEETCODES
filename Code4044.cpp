class Solution {
    public int countGoodRotations(int[] nums) {
        return solve(nums, 0);
    }

    private int solve(int[] nums, int rotations) {
        if (rotations == nums.length) {
            return 0;
        }

        int n = nums.length;
        int half = n / 2;
        long sumFirstHalf = 0;
        long sumSecondHalf = 0;

        for (int i = 0; i < half; i++) {
            sumFirstHalf += nums[i];
            sumSecondHalf += nums[i + half];
        }

        int count = (sumFirstHalf > sumSecondHalf) ? 1 : 0;

        rotate(nums);
        return count + solve(nums, rotations + 1);
    }

    private void rotate(int[] nums) {
        int temp = nums[0];
        for (int i = 0; i < nums.length - 1; i++) {
            nums[i] = nums[i + 1];
        }
        nums[nums.length - 1] = temp;
    }
}

//==========================================================================================================================================================

#include <vector>

class Solution {
public:
    int countGoodRotations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int half = n / 2;
        
        std::vector<long long> ext(2 * n);
        for (int i = 0; i < n; ++i) {
            ext[i] = nums[i];
            ext[i + n] = nums[i];
        }

        long long sumFirst = 0;
        long long sumSecond = 0;

        for (int i = 0; i < half; ++i) {
            sumFirst += ext[i];
            sumSecond += ext[i + half];
        }

        int count = 0;
        if (sumFirst > sumSecond) {
            count++;
        }

        for (int k = 1; k < n; ++k) {
            sumFirst = sumFirst - ext[k - 1] + ext[k + half - 1];
            sumSecond = sumSecond - ext[k + half - 1] + ext[k + 2 * half - 1];

            if (sumFirst > sumSecond) {
                count++;
            }
        }

        return count;
    }
};