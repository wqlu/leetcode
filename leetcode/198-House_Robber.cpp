class Solution {
public:
    int rob(vector<int>& nums) {
        const int nums_size = nums.size();
        vector<int> dp(nums_size + 1, INT_MIN);
        if (nums_size == 0) return 0;
        if (nums_size == 1) return nums[0];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums_size; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[nums_size];
    }
};