class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        int res = 0, cnt = 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        unordered_set<int> s; // 二维变成一维
        for (auto mine : mines) s.insert(mine[0] * N + mine[1]);
        for (int j = 0; j < N; ++j) {
            cnt = 0;
            for (int i = 0; i < N; ++i) { // up
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = cnt;
            }
            cnt = 0;
            for (int i = N - 1; i >= 0; --i) { // down
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
            }
        }
        for (int i = 0; i < N; ++i) {
            cnt = 0;
            for (int j = 0; j < N; ++j) { // left
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
            }
            cnt = 0;
            for (int j = N - 1; j >= 0; --j) { // right
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
                res = max(dp[i][j], res);
            }
        }
        return res;
    }
};