#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> cur;
        dfs(ans, cur, 0, nums);
        return ans;
    }

    void dfs(vector<vector<int> >& ans, vector<int>& cur, int index, vector<int>& nums) {
        ans.push_back(cur);
        
        for (int i = index; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(ans, cur, i+1, nums);
            cur.pop_back();
        }
    
    }
};

int main() {
    Solution s;
    vector<int> candidates{ 1,2,3 };
    vector<vector<int> > ans = s.subsets(candidates);
    for (vector<int> v1 : ans) {
        cout << "[ ";
        for (int i : v1) {
            cout << i << " "; 
        }
        cout << "]" << endl;
    } 
    return 0;
}