class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; ++i) {
            if (i == 0) {
                ans.push_back({ 1 });
                continue;
            }
            if (i == 1) {
                ans.push_back({ 1, 1 });
                continue;
            }
            vector<int> tmp(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                tmp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};