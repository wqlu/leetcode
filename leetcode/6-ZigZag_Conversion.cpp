class Solution {
public:
        string convert(string s, int numRows) {
        if (numRows == 1) return s;
        const int s_len = s.size();

        int index = 0;
        bool down = true;
        vector<string> ans(numRows, "");
        int y = 0;
        while (index < s_len) {
            if (down) {
                ans[y] += s[index];
                y++;
                if (y == numRows) {
                    down = false;
                    y -= 2;
                }
            } else {
                ans[y] += s[index];
                y--;
                if (y == -1) {
                    down = true;
                    y += 2;
                }
            }
            index++;
        }
        string res = "";
        for (auto & s : ans) {
            res += s;
        }
        return res;
    }

};