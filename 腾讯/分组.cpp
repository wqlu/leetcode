#include <bits/stdc++.h>
using namespace std;

vector<int> diff(vector<int> &vec, int n) {
    int sum1 = vec[n-1], sum2 = vec[n-2];
    int num1 = 1, num2 = 1;
    for (int i = n - 3; i >= 0; ++i) {
        if (num1 == num2) {
            if (sum1 > sum2) {
                sum2 += vec[i];
                num2++;
            } else {
                sum1 += vec[i];
                num1++;
            }
        } else {
            if (num1 > num2) {
                sum2 += vec[i];
                num2++;
            } else {
                sum1 += vec[i];
                num1++;
            }
        }
    }
    vector<int> dis;
    int min_ = sum1 > sum2 ? sum2 : sum1;
    int max_ = sum1 > sum2 ? sum1 : sum2;
    dis.push_back(min_);
    dis.push_back(max_)
    return dis;
}

int main() {
    int T; cin >> T;
    vector<vector<int>> ans;
    for (int i = 0; i < T; ++i) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int j = 0; j < n; ++j) {
            cin >> vec[i];
        }
        vector<int> tmp = diff(vec, n);
        ans.push_back(tmp);
    }
    for (auto v : ans) {
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}
