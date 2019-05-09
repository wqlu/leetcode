class Solution {
public:
   vector<int> twoSum(vector<int>& numbers, int target) {
        const int numbers_size = numbers.size();
        int low = 0, high = numbers_size - 1;
        vector<int> ans;
        while(low < high) {
            if (target == numbers[low] + numbers[high]) {
                break;
            } else if (target < numbers[low] + numbers[high]) {
                high--;
            } else {
                low++;
            }
        }
        ans.push_back(low + 1);
        ans.push_back(high + 1);
        return ans;
    }
};