#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Always perform binary search on the smaller array to minimize the search space
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        int halfLen = (m + n + 1) / 2;
        
        while (low <= high) {
            int i = (low + high) / 2; // Partition index for nums1
            int j = halfLen - i;     // Partition index for nums2
            
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            // Check if partitions are correct
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is odd
                if ((m + n) % 2 == 1) {
                    return std::max(maxLeft1, maxLeft2);
                }
                // If total number of elements is even
                return (double)(std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
            } 
            else if (maxLeft1 > minRight2) {
                high = i - 1; // Too far right in nums1, shift partition left
            } 
            else {
                low = i + 1;  // Too far left in nums1, shift partition right
            }
        }
        
        return 0.0;
    }
};