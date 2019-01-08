//
// Email: wq.lu@outlook.com
//

#include <bits/stdc++.h>
using namespace std;

bool isSubString(string t, const string &s) {
    int t_sie = t.size(), s_sie = s.size();
    int dp[t_sie+1][s_sie+1];
    for (size_t i = 0; i < t_sie + 1; i++)
        dp[i][0] = 0;
    for (size_t j = 0; j < s_sie + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < t_sie + 1; i++) {
        for (int j = 1; j < s_sie + 1; j++) {
            if (t[i-1] == s[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    if (dp[t_sie][s_sie] == t_sie)
        return true;
    else
        return false;
}

int main() {
    string s, t;
    cin >> s >> t;
    bool ans = isSubString(t, s);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
