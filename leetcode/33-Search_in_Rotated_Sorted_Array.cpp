#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nums_size = nums.size();
        int low = 0, high  = nums_size- 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // mid 和 target在同一侧
            int num = (nums[mid] > nums[0]) == (target > nums[0]) ? nums[mid] : (nums[mid] > nums[0]) ? INT_MIN : INT_MAX;
            if (target > num) {
                low = low + 1;
            } else if (target < num) {
                high = high - 1;
            } else {
                return  mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    int ans = s.search(nums, 3);

    return 0;
}