#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        int R = 0, L = 0, n = s.length();
        map<char, int> m;
        int maxp = 0;

        while (R < n) {
            ++m[s[R]];
            while (m.size() > k) {
                --m[s[L]];
                if (m[s[L]] == 0)
                    m.erase(m.find(s[L])); // 删除值为0的元素
                ++L;
            }
            maxp = max(R-L+1, maxp);
            ++R;
        }
        return maxp;
    }
};

int main() {
    Solution s;
    string test = "eceba";
    int ans = s.lengthOfLongestSubstringKDistinct(test, 3);
    cout << ans << endl;
    return 0;
}
