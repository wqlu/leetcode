
/*
 * n个骰子，每个骰子出现等概率出现，例如
 * 2个骰子，（2，3）第一个骰子等概率出现[1,2],第二个[1,2,3],求最大值的期望
 * */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, temp; cin >> n;
    int m_max = 0; // 记录最大的数
    vector<int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        m_max = (m_max < temp) ? temp : m_max;
        cnt.push_back(temp);
    }

    vector<double> p(n);
    double q1 = 0.0, q2 = 0.0, res = 0.0;
    for (int k = 1; k <= m_max; ++k) {
        q1 = 1.0;
        for (int i = 0; i < n; ++i) {
            p[i] = (cnt[i] >= k) ? (1.0*k)/cnt[i] : 1.0;
            q1 *= p[i];
        }
        res += (q1 - q2) * k;
        q2 = q1;
    }
    printf("%.2f", res);
    return 0;
}
