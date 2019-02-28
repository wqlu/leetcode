#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> ans;
        const int A_size = A.size();
        for (int i = 0; i < A_size; ++i) {
            int temp = 1;
            for (int j = 0; j < A_size; j++) {
                if (j == i)
                    continue;
                else {
                    temp *= A[j];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};