#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> find(vector<vector<int>> &matrix, int N, int M) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<int> ans;
        int up = 0, down = N - 1, left = 0, right = M -1;
        while (true) {
            for (int i = up; i <= down; ++i) {
                ans.push_back(matrix[i][left]);
            }
            if (++left > right) break;
            for (int j = left; j <= right; ++j) {
                ans.push_back(matrix[down][j]);
            }
            if (--down < up) break;
            for (int i = down; i >= up; --i) {
                ans.push_back(matrix[i][right]);
            }
            if (--right < left) break;
            for (int j = right; j >= left; --j) {
                ans.push_back(matrix[up][j]);
            }
            if (++up > down) break;
        }
        return ans;
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> pos(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> pos[i][j];
        }
    }
    Solution s;
    vector<int> ans = s.find(pos, N, M);
    for (int i = 0; i < ans.size() - 1; ++i) {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;
    return 0;
}
