#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long low = 0, high = x, mid;
        if (x == 0) return 0;
        if (x ==1) return 1;
        while (low < high) {
            mid = low + (high - low) / 2;
            if ((mid * mid) == (long)x) {
                return mid;
            } else if ((mid * mid) < (long)x) {
                low = mid + 1;
            } else {
                high = mid; 
            }
        }
        return high -1;
    }
};

int main() {
    Solution s;
    int ans = s.mySqrt(8);
    cout << ans << endl;
    return 0;
}