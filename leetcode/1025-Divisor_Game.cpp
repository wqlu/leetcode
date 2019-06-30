#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N + 1, false);
        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j < i; ++i) {
                if (i % j == 0 && dp[i-j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
