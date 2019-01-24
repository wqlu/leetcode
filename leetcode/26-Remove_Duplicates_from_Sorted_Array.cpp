#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        int pre = nums[0];
        vector<int>::iterator it = nums.begin();
        it ++;
        for (; it != nums.end();) {
            int tmp = *it;
            if (tmp == pre) {
                it = nums.erase(it);
            } else {
                it++;
                pre = tmp;
            }
        }
        return nums.size();
    }
};