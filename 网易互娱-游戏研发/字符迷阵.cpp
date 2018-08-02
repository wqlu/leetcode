//
// Created by lu on 18-8-2.
// Email: wq.lu@outlook.com
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int find_word(vector<string> &matrix, const string &target, const int &rows, const int &cols) {
        int ans = 0;
        size_t k;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target[0]) {
                    k = 1;
                    while ((j+k < cols) && (matrix[i][j+k] == target[k])) {
                        k++;
                        if (k == target.size()) {
                            ans++;
                            break;
                        }
                    }
                    k = 1;
                    while ((i+k < cols) && (matrix[i+k][j] == target[k])) {
                        k++;
                        if (k == target.size()) {
                            ans++;
                            break;
                        }
                    }
                    k = 1;
                    while ((i+k < rows) && (j+k < cols) && (matrix[i+k][j+k] == target[k])) {
                        k++;
                        if (k == target.size()) {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


int main() {

    int test_num;
    cin >> test_num;
    vector<int> ans;
    Solution solution;
    for (int i = 0; i < test_num; i++) {
        int rows, cols;
        cin >> rows >> cols;
        vector<string> matrix;
        for (int i = 0; i < rows; i++) {
            string row_i;
            cin >> row_i;
            matrix.push_back(row_i);
        }
        string target;
        cin >> target;
        ans.push_back(solution.find_word(matrix, target, rows, cols));
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
}
