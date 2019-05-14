<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());
        dp[0] = 0;
        int index = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[index]) {
                dp[i] = dp[i-1] + prices[i] - prices[index];
                index = i;
            } else {
                dp[i] = dp[i-1];
            }
        }
        return *max_element(dp.begin(), dp.end()); 
=======
class Solution {
public:
   int maxProfit(vector<int>& prices) {
        const int prices_size = prices.size();
        if (prices_size == 0)
            return 0;
        int dp_size = prices_size + 1;
        vector<int> dp(dp_size, 0);
        int temp_min = prices[0];
        for (int i = 1; i < dp_size; ++i) {
            int profit = prices[i - 1] - temp_min;
            dp[i] = max(profit, dp[i - 1]);
            if (prices[i - 1] < temp_min)
                temp_min = prices[i - 1];
        }
        return *max_element(dp.begin(), dp.end());
>>>>>>> 7a183c173adea401a4865f6f0c1c3c675d4dab0a
    }
};