#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int> &errs, int s, int n) {
        int l = 0, r = 0;
        int sum = 0;
        int _max = 0;
        for (int i = 0; i < n; ++i) {
            sum += errs[i];
            if (sum > s) {
				sum -= err[l];
                l = l + 1;
            } else {
                _max = max(_max, i - l + 1);
            }
        }
        return _max;
    }
};


int main() {
    int n, s; cin >> n >> s;
    vector<int> errs(n);
    for (int i = 0; i < n; ++i) {
        cin >> errs[i];
    }

    Solution sol;
    int ans = sol.find(errs, s, n);
    cout << ans << endl;
    return 0;
}
