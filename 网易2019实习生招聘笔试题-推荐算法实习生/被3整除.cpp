#include <bits/stdc++.h>
using namespace std;

int main() {
    long long start_n, end_n;
    cin >> start_n >> end_n;
    long long count = 0, sum = 0;
    for (int i = 0; i < end_n + 1; i++) {
        sum += 1;
        if (i >= start_n && sum % 3 == 0) {
            count++;
        }
    }
    cout << 0;
    return 0;
}
