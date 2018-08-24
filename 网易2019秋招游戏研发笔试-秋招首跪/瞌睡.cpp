#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, sum = 0;
    cin >> n >> k;
    int a[n], t[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (a[i]  == 1 ) {
            sum += a[i];
        }
    }
    int ans = sum;
    for (int i = 0; i <= n - k; i++) {
        for (int k= 0; k < 3; k++ ) {
            if (t[i+k] == 0) {
                ans += a[i+k];
            }
        }
        ans = ans > sum ? ans : sum;
    }
    cout << ans << endl;
    return 0;
}
