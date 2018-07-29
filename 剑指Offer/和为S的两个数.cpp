#include <iostream>
#include <vector>
using namespace std;

/**
 * 不用考虑乘积最小，最外侧的就是最小的
 */
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> ans;
        int low = 0;
        int high = array.size() - 1;
        while (high > low) {
            if (sum == array[low] + array[high]) {
                ans.push_back(array[low]);
                ans.push_back(array[high]);
                low ++;
                high --;
            } else if (sum > array[low] + array[high]) {
                low ++;
            } else {
                high --;
            }
        }
        return ans;
    }
};

int main() {
    
    Solution solution;
    vector<int> vect;
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);
    vect.push_back(6);
    vect.push_back(7);
    vector<int> ans = solution.FindNumbersWithSum(vect, 9);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
