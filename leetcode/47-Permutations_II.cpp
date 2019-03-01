#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> used(nums.size());
        sort(nums.begin(), nums.end());
        dfs(ans, cur, used, nums);
        return ans;
    }


    void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& used, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
                used[i] = 1;
                cur.push_back(nums[i]);
                dfs(ans, cur, used, nums);
                cur.pop_back();
                used[i] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates{ 2, 1, 2, 2};
    vector<vector<int> > ans = s.permuteUnique(candidates);
    for (vector<int> v1 : ans) {
        cout << "[ ";
        for (int i : v1) {
            cout << i << " "; 
        }
        cout << "]" << endl;
    } 
    return 0;
}