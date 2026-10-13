#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3}; // expected 2 1 3
    const int n = sizeof(arr) / sizeof(arr[0]);

    for (int e = 0; e + 1 < n; ++e) {
        if (e % 2 == 0) {
            if (arr[e] < arr[e + 1]) {
                swap(arr[e], arr[e + 1]);
                break;
            }
        } else if (arr[e] > arr[e - 1]) {
            swap(arr[e], arr[e - 1]);
        }
    }

    int score = 0;
    int bol = 1;

    for (int i = 0; i < n; ++i) {
        score += arr[i] * bol;
        bol *= -1;
    }

    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\nScore: " << score << endl;

    return 0;
}


//================================================================================Leet code================================================================================
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        
        // Step 1: Square all elements to eliminate signs
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            squares[i] = val * val;
        }
        
        // Step 2: Sort the squares in ascending order
        sort(squares.begin(), squares.end());
        
        long long score = 0;
        int negativeCount = n / 2; // Floor of n / 2 for negative slots
        
        // Step 3: Subtract the smallest squares and add the rest
        for (int i = 0; i < n; ++i) {
            if (i < negativeCount) {
                score -= squares[i];
            } else {
                score += squares[i];
            }
        }
        
        return score;
    }
};