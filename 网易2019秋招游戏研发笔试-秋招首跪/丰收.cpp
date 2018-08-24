//
// Email: wq.lu@outlook.com
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, t;
ll a[100005];
ll q;

int main() {
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        a[i] = a[i-1] + t;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> q;
        int loc = lower_bound(a+1, a+n+1, q) - a;
        cout << loc << endl;
    }
    return 0;
}