#include <bits/stdc++.h>
using namespace std;

int dp[1001];

class Solution {
public:
    int find(int M, int N, vector<int> &W, vector<int> &V) {
        for (int i = 0; i <= M; ++i) dp[i] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = M; j >= W[i-1]; j--) {
                dp[j] = max(dp[j], dp[j - W[i-1]] + V[i-1]);
            }
        }
        return dp[M];
    }
};

int main() {
    int M; cin >> M;
    int N; cin >> N;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i) cin >> w[i];
    for (int i = 0; i < N; ++i) cin >> v[i];
    Solution s;
    int ans = s.find(M, N, w, v);
    cout << ans << endl;
    return 0;
}
