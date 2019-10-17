#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    set<int> set_1;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        set_1.insert(temp);
    }
    vector<int> vector_1;
    for (auto iter : set_1) {
        vector_1.push_back(iter);
    }
    vector<int> ans;
    ans.push_back(vector_1[0]);
    int count = 1;
    for (int i = 1; i < vector_1.size(); ++i) {
        ans.push_back(vector_1[i]-vector_1[i-1]);
        count++;
        if (count == k) {
            break;
        }
    }
    int ans_size = ans.size();
    for (int i = 0; i < k - ans_size; ++i) {
        ans.push_back(0);
    }
    for (auto iter : ans) {
        cout << iter << endl;
    }
    return 0;
}
