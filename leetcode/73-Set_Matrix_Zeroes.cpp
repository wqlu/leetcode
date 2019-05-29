class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> rows(m, 1);
        vector<int> clums(n, 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = 0;
                    clums[j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i] == 0 || clums[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};