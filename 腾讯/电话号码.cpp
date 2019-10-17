#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool find(int n, string &s) {
        if (n < 11) return false;
        bool count = false;
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] <= '9' && s[i] >= '0') {
                if (s[i] == '8') {
                   count = true;
                }
                if (count) {
                    num++;
                }
            }
        }
        if (num >= 8) {
            return true;
        }
        return false;
    }
};

int main() {
    int t; cin >> t;
    Solution solution;
    vector<bool> ans;
    for (int i = 0; i < t; ++i) {
        int n; cin >> n;
        string s; cin >> s;
        bool res = solution.find(n, s);
        ans.push_back(res);
    }
    for (auto iter : ans) {
        if (iter) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
