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
    }
};