class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;
		const int m = matrix.size();
		const int n = matrix[0].size();

		// 首先确定在第几行
		if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
		int row_index = 0;
		for (int i = 0; i < m; ++i) {
			if (matrix[i][n - 1] >= target) {
				row_index = i;
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (matrix[row_index][i] == target)
				return true;
		}
		return false;
	}
};