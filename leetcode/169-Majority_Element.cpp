class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, tmp = 0;
        for (const auto& iter : nums) {
            if (count == 0) {
                tmp = iter;
                count++;
            }else {
                if (iter == tmp)
                    count++;
                else
                    count--;
            }
        }
        return tmp;
    }
};