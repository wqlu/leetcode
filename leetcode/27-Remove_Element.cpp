#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end();) {
            if (*it == val) {
                it = nums.erase(it);
            } else {
                it++;
            }
        }
        return nums.size();
    }

    int removeElement2(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};