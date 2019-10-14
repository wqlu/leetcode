#include <bits/stdc++.h>
using namespace std;

void LCS(string &s1, string &s2) {
    int len_1 = s1.length(), len_2 = s2.length();
    vector<vector<int>> dp(len_2+1, vector<int>(len_1+1, 0));
    for (int i = 0; i < len_2; ++i) {
        for (int j = 0; j < len_1; ++j) {
            if (s2[i] ==  s1[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    for (auto iter_v : dp) {
        for (auto iter_int : iter_v) {
            cout << iter_int << " ";
        }
        cout << endl;
    }
}

int main() {
    string s1 = "ABCPDSFJGODIHJOFDIUSHGD";
    string s2 = "OSDIHGKODGHBLKSJBHKAGHI";
    LCS(s1, s2);
    return 0;
}
