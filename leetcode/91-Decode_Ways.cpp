#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecoding(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = (s[i] == '0') ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
private:
    bool isValid(const char c) { return c != '0'; }
    bool isValid(const char c1, const char c2) { 
        const int num = (c1 - '0')*10 + (c2 - '0');
        return num >= 10 && num <= 26;
    }
};

int main() {
    string test = "100";
    Solution s;
    int ans = s.numDecoding(test);
    return 0;
}
