#include <bits/stdc++.h>
using namespace std;

inline double expect(double a, int b) {
    double res = 1, t = a;
    while (b) {
        if (b & 1) {
            res = res * t;
        }
        t = t*t;
        b >>= 1;
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int max_ = *max_element(a.begin(), a.end());
    double ans = 0;
    for (int i = 1; i <= max_; ++i) {
        int n1 = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] >= i) {
                n1++;
            }
        }
        ans += (expect(1.0*i/))*i;
    }
    printf("%.2f", ans);
    return 0;
}
