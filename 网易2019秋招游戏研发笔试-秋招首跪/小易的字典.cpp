#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string ans = "";
    for (int i = 0; i < n; i++) ans += 'a';
    for (int j = 0; j < m; j++) ans += 'z';
    for (int i = 0; i < k; i++) {
        bool flag = false;
        for (int j = m+n-1; j >= 1; j--) {
            if (ans[j] == 'z' && ans[j-1] == 'a') {
                ans[j] = 'a';
                ans[j-1] = 'z';
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
