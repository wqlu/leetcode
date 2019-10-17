#include <bits/stdc++.h>
using namespace std;

bool judge(char *s) {
    int len = 0;
    char *tmp = s;
    while (*tmp != '\0') {
        len++;
        tmp++;
    }
    int l = 0, r = len - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    char *s = "abcdba";
    bool ans = judge(s);
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
