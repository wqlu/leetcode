#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2) {
    return (s1+s2) < (s2+s1);
}

int main() {
    string test;
    getline(cin, test);
    vector<string> v;
    int l = 0, r = 0;
    for (int i = 0; i < test.length(); ++i) {
        if (test[i] == ',') {
            r = i - 1;
            v.push_back(test.substr(l, i - l));
            l = i + 1;
        } else {
            r = i;
        }
    }
    v.push_back(test.substr(l));
    sort(v.begin(), v.end(), cmp);
    string res = "";
    for (auto s : v) {
        res += s;
    }
    cout << res << endl;;
    return 0;
}

