#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWin(string &s) {
        vector<bool> state(s.length());
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '+') {
                state[i] = true;
            } else {
                state[i] = false;
            }
        }
        return search(state);
    }

    bool search(vector<bool> &state) {
        for (int i = 0; i < state.size(); ++i) {
            if (state[i] && state[i+1]) {
                state[i] = false;
                state[i+1] = false;
                if (!search(state)) {
                    state[i] = true;
                    state[i+1] = true;
                    return true;
                } else {
                    state[i] = true;
                    state[i+1] = false;
                }
            }
        }
        return false;
    }
};

int main() {
    string s = "-+++-";
    Solution solution;
    bool ans = solution.canWin(s);
    if (ans) cout << "win" << endl;
    else cout << "lose" << endl;
    return 0;
}
