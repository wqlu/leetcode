class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 0;
        for (auto &num: nums) {
            if (num > target)
                break;
            dp[num] = 1;
        }
        for (int i = 1; i < target+1; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
               if (i < nums[j]) 
                   break;
                dp[i] += (unsigned long long)dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};