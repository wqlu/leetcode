#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int nums_len = nums.size();
        if (nums_len <= 1) return nums_len;

        vector<int> dp(nums_len);
        dp[0] = 1;
        int res = 0;

        for (int i = 1; i < nums_len; ++i) {
            int count = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    count = max(dp[j] + 1, count);
            }
            dp[i] = count;
            res = max(res, count);
        }
        return res;
    }
};
