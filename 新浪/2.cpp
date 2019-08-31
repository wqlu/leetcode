#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= n; ++j) {
            int max_ = 0;
            for (int t = 1; t <= k; t++) {
                if (j - t >= 0) {
                    max_ = max(dp[i-1][j-t], max_);
                }
            }
            dp[i][j] = max_ + a[j-1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[m][i]);
    }
    cout << ans << endl;
    return 0;
}


