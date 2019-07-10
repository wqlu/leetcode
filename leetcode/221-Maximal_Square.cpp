#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int rowSize = matrix.size();
        if (!rowSize) return 0;
        int colSize = matrix[0].size();
        if (!colSize) return 0;

        int square[rowSize+1][colSize+1];
        memset(square, 0, sizeof(int)*(rowSize+1)*(colSize+1));
        int maxWidth = 0;
        for (int r = 1; r <= rowSize; ++r) {
            for (int c = 1; c <= colSize; ++c) {
                if (matrix[r-1][c-1] == '1') {
                    square[r][c] = min(min(square[r-1][c], square[r][c-1]), square[r-1][c-1]+1);
                }
                maxWidth = max(maxWidth, square[r][c]);
            }
        }
        return maxWidth*maxWidth;
    }
};
