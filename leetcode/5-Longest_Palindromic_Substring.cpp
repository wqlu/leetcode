//
// Created by lu on 19-1-17.
// Email: wq.lu@outlook.com
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        const int slen = s.length();
        if (s.empty() || s.length() == 1) {
            return s;
        }
        bool dp[slen][slen] = {false};
        // initialize dp
        for (int i = 0; i < slen; i++) {
            dp[i][i] =  true;
            if (i < slen - 1) {
                dp[i][i+1] = (s[i+1] == s[i]);
            }
        }

        // fill dp, from back to front, so i = slen -3
        for (int i = slen -3 ; i >= 0 ; --i) {
            for (int j = i + 2; j < slen; ++j) {
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }

        int max_len = 1;
        for (int i = 0; i < slen; i++) {
            for (int j = i ; j < slen; j++) {
                if (dp[i][j] && (j - i + 1) >= max_len) {
                    max_len = j - i + 1;
                    ans = s.substr(i, max_len);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string s1 = "ab";
    cout << s1.length() << endl;
    string test = s.longestPalindrome(s1);
    cout << test << endl;
    return 0;
}
