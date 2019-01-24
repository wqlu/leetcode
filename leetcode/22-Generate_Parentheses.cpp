class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generateString(ans, s, n, n);
        return ans;
    }

    void generateString(vector<string>& ans, string s, int left, int right) {
        if (left < 0 || right < 0) {
            return;
        }

        if (left == 0 && right == 0) {
            ans.push_back(s);
        }

        if (left <= right) {
            if (left == right) {
                generateString(ans, s+"(", left - 1, right);
            }else {
                if (left > 0) {
                    generateString(ans, s+"(", left - 1, right);
                }

                if (right > 0) {
                    generateString(ans, s+")", left, right - 1);
                }
            }
        }
    }
};