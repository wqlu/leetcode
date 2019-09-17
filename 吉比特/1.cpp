#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2; cin >> s1 >> s2;
    int s1_len = s1.length();
    int s2_len = s2.length();
    if (s1_len < s2_len) { 
        cout << 0 << endl;
    } else {
        int p = s1_len-1;
        for (int i = s2_len-1; i >= 0; --i) {
            bool flag = false;
            for (int j = p; j >= 0; --j) {
                if (s2[i] == s1[j]) {
                    flag = true;
                    p = j - 1;
                    break;
                } else {
                    continue;
                }
            }
            if (!flag) {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << p + 2<< endl;
    }
    return 0;
}

