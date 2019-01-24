#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = true;
        if (nums.size() <= 1) return;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i+1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            
        } else {
            sort(nums.end(), nums.end());
        }
    }
};