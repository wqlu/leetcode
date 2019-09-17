#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int S[n];
    vector<vector<int>> D(n+1, vector<int>(n+1, 0));
    int sum = 0;
    int Dtemp;
    int flag;
    int i = 1, k, l, j;
    S[0] = 0;
    for (int i = 0; i < m; i++) {
        int k, t, d; cin >> k >> t >> d;
        D[k][t] = d;
    }
    do {
        k = 1;Dtemp = 10000;
        do {
            l = 0; flag = 0;
            do {
                if (S[l] == k) {
                    flag = 1;
                    break;
                } else 
                    l++;
            } while (l < i);
            if (flag == 0 && D[k][S[i-1]] < Dtemp) {
                j = k;
                Dtemp = D[k][S[i-1]];
            }
            k++;
        } while (k < n);
        S[i] = j;
        i++;
        sum += Dtemp;
    } while (i < n);
    sum += D[0][j];
    cout << sum << endl;
    return 0;
}
