#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.size(), t_len = t.size();
        if (s_len > t_len)
            return false;
        int idx = 0;
        for (int i = 0; i < t_len; ++i) {
            if (idx == s_len)
                return true;
            if (t[i] == s[idx]) {
                idx++;
            } else {
                continue;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
