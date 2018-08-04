#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int MaxLen[MAX][MAX];

// 最长公共子序列，动态规划求解
int maxLen(string s1, string s2) {
    int length1 = s1.length();
    int length2 = s2.length();
    for (int i = 0; i < length1; i++)
        MaxLen[i][0] = 0;
    for (int i = 0; i < length2; i++)
        MaxLen[0][i] = 0;

    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (s1[i-1] == s2[j-1]) {
                MaxLen[i][j] = MaxLen[i-1][j-1] + 1;
            } else {
                MaxLen[i][j] = max(MaxLen[i-1][j], MaxLen[i][j-1]);
            }
        }
    }
    return MaxLen[length1][length2];
}

int main() {
    string s;
    while (cin >> s) {
        int length = s.size();
        if (length == 1) {
            cout << 1 << endl;
            continue;
        } 
        // 利用回文的特点
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int max_length = maxLen(s, s2);
        cout << length - max_length << endl;
    }
    return 0;
}
