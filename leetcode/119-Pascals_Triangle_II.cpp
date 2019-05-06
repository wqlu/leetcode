class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        for (int i = 0; i < rowIndex + 1; ++i) {
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
        return ans[rowIndex];
    }
};