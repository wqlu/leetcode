class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto itor : nums) {
            ans = ans ^ itor;
        }
        return ans;
    }
};