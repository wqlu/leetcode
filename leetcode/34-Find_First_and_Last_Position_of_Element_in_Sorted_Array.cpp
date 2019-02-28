#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int nums_size = nums.size();
        int low = 0, high = nums_size;
        vector<int> ans = binSearch(nums, low, high, target);
        return ans;
    }

    vector<int> binSearch(vector<int>& nums, int low, int high, int target) {
        int leftIndex = -1, rightIndex = -1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                leftIndex = mid;
                rightIndex = mid;
                vector<int> left = binSearch(nums, low, mid, target);
                vector<int> right = binSearch(nums, mid + 1, high, target);
                if (left[0] != -1) {
                    leftIndex = left[0];
                }
                if (right[0] != -1) {
                    rightIndex = right[1];
                }
                return {leftIndex, rightIndex};
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
            
        }
        return {-1, -1};
    }
};