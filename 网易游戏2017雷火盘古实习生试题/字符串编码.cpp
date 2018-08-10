#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, ans="";
    cin >> s;
    int count = 1;
    char c = s[0];
    if (1 == s.size()) {
        cout << to_string(1) + c << endl;
    }
    for (int i = 1; i < s.size(); i++) {
        if (c != s[i]) {
            ans += (to_string(count) + c);
            c = s[i];
            count = 1;
        } else {
            count++;
        }
        if (i == s.size() - 1) {
            ans += (to_string(count) + c);
        }
    }
    cout << ans << endl;
    return 0;
}
