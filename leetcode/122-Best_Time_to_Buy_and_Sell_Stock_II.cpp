class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int prices_size = prices.size();
        if (prices_size == 0) return 0;
        int maxProfit = 0;
        for (int i = 1; i < prices_size; ++i) {
            if (prices[i] <= prices[i - 1]) continue;
            maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }
};