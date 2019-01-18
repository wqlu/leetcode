class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        bool ans;
        const int slen = s.size();
        if (s[0] == '-') {
            return false;
        } else {
            ans = true;
            for (int i = 0; i < slen / 2; i++) {
                if (s[i] == s[slen-1-i])
                    continue;
                else {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};