#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int far = nums[0];
        for (int i = 0; i < n; i++) {
            if (i > far) break;
            far = max(far, i + nums[i]);
        }
        return far >= (n-1);
    }
};
