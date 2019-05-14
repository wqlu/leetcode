class Solution {
public:
    string convertToTitle(int n) {
        vector<int> ans;
        while (n) {
            if (n % 26 == 0) {
                ans.push_back(26);
                n = (n/26) - 1;
            } else {
                ans.push_back(n % 26);
                n /= 26;
            }
        }
        string s = "";
        int ans_size = ans.size();
        for (int i = ans_size - 1; i >= 0; --i) {
            s += ans[i] - 1+ 'A';
        }
        return s;
    }
};