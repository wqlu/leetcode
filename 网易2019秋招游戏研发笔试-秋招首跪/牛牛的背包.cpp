#include <bits/stdc++.h>
using namespace std;

int ans = 0;

class Solution {
public:
    void ways(vector<long long>&v, int n, long long curr_w, int index, long long w) {
        if (curr_w <= w) ans += 1;
        else return ;
        for (int i = index; i < n; ++i) {
            if (curr_w + v[i] > w)
                break;
            ways(v, n, curr_w + v[i], i + 1, w);
        }
    }
};

int main() {
    int n;
    long long w;
    cin >> n >> w;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    Solution solution;
    long long total = 0;
    for (auto iter : v) {
        total += iter;
    }
    if (total <= w) {
        ans = pow(2, n);
    } else {
        solution.ways(v, n, 0, 0, w);
    }
    // solution.ways(v, n, 0, 0, w);
    cout << ans << endl;
    return 0;
}
