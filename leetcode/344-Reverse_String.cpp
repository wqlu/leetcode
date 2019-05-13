class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 0 || s.size() == 1) return;
        size_t s_size = s.size();
        for (int i = 0; i < s_size / 2; ++i) {
            char temp = s[i];
            s[i] = s[s_size - i - 1];
            s[s_size - 1 - i] = temp;
        }
        return;
    }
};