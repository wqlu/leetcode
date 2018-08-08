#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n,m;
    cin >> n;
    vector<int> h;
    for (int i = 0; i < n; i++) {
        int stu;
        cin >> stu;
        h.push_back(stu);
    }
    cin >> m;
    vector<int> w;
    for (int i = 0; i < m; i++) {
        int chac;
        cin >> chac;
        w.push_back(chac);
    }
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());

    int ans = 0;
    for (int i = n - 1; i >=0; i--) {
        if (h[i] <= w[w.size()-1]) {
            ans++;
            w.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}
