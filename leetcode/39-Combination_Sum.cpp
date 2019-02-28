#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(ans, cur, 0, candidates, target);
        return ans;
    }

    void dfs(vector<vector<int> >& ans, vector<int>& cur, int index, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(cur);
			return;
        } else if (target < 0) {
            return;
        } else {
            for (int i = index; i < candidates.size();i++) {
                cur.push_back(candidates[i]);
                dfs(ans, cur, i, candidates, target - candidate);
                cur.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates;
    candidates = {2, 3, 6, 7};
    vector<vector<int> > ans = s.combinationSum(candidates, 7);
    for (vector<int> v1 : ans) {
        cout << "[ ";
        for (int i : v1) {
            cout << i << " "; 
        }
        cout << "]" << endl;
    } 
    return 0;
}