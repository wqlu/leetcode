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
    }
};