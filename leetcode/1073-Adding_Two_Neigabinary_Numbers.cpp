#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
        int arr1_idx = arr1.size() - 1, arr2_idx = arr2.size() - 1;
        vector<int> ans;
        int flag = 0;
        while (arr1_idx >= 0 || arr2_idx >= 0) {
            char i = (arr1_idx >= 0) ? arr1[arr1_idx--] : 0;
            char j = (arr2_idx >= 0) ? arr2[arr2_idx--] : 0;
            char t = i + j + flag;
            flag = t >> 1;
            ans.push_back(t & 0x01);
        }
        if (flag == 1) ans.push_back(1);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = {1,1,1,1,1};
    vector<int> arr2 = {1,0,1};
    vector<int> ans = s.addNegabinary(arr1, arr2);
    return 0;
}
