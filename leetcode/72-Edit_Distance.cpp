class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_len = word1.length();
        int word2_len = word2.length();

        vector<vector<int>> dp(word1_len + 1, vector<int>(word2_len + 1, 0));
        
        for (int i = 0; i <= word1_len; ++i) {
            for (int j = 0; j <= word2_len; ++j) {
                if (i == 0) {
                    dp[i][j] == j;
                }
                else if (j == 0) {
                    dp[i][j] == i;
                }
                else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                }
            }
        }

        return dp[word1_len][word2_len];
    }
};