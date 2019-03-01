#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        set<vector<int> > ans;
        vector<int> cur;
        // 需要进行排序
        sort(nums.begin(); nums.end());
        dfs(ans, cur, 0, nums);
        return vector<vector<int> > (ans.begin(), ans.end());
    }

    void dfs(set<vector<int> >& ans, vector<int>& cur, int index, vector<int>& nums) {
        ans.insert(cur);
        
        for (int i = index; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(ans, cur, i+1, nums);
            cur.pop_back();
        }
    
    }
};

int main() {
    Solution s;
    vector<int> candidates{ 1,2,2 };
    vector<vector<int> > ans = s.subsetsWithDup(candidates);
    for (vector<int> v1 : ans) {
        cout << "[ ";
        for (int i : v1) {
            cout << i << " "; 
        }
        cout << "]" << endl;
    } 
    return 0;
}