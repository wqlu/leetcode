#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    double ans, count = 1;
    char c = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (c != s[i]) {
            count++;
            c = s[i];
        }
    }
    ans = (double) (s.size() / count);
    printf("%.2lf",ans); 
    return 0;
}
