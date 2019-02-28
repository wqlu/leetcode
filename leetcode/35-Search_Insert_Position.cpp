#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int nums_size = nums.size();
        int ans = -1;
        for (int i = 0; i < nums_size; i++) {
            if (nums[i] >=  target) {
                ans = i;
                break;
            } else {
                continue;
            }
        }     
        if (ans == -1) {
            ans = nums_size;
        }   
        return ans;
    }
};