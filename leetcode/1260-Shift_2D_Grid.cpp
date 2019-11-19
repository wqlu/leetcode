#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                v.push_back(grid[i][j]);
            }
        }
        for (int i = 0; i < k; ++i) {
            int t = v[v.size()-1];
            v.erase(v.begin() + v.size() - 1);
            v.insert(v.begin(), t);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = v[i * n + j];
            }
        }
        return grid;
    }
};
