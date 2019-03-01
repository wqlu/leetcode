#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        set<vector<int> > ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(ans, cur, 0, candidates, target);
        return vector<vector<int> >(ans.begin(), ans.end());
    }

    void dfs(set<vector<int> >& ans, vector<int>& cur, int index, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.insert(cur);
            return;
        } else if (target < 0) {
            return;
        } else {
            for (int i = index; i < candidates.size(); i++) {
                cur.push_back(candidates[i]);
                dfs(ans, cur, i+1, candidates, target - candidates[i]);
                cur.pop_back();
            }
        }
    }

};

int main() {
    Solution s;
    vector<int> candidates;
    candidates = { 2, 3, 6, 7 };
    vector<vector<int> > ans = s.combinationSum2(candidates, 5);
    for (vector<int> v1 : ans) {
        cout << "[ ";
        for (int i : v1) {
            cout << i << " "; 
        }
        cout << "]" << endl;
    } 
    return 0;
}