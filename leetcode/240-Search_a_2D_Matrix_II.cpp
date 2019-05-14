class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
        int i = 0, j = cols - 1;
        
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else 
                j--;
        }
        return false;
    }
};