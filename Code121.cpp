#include <iostream>
int main() {
    int arr[] = {12, 45, 7, 23, 56};
    int n = 5;
    int minVal = arr[0];
    int maxVal = arr[1];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    
    }
    if (maxVal == minVal){
            return 0;
        }
    return maxVal - minVal;
}



/*========================================================================================*/

#include <iostream>

int main() {
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = 6;
    int maxProfit = 0;

    // Outer loop picks the buy day (i)
    for (int i = 0; i < n; i++) {
        
        // Inner loop picks a future sell day (j)
        for (int j = i + 1; j < n; j++) {
            int profit = arr[j] - arr[i];
            
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    std::cout << "Max Profit: " << maxProfit << "\n";
    return maxProfit;
}