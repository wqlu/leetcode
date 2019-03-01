#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> letter_index;
        for (int i = 0; i < S.size(); i++) {
            if ((S[i] >=  'a' && S[i] <= 'z') || (S[i] >=  'A' && S[i] <= 'Z')) {
                letter_index.push_back(i);
            }
        }
        if (letter_index.empty()) {
            return {S};
        } else {
            vector<string > ans;
            string cur = S;
            dfs(ans, cur, 0, letter_index);
            return ans;   
        }
    }

    void dfs(vector<string>& ans, string& cur, int index, vector<int>& letter_index) {
        ans.push_back(cur);
        for (int i = index; i < letter_index.size(); i++) {
            cur[letter_index[i]] = upperOrLower(cur[letter_index[i]]);
            dfs(ans, cur, i+1, letter_index);
            cur[letter_index[i]] = upperOrLower(cur[letter_index[i]]);
        }
    }

    char upperOrLower(char c) {
        if (c >= 'a' && c <= 'z') {
            return (c - 32);
        } else {
            return (c + 32);
        }
    }
};

int main() {
    Solution s;
    vector<string> ans  = s.letterCasePermutation("c");
    for (string s1 : ans) {
        cout << s1 << endl;
    }
    return 0;
}