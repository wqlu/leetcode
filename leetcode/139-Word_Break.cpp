#include <iostream>
#include <vector>
#include <string>

using  namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (string &w : wordDict) {

            }
        }
        return false;
    }
};
