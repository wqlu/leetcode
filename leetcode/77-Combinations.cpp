#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> cur;
        dfs(ans, cur, 1, n, k);
        return ans;
    }

    void dfs(vector<vector<int> >& ans, vector<int>& cur, int index, int n, int k) {
        if (k == 0) {
            ans.push_back(cur);
            return;
        } else {
            for (int i = index; i < n+1; i++) {
                cur.push_back(i);
                dfs(ans, cur, i+1, n, k-1);
                cur.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int> > ans = s.combine(4, 2);
    for (vector<int> v1 : ans) {
        cout << "[ ";
        for (int i : v1) {
            cout << i << " "; 
        }
        cout << "]" << endl;
    } 
    return 0;
}