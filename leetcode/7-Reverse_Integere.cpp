//
// Created by lu on 19-1-17.
// Email: wq.lu@outlook.com
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        string s = to_string(x);
        int slen;
        if (s[0] == '-') {
            // negative number
            slen = s.length() - 1;
        } else {
            slen = s.length();
        }
        for (int i = 0; i < slen; ++i) {
            long tmp = x / (long(pow(10,slen -i - 1)));
            ans += tmp * (long(pow(10, i)));
            x = x % (long(pow(10,slen -i - 1)));
        }
        if (ans > INT32_MAX || ans < INT32_MIN) {
            ans = 0;
        }
        return ans;
    }
};

int main() {
    Solution s;
    int ans = s.reverse(1634236469);
    cout << ans << " " << endl;
    cout << INT32_MAX << " " << INT32_MIN << endl;
    return 0;
}
