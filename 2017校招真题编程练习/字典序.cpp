// 内存空间超过限制了,使用字典树来解决
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, j;
    set<string> ans;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++) {
        ans.insert(to_string(i));
    }
    set<string>::iterator it;
    for (it = ans.begin(), j = 1; it != ans.end(); it++, j++) {
        if (j == m) {
            cout << (*it) << endl;
            break;
        }
    }
    return 0;
}
