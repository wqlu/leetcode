#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0, L = 0, R = 0;
    while (L < n) {
        if (L == R) ++R;
        while ((R < n) && a[R] - a[L] < k) ++R;
        ans += (R - L - 1);
        ++L;
    }
    cout << ans << endl;
    return 0;
}
