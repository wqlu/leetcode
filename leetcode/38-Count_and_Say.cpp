#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
        string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            ans = say(ans);
        }
        return ans;
    }
private:
    string say(const string& n) {
        string ans;
        int s = 0, len = n.length();
        for (int e = 1; e <= len; ++e) {
            if (e == len || n[s] != n[e]) {
                int count = e - s;
                ans += to_string(count);
                ans += n[s];
                s = e;
            }
        }
        return ans;
    }
};