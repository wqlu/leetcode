#include <bits/stdc++.h>
using namespace std;

int min_(int m, int n, int num) {
    int count = 0;
    for (int i = 1; i < m; ++i) {
        count += min(num/i, n);
    }
    return count;
}

int TwoSort(int m, int n, int k) {
    int l = 1, r = m*n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        int tmp = min_(m, n, mid);
        if (tmp < k) {
            l = mid + 1;
        } else {
            r = mid + 1;
        }
    }
    return l;
}

int main() {

    int n, m, k; 
    cin >> n >> m >> k;
    if (k == 1)
        cout << 1 << endl;
    if (k == m*n) 
        cout << n*m << endl;

    cout << TwoSort(m, n, k) << endl;
    return 0;
}
