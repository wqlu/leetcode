#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> ans;
    string temp;
    while (cin >> temp) {
        ans.insert(temp);
    }
    cout << ans.size() << endl;
    return 0;
}
