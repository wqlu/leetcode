#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, sum = 0, sum2 = 0;
    cin >> n >> k;
    int a[n], t[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i]  == 1 ) {
            sum += a[i];
        }
    }

    int cur = 0;
    k = min(k, n);

    for (int i = 0; i < k; ++i) {
        if (t[i] == 0)
            cur += a[i];
    }
    sum2 = cur;

    for (int i = k; i < n; i++) {
        if (t[i-k] == 0) 
            cur -= a[i-k];
        if (t[i] == 0)
            cur += a[i];
        if (cur > sum2)
            sum2 = cur;
    }

    cout << sum + sum2 << endl;
    return 0;
}
