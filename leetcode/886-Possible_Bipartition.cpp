class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        g_ = vector<vector<int>>(N);
        for (const auto &d : dislikes) {
            g_[d[0] - 1].push_back(d[1] - 1);
            g_[d[1] - 1].push_back(d[0] - 1);
        }
        colors_ = vector<int>(N, 0); // 0 unknown, 1 blue, -1 red
        for (int i = 0; i < N; ++i) {
            if (colors_[i] == 0 && !dfs(i, 1)) return false;
        }
        return true;
    }

private:
    vector<vector<int>> g_;
    vector<int> colors_;
    bool dfs(int cur, int color) {
        colors_[cur] = color;
        for (const int &next : g_[cur]) {
            if (colors_[next] == color) return false;
            if (colors_[next] == 0 && !dfs(next, -color)) return false;
        }
        return true;
    }
};