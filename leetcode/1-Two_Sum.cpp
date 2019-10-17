#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        auto pDiff = m.find(target - nums[i]);
        if (pDiff != m.end()) {
            ans.push_back(m[target - nums[i]] + 1);
            ans.push_back(i + 1);
            return ans;
        }
        m[nums[i]] = i;
    }
}
