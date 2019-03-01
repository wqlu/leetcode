#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, nums);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (contains(cur, nums[i])) {
                    continue;
                }
                cur.push_back(nums[i]);
                dfs(ans, cur, nums);
                cur.pop_back();
            }
        }
    }

    bool contains(vector<int>& cur, int num) {
        for (int i : cur) {
            if (i == num)
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> candidates{1, 2, 3};
    vector<vector<int> > ans = s.permute(candidates);
    for (vector<int> v1 : ans) {
        cout << "[ ";
        for (int i : v1) {
            cout << i << " "; 
        }
        cout << "]" << endl;
    } 
    return 0;
}