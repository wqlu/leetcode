#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> cur;
        vector<int> candidates{1, 2, 3, 4, 5, 6, 7, 8, 9};
        dfs(ans, cur, 0, k, n, candidates);
        return ans;
    }

    void dfs(vector<vector<int> >& ans, 
            vector<int>& cur, 
            int index, int k, int n,
            vector<int>& candidates) {

        if (n == 0 && cur.size() == k) {
            ans.push_back(cur);
            return;
        } else if (n < 0) {
            return;
        } else {
            if (cur.size() < k) {
                for (int i = index; i < candidates.size(); i++) {
                    cur.push_back(candidates[i]);
                    dfs(ans, cur, i + 1, k, n - candidates[i], candidates);
                    cur.pop_back();
                }
            
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates;
    vector<vector<int> > ans = s.combinationSum3(3, 9);
    for (vector<int> v1 : ans) {
        cout << "[ ";
        for (int i : v1) {
            cout << i << " "; 
        }
        cout << "]" << endl;
    } 
    return 0;
}